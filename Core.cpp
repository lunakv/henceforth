#include <iostream>
#include "Core.hpp"

DDRef GetCoreDict() {
    auto d = std::make_shared<DefDict>();
    (*d)["+"] = std::make_shared<Add>();
    (*d)["-"] = std::make_shared<Sub>();
    (*d)["*"] = std::make_shared<Mul>();
    (*d)["/"] = std::make_shared<Div>();
    (*d)["MOD"] = std::make_shared<Mod>();
    (*d)["/MOD"] = std::make_shared<DivMod>();
    (*d)["TRUE"] = std::make_shared<Yes>();
    (*d)["FALSE"] = std::make_shared<No>();
    (*d)["RSHIFT"] = std::make_shared<RShift>();
    (*d)["LSHIFT"] = std::make_shared<LShift>();
    (*d)["<"] = std::make_shared<Less>();
    (*d)[">"] = std::make_shared<More>();
    (*d)["="] = std::make_shared<Eq>();
    (*d)["AND"] = std::make_shared<And>();
    (*d)["OR"] = std::make_shared<Or>();
    (*d)["XOR"] = std::make_shared<Xor>();
    (*d)["MAX"] = std::make_shared<Max>();
    (*d)["MIN"] = std::make_shared<Min>();
    (*d)["WITHIN"] = std::make_shared<Within>();

    (*d)["DUP"] = std::make_shared<Dup>();
    (*d)["DROP"] = std::make_shared<Drop>();
    (*d)["."] = std::make_shared<Print>();
    (*d)["CR"] = std::make_shared<Cr>();
    return std::move(d);
}

// generic binary arithmetic operation
void BinOp(Stack &s, ptrdiff_t(*f)(ptrdiff_t,ptrdiff_t)) {
    auto b = s.top(); s.pop();
    auto a = s.top(); s.pop();
    s.push(f(a, b));
}

void Add::Run(Stack &s, Stack &r, ptrdiff_t &ip) const {
    BinOp(s, [](auto a, auto b) { return a+b; });
}

void Sub::Run(Stack &s, Stack &r, ptrdiff_t &ip) const {
    BinOp(s, [](auto a, auto b) { return a-b; });
}

void Mul::Run(Stack &s, Stack &r, ptrdiff_t &ip) const {
    BinOp(s, [](auto a, auto b) { return a*b; });
}

void Div::Run(Stack &s, Stack &r, ptrdiff_t &ip) const {
    BinOp(s, [](auto a, auto b) { return a/b; });
}

void Mod::Run(Stack &s, Stack &r, ptrdiff_t &ip) const {
    BinOp(s, [](auto a, auto b) { return a%b; });
}

void DivMod::Run(Stack &s, Stack &r, ptrdiff_t &ip) const {
    auto b = s.top(); s.pop();
    auto a = s.top(); s.pop();
    s.push(a % b);
    s.push(a / b);
}

void RShift::Run(Stack &s, Stack &r, ptrdiff_t &ip) const {
    BinOp(s, [](auto a, auto b) { return a>>b; });
}

void LShift::Run(Stack &s, Stack &r, ptrdiff_t &ip) const {
    BinOp(s, [](auto a, auto b) { return a<<b; });
}

void Yes::Run(Stack &s, Stack &r, ptrdiff_t &ip) const {
    s.push(1);
}

void No::Run(Stack &s, Stack &r, ptrdiff_t &ip) const {
    s.push(0);
}

Const::Const(ptrdiff_t c) : c(c) {}

void Const::Run(Stack &s, Stack &r, ptrdiff_t &ip) const {
    s.push(c);
}

void More::Run(Stack &s, Stack &r, ptrdiff_t &ip) const {
    BinOp(s, [](auto a, auto b) { return static_cast<ptrdiff_t>(a > b); });
}

void Less::Run(Stack &s, Stack &r, ptrdiff_t &ip) const {
    BinOp(s, [](auto a, auto b) { return static_cast<ptrdiff_t>(a > b); });
}

void Eq::Run(Stack &s, Stack &r, ptrdiff_t &ip) const {
    BinOp(s, [](auto a, auto b) { return static_cast<ptrdiff_t>(a == b); });
}

void And::Run(Stack &s, Stack &r, ptrdiff_t &ip) const {
    BinOp(s, [](auto a, auto b) { return a & b; });
}

void Or::Run(Stack &s, Stack &r, ptrdiff_t &ip) const {
    BinOp(s, [](auto a, auto b) { return a | b; });
}

void Xor::Run(Stack &s, Stack &r, ptrdiff_t &ip) const {
    BinOp(s, [](auto a, auto b) { return a^b; });
}

void Max::Run(Stack &s, Stack &r, ptrdiff_t &ip) const {
    BinOp(s, [](auto a, auto b) { return std::max(a, b); });
}

void Min::Run(Stack &s, Stack &r, ptrdiff_t &ip) const {
    BinOp(s, [](auto a, auto b) { return std::min(a, b); });
}

void Within::Run(Stack &s, Stack &r, ptrdiff_t &ip) const {
    auto hi = s.top(); s.pop();
    auto lo = s.top(); s.pop();
    auto test = s.top(); s.pop();
    if (hi >= lo)
        s.push(static_cast<ptrdiff_t>(test >= lo && test <= hi));
    else
        s.push(static_cast<ptrdiff_t>(test >= lo || test <= hi));
}

void Dup::Run(Stack &s, Stack &r, ptrdiff_t &ip) const {
    s.push(s.top());
}

void Drop::Run(Stack &s, Stack &r, ptrdiff_t &ip) const {
    s.pop();
}

void Print::Run(Stack &s, Stack &r, ptrdiff_t &ip) const {
    std::cout << s.top() << ' ';
    s.pop();
}

void Cr::Run(Stack &s, Stack &r, ptrdiff_t &ip) const {
    std::cout << std::endl;
}
