#ifndef HENCEFORTH_INTERPRETER_HPP
#define HENCEFORTH_INTERPRETER_HPP

#include <iostream>
#include "Tokenizer.hpp"
#include "Definition.hpp"
#include "Compiler.hpp"

class Interpreter {
    Tokenizer t;
    Compiler c;
    DefDict dict;
    Stack s, r;
    void ExecuteCommand(const std::string &token);
public:
    explicit Interpreter(std::istream &i) : t(i), c(t), dict(GetCoreDict()) {}
    void Run();
};


#endif //HENCEFORTH_INTERPRETER_HPP
