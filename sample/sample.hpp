#ifndef _CPP_KERNEL_HEADER_TEST
#define _CPP_KERNEL_HEADER_TEST

#include <iostream>

#include "res/linker.hpp"

extern "C" {
    #include "res/legacy.h"
}

namespace _CPP_KERNEL_HEADER_TEST {
    void TestHeaderMode() {
        std::cout << "External headers are working properly." << std::endl;

        #ifdef _CPP_KERNEL_HEADER_TEST_legacy
            printf("C Header Legacy is working as expected.");
        #else
            printf("C Header Legacy is NOT working as expected.");
        #endif
    
        #ifdef _CPP_KERNEL_HEADER_TEST_linker
            std::cout << "C++ Linker is working as expected." << std::endl;
        #else
            std::cout << "C Linker is NOT working as expected." << std::endl;
        #endif
    }
}

#endif