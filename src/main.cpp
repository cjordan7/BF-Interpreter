//
//  bf.hpp
//  BFInterpreter
//
//  Copyright © 2020 Cosme Jordan. All rights reserved.
//

#include <iostream>
#include "bf.hpp"

int main(int argc, const char * argv[]) {
    // It can only works if we have a file
    if(argc < 2) {
        std::cerr << "Wrong input" << std::endl;
        std::cerr << "Example of use: ./bfInterpreter sample.bf" << std::endl;
        return 1;
    }

    // Initialize a bf
    BF bf;

    // Interpret the argument file
    bf.interpret(argv[1]);
    
    return 0;
}
