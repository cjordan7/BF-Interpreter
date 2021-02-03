//
//  bf.cpp
//  BFInterpreter
//
//  Copyright © 2020 Cosme Jordan. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stack>
#include "bf.hpp"

//#define MEMORY_SIZE 100000
#define ERROR_DOES_NOT_MATCH "Error: '[' does not match ']'"

std::size_t BF::MEMORY_SIZE = 30000;

BF::BF() {
    // Instantiate the memory with size MEMORY_SIZE
    // where all the elements are equal to zero
    memory.resize(MEMORY_SIZE, 0);
}

// A function used to read the contents of a file
std::string BF::readFile(const std::string& filename) {
    std::ifstream input(filename);
    
    if(input.fail()) {
        throw std::runtime_error("Error: Failed to open file named: " +
                                 filename +
                                 ".");
    }
    
    std::string stringValue((std::istreambuf_iterator<char>(input)),
                            (std::istreambuf_iterator<char>()));
    return stringValue;
}

// A function to throw an error if the stack is empty
void BF::errorMatching(std::stack<std::string::const_iterator>& stack) {
    if(stack.empty()) {
        throw std::runtime_error(ERROR_DOES_NOT_MATCH);
    }
}

void BF::interpret(std::string filename) {
    interpretBf(readFile(filename));
}

void BF::incrementOperator() {
    ++memoryIterator;
    
    // If memoryIterator is memory.end(), then
    // we have a buffer overflow
    if(memoryIterator == memory.end()) {
        throw std::runtime_error("Error: Buffer Overflow");
    }
}

void BF::decrementOperator() {
    // If memoryIterator is memory.begin(), then
    // we have a buffer underwrite
    if(memoryIterator == memory.begin()) {
        throw std::runtime_error("Error: Buffer Underwrite");
    }
    
    // Else, we update the memory pointer
    --memoryIterator;
}

void BF::saveInstruction() {
    instructionStack.push(instructionIterator);
}

void BF::pop() {
    instructionStack.pop();
}

std::string::const_iterator BF::top() {
    return instructionStack.top();
}

std::string::const_iterator BF::getNewInstruction() {
    errorMatching(instructionStack);
    std::string::const_iterator it = top();
    pop();
    
    return it;
}

void BF::moveLeftOperator(std::string& bf) {
    saveInstruction();
    std::string::const_iterator startInstructionPtr = instructionIterator;
    
    if(*memoryIterator == 0) {
        for(;++instructionIterator != bf.end();) {
            if(*instructionIterator == '[') {
                saveInstruction();
            } else if(*instructionIterator == ']') {
                if(startInstructionPtr == getNewInstruction()) {
                    return;
                }
            }
        }
    }
}

void BF::moveRightOperator() {
    errorMatching(instructionStack);

    if(*memoryIterator == 0) {
        pop();
    } else {
        instructionIterator = top();
    }
}

bool BF::isToken(char c) {
    return c == '+' || c == '-' || c == '<' ||
    c == '>'|| c == '['|| c == ']' ||
    c == ',' || c == '.';
}

std::string BF::cleanInput(std::string& bf) {
    std::string newBF;

    for(int i = 0; i < bf.size(); ++i) {
        if(isToken(bf.at(i))) {
            newBF += bf.at(i);
        }
    }

    return newBF;
}

// The main function to interpret BF
void BF::interpretBf(std::string program) {
    std::string bf = cleanInput(program);
    memoryIterator = memory.begin();
    instructionIterator = bf.begin();

    // Main loop
    while(instructionIterator != bf.end()) {
        switch(*instructionIterator) {
            case '+':
                // Update the memory at memoryIterator
                ++(*memoryIterator);
                break;
            case '-':
                // Update the memory at memoryIterator
                --(*memoryIterator);
                break;
            case '.':
                // We print
                printf("%c", *memoryIterator);
                break;
            case ',':
                // We simply get the input from the user
                scanf("%c", &(*memoryIterator));
                break;
            case '>':
                incrementOperator();
                break;
            case '<':
                decrementOperator();
                break;
            case '[':
                moveLeftOperator(bf);
                break;
            case ']':
                moveRightOperator();
                break;
            default:
                break;
        }

        ++instructionIterator;
    }
}
