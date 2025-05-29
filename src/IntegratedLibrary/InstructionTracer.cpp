//
// Created by holaphei on 27/05/25.
//



#include "etiss/IntegratedLibrary/InstructionTracer.h"
#include "etiss/ETISS.h"
#include "etiss/IntegratedLibrary/InMemoryTracerBuffer.h"

#include "../../ArchImpl/RV32IMACFD/RV32IMACFD.h"
#include "etiss/CPUArch.h"

#include <fstream>
#include <mutex>
#include <unordered_set>

using namespace etiss::plugin;
using namespace etiss::instr;


// Initialize and populate the set of instructions
std::unordered_set<std::string> instructions_to_snapshot = {"cjr"};


InstructionTracer::InstructionTracer(const std::string &snapshot_content,
                     const std::string &output_path)
    : output_path_(output_path),
      snapshot_content_(snapshot_content)

{

}

/*
 * In destructor, we call the writeToDisk function to
 * write buffer information to disk
 *
 */
InstructionTracer::~InstructionTracer()
{
    /* make sure we never throw from a destructor */
    try { writeToDisk(); }
    catch (const std::exception &e)
    {
        std::cerr << "InstructionTracer: Write to disk failed - " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "InstructionTracer: Write to disk failed - unknown exception" << std::endl;
    }
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
                        ss << "InstructionTracer_collect_state((RV32IMACFD*) cpu);\n";
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
    block.fileglobalCode().insert("extern void InstructionTracer_collect_state(RV32IMACFD*);");
};


void InstructionTracer::writeToDisk()
{
    std::lock_guard<std::mutex> guard(mutex_);

    if (output_path_.empty())
        return;   // silently ignore if no file requested

    std::ofstream out(output_path_, std::ios::out | std::ios::trunc);
    if (!out)
    {
        etiss::log(etiss::ERROR,
                   "InstructionTracer: cannot open output file '" + output_path_ + '\'');
        return;
    }

    out << InMemoryTracerBuffer::instance().str();
    out.flush();
}



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

    void InstructionTracer_collect_state(RV32IMACFD* cpu)
    {

        const etiss_uint32 pc = static_cast<etiss_uint32>(reinterpret_cast<ETISS_CPU *>(cpu)->instructionPointer);

        etiss_uint32 x[32];
        for (int i = 0; i < 32; ++i)
            x[i] = *cpu->X[i];

        etiss_uint64 f[32];
        for (int i = 0; i < 32; ++i)
            f[i] = cpu->F[i];

        std::ostringstream entry;
        entry << "{\"pc\": " << pc << ", \"x\": [";

        // X registers
        for (int i = 0; i < 32; ++i)
        {
            if (i != 0) entry << ", ";
            entry << x[i];
        }

        entry << "], \"f\": [";

        // F registers
        for (int i = 0; i < 32; ++i)
        {
            if (i != 0) entry << ", ";
            entry << f[i];
        }

        entry << "]}\n";

        // Append to global static buffer
        {
            InMemoryTracerBuffer_append_entry(entry.str().c_str());
        }
    }

}