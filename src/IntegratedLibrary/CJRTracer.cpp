//
// Created by holaphei on 27/05/25.
//



#include "etiss/IntegratedLibrary/CJRTracer.h"
#include "etiss/ETISS.h"
#include <iostream>


int counter = 0;


CJRTracer::CJRTracer() {}

/* This is the method that runs at runtime when your instruction executes */
bool CJRTracer::callback()
{
    counter++;
    std::cout << "CJR execution count: " << counter << std::endl;
    return false; // Don't stop execution
}

/* This is the method that runs during instruction decoding/translation */
bool CJRTracer::callbackOnInstruction(etiss::instr::Instruction &i) const
{
    return i.name_ == "cjr"; // Match the instruction by name
}
