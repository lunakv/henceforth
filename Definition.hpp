#ifndef HENCEFORTH_DEFINITION_HPP
#define HENCEFORTH_DEFINITION_HPP

#include <stack>
#include <vector>
#include <memory>
#include <map>

// stack wrapper that throws exceptions on underflow
class Stack {
    std::stack<ptrdiff_t> s;
public:
    ptrdiff_t & top();
    void pop();
    void push(const ptrdiff_t &val) { s.push(val); }
    void push(ptrdiff_t &&val) { s.push(val); }
    [[nodiscard]] bool empty() const { return s.empty(); }
};

// Abstract class for defining word semantics
class Definition {
public:
    virtual void Compile(size_t res) {};
    virtual void Run(Stack &s, Stack &r, size_t &ip) const = 0;
};

// User created definition - represented as a list of definitions to execute
class CustomDefinition : public Definition {
    std::vector<std::shared_ptr<Definition>> v;
public:
    void Run(Stack &s, Stack &r, size_t &ip) const override;
    [[nodiscard]] size_t size() const { return v.size(); }
    std::shared_ptr<Definition> operator[](size_t i) { return v[i]; }
    friend class Compiler;
};

// Definitions that may want to change the instruction pointer inherit from this class
class Branching : public Definition {
protected:
    size_t jmp{};
public:
    void Compile(size_t res) override { jmp = res; };
};

using DefDict = std::map<std::string, std::shared_ptr<Definition>>;
using DDRef = std::shared_ptr<DefDict>;
#endif //HENCEFORTH_DEFINITION_HPP
