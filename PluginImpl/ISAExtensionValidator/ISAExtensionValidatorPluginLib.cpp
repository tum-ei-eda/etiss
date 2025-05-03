//
// Created by holaphei on 03/05/25.
//
// define a name for this library. this will be used to avoid name clashes with other libraries. in this example the library is named "ISAExtensionValidatorPluginLib".
// IMPORTANT this name MUST match the library name: e.g. ISAExtensionValidatorPluginLib -> libISAExtensionValidatorPluginLib.so
#define ETISS_LIBNAME ISAExtensionValidatorPluginLib
        
#include "etiss/helper/PluginLibrary.h" // defines the following functions
        
 
        
#include "ISAExtensionValidator.h" // include your plugin implementation header files
                        
extern "C"{
        
    unsigned ISAExtensionValidatorPluginLib_etissversion(){
        // TODO: Figure this out
        // return ETISS_LIBRARYIF_VERSION;
        return 0;
    }
        
    unsigned ISAExtensionValidatorPluginLib_countPlugin(){
        //TODO
        return 1; // number of plugins provided
    }
    const char * ISAExtensionValidatorPluginLib_namePlugin(unsigned index){
        //TODO
        switch (index){
        case 0:
            return "ISAExtensionValidatorPluginLib";
        default:
            return "";
        }
    }
    etiss::Plugin* ISAExtensionValidatorPluginLib_createPlugin(unsigned index,std::map<std::string,std::string> options){
        //TODO
        switch (index){
        case 0:
            // parse arguments?
            return new ISAExtensionValidator();
        default:
            return 0;
        }
    }
    void ISAExtensionValidatorPluginLib_deletePlugin(etiss::Plugin* arch){
        delete arch;
    }
        
}