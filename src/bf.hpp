//
//  bf.hpp
//  BFInterpreter
//
//  Copyright © 2020 Cosme Jordan. All rights reserved.
//

#ifndef bf_hpp
#define bf_hpp

#include <string>
#include <stack>
#include <vector>

class BF {
private:
    static std::size_t MEMORY_SIZE;

    // Variables
    std::vector<char> memory;
    std::vector<char>::iterator memoryIterator;
    std::string::const_iterator instructionIterator;
    std::stack<std::string::const_iterator> instructionStack;

public:
    BF();
    void interpret(std::string filename);

private:
    std::string readFile(const std::string& filename);

    void interpretBf(std::string program);
    void errorMatching(std::stack<std::string::const_iterator>& stack);

    // Increment and decrement operator
    void incrementOperator();
    void decrementOperator();

    // Move operators
    void moveLeftOperator(std::string& bf);
    void moveRightOperator();

    // Save instruction
    void saveInstruction();
    
    std::string::const_iterator getNewInstruction();
    std::string cleanInput(std::string& bf);
    
    // Stack instruction
    void pop();
    std::string::const_iterator top();
    bool isToken(char c);
};

#endif /* bf_hpp */
