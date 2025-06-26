//
// Created by holaphei on 27/05/25.
//



#include "etiss/IntegratedLibrary/InstructionTracer.h"
#include "etiss/ETISS.h"
#include "etiss/IntegratedLibrary/TraceFileWriter.h"

#include "../../ArchImpl/RV32IMACFD/RV32IMACFD.h"
#include "etiss/CPUArch.h"

#include <fstream>
#include <mutex>
#include <unordered_set>

#include <sstream>
#include <string>
#include <iostream>
#include <iomanip>

using namespace etiss::plugin;
using namespace etiss::instr;


// Initialize and populate the set of instructions
std::unordered_set<std::string> instructions_to_snapshot = {"cjr", "cswsp"};


etiss_uint32 low_pc = 0;
etiss_uint32 high_pc = 0;

InstructionTracer::InstructionTracer()

{

    /*
     * The python pipeline will write low_pc and high_pc in a file pcs.tmp with ; as delimiter
     *
     * TODO:
     *      in future this should be replaced with a more mature implementation
     */
    std::ifstream pcs_file("pcs.tmp");
    if (!pcs_file.is_open()) {
        etiss::log(etiss::ERROR, "Failed to read PC-range from pcs.tmp. Tracing will not be activated");
        return;
    }

    std::string line;
    if (std::getline(pcs_file, line)) {
        std::stringstream ss(line);
        std::string token;

        if (std::getline(ss, token, ';')) {
            low_pc = static_cast<etiss_uint32>(std::stoul(token, nullptr, 10));
        }

        if (std::getline(ss, token, ';')) {
            high_pc = static_cast<etiss_uint32>(std::stoul(token, nullptr, 10));
        }

        etiss::log(etiss::INFO, "Loaded PC range: low=" + std::to_string(low_pc) +
                                 ", high=" + std::to_string(high_pc));
    }
    else {
        etiss::log(etiss::WARNING, "pcs.tmp is empty or unreadable");
    }

    pcs_file.close();

}



/*
 * This is the method that runs at runtime when your instruction executes
 * TODO: this might not be needed any more
 */
bool InstructionTracer::callback()
{
    std::lock_guard<std::mutex> guard(mutex_);

    /* keep simulation running */
    return false;
}

/* This is the method that runs during instruction decoding/translation */
bool InstructionTracer::callbackOnInstruction(etiss::instr::Instruction &instr) const
{
    /* attach this tracer only to the ‘cjr’ instruction */
    // TODO: Is this still needed?
    return instr.name_ == "cjr";
}

/*
 * This function is based on the PrintInstruction plugin implementation. In this early
 * form this plugin works just with RV32IMACFD architecture with hard coded values. Here
 * we generate statements for the C code blocks to declare and initialize variables and then
 * to call the appropriate function from the ones defined in extern "C" blocks. Please also
 * see initCodeBlock in which the functions are included to the code block as extern functions.
 *
 */
void InstructionTracer::finalizeInstrSet(etiss::instr::ModedInstructionSet &mis ) const
{
    mis.foreach ([](etiss::instr::VariableInstructionSet &vis) {
        vis.foreach ([](etiss::instr::InstructionSet &set) {
            set.foreach ([](etiss::instr::Instruction &instr) {
                if (instructions_to_snapshot.find(instr.name_) != instructions_to_snapshot.end())
                {
                    instr.addCallback(
                    [&instr](etiss::instr::BitArray &ba, etiss::CodeSet &cs, etiss::instr::InstructionContext &ic) {
                        std::stringstream ss;
                        ss << "// InstructionTracer: call function to collect state information;\n";
                        /*
                         * TODO: The cast is now hardcoded. Would be nice if
                         * it could be passed from configuration or as an argument
                         */
                        ss << "InstructionTracer_collect_state((RV32IMACFD*) cpu, \"" << instr.name_ << "\");\n";
                        cs.append(etiss::CodePart::PREINITIALDEBUGRETURNING).code() = ss.str();

                        return true;
                    },
                    0);
                }

            });
        });
    });
};


/*
 * Add defined functions as extern functions to each code block
 */
void InstructionTracer::initCodeBlock(etiss::CodeBlock &block ) const
{
    block.fileglobalCode().insert("extern void InstructionTracer_collect_state(RV32IMACFD*, const char*);");
};



/*
 * functions that are brought in to C code blocks as extern functions. At their current state
 * they simply output different types of data to console.
 *
 */
extern "C"
{

    /**
     * @brief Collects and handles the current CPU state for ISA extension validation.
     *
     * This function extracts the instruction pointer (PC), general-purpose registers (X),
     * and floating-point registers (F) from the given RV32IMACFD CPU state and stores it
     * in a JSON-format to an in-memory buffer.
     *
     * The state information is intended to be used for verification purposes.
     *
     * @param cpu Pointer to the RV32IMACFD CPU instance whose state should be collected.
     */

    void InstructionTracer_collect_state(RV32IMACFD* cpu, const char *instruction)
    {
        const etiss_uint32 pc = static_cast<etiss_uint32>(reinterpret_cast<ETISS_CPU *>(cpu)->instructionPointer);
        auto& writer = TraceFileWriter::instance();

        if (std::string(instruction) == "cswsp" && (low_pc <= pc && pc <= high_pc)) {
            writer.activateTrace();
        }

        if (writer.isTracing()) {
            StateSnapshotEntry entry{};
            entry.type = 1;
            entry.pc = pc;
            entry.sp = cpu->SP;
            strncpy(entry.instruction, instruction, sizeof(entry.instruction) - 1);

            for (int i = 0; i < 32; ++i)
                entry.x[i] = *cpu->X[i];

            for (int i = 0; i < 32; ++i)
                entry.f[i] = cpu->F[i];

            writer.writeStateSnapshot(entry);
        }

        if (std::string(instruction) == "cjr" && (low_pc <= pc && pc <= high_pc)) {
            writer.deactivateTrace();
        }
    }



}