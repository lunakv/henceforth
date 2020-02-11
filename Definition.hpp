#ifndef HENCEFORTH_DEFINITION_HPP
#define HENCEFORTH_DEFINITION_HPP

#include <stack>
#include <vector>
#include <memory>
#include "StackObject.hpp"

class Definition;
using CStack = std::stack<int>;
using SStack = std::stack<StackObject>;
using RStack = std::stack<StackObject>;

class Definition {
public:
    virtual void Compile(size_t res) {};
    virtual void Run(SStack &s, RStack &r, int &sp) = 0;
};

class CustomDefinition : public Definition {
    std::vector<std::shared_ptr<Definition>> v;
public:
    explicit CustomDefinition(std::vector<std::shared_ptr<Definition>> v);
    void Run(SStack &s, RStack &r, int &sp) override;
};

class Branching : public Definition {
protected:
    size_t jmp{};
public:
    void Compile(size_t res) override;
};

#endif //HENCEFORTH_DEFINITION_HPP
