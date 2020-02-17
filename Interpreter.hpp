#ifndef HENCEFORTH_INTERPRETER_HPP
#define HENCEFORTH_INTERPRETER_HPP

#include <iostream>
#include "Tokenizer.hpp"
#include "Definition.hpp"
#include "Compiler.hpp"

class Interpreter {
    DefDict dict;
    Stack s, r;
    void ExecuteCommand(const std::string &token);
public:
    explicit Interpreter() : dict(GetCoreDict()) {}
    void Run(std::istream &in, bool quiet);
};


#endif //HENCEFORTH_INTERPRETER_HPP
