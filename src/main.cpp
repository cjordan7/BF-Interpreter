//
//  bf.hpp
//  BFInterpreter
//
//  Copyright © 2020 Cosme Jordan. All rights reserved.
//

#include <iostream>
#include "bf.hpp"

int main(int argc, const char * argv[]) {
    if(argc < 2) {
        std::cerr << "Wrong input" << std::endl;
        std::cerr << "Example of use: ./bfInterpreter sample.bf" << std::endl;
        return 1;
    }
    
    BF bf;
    bf.interpret(argv[1]);
    
    return 0;
}
