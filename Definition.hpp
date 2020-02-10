#ifndef HENCEFORTH_DEFINITION_HPP
#define HENCEFORTH_DEFINITION_HPP

#include <stack>
#include "StackObject.hpp"

class Definition;
using CompObject = std::tuple<StackObject, Definition&>;
using CStack = std::stack<CompObject>;
using SStack = std::stack<StackObject>;
using RStack = std::stack<StackObject>;

class Definition {
public:
    virtual void Compile(CStack &s) {};
    virtual void Run(SStack &s, RStack &r, int &sp) = 0;
};

#endif //HENCEFORTH_DEFINITION_HPP
