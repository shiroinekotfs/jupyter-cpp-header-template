#ifndef _CPP_KERNEL_HEADER_TEST
#define _CPP_KERNEL_HEADER_TEST

#include <iostream>

#include "res/linker.hpp"

extern "C" {
    #include "res/legacy.h"
}

namespace _CPP_KERNEL_HEADER_TEST {
    void TestHeaderMode() {
        std::cout << "External headers are working properly.\n\n" << std::endl;

        #ifdef _CPP_KERNEL_HEADER_TEST_legacy
            printf("C Header Legacy is working as expected.\n\n");
        #else
            printf("C Header Legacy is NOT working as expected.\n\n");
        #endif
    
        #ifdef _CPP_KERNEL_HEADER_TEST_linker
            std::cout << "C++ Linker is working as expected.\n\n" << std::endl;
        #else
            std::cout << "C Linker is NOT working as expected.\n\n" << std::endl;
        #endif
    }
}

#endif