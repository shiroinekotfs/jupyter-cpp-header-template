#ifndef cppjupytertestheader
#define cppjupytertestheader

#include <iostream>

#include "res/linker.hpp"

extern "C" {
    #include "res/legacy.h"
}

namespace cppjupytertestheader {
    void TestHeaderMode() {
        std::cout << "External headers are working properly." << std::endl;

        #ifdef cppjupytertestheader_legacy
            printf("C Header Legacy is working as expected.");
        #else
            printf("C Header Legacy is NOT working as expected.");
        #endif
    
        #ifdef cppjupytertestheader_linker
            std::cout << "C++ Linker is working as expected." << std::endl;
        #else
            std::cout << "C Linker is NOT working as expected." << std::endl;
        #endif
    }
}

#endif