#include "ArithmeticDefinitions.hpp"

// generic binary arithmetic operation
void BinOp(Stack &s, ptrdiff_t(*f)(ptrdiff_t,ptrdiff_t)) {
    auto b = s.top(); s.pop();
    auto a = s.top(); s.pop();
    s.push(f(a, b));
}

void Add::Run(Stack &s, Stack &r, ptrdiff_t &ip) {
    BinOp(s, [](auto a, auto b) { return a+b; });
}

void Sub::Run(Stack &s, Stack &r, ptrdiff_t &ip) {
    BinOp(s, [](auto a, auto b) { return a-b; });
}

void Mul::Run(Stack &s, Stack &r, ptrdiff_t &ip) {
    BinOp(s, [](auto a, auto b) { return a*b; });
}

void Div::Run(Stack &s, Stack &r, ptrdiff_t &ip) {
    BinOp(s, [](auto a, auto b) { return a/b; });
}

void Mod::Run(Stack &s, Stack &r, ptrdiff_t &ip) {
    BinOp(s, [](auto a, auto b) { return a%b; });
}

void DivMod::Run(Stack &s, Stack &r, ptrdiff_t &ip) {
    auto b = s.top(); s.pop();
    auto a = s.top(); s.pop();
    s.push(a % b);
    s.push(a / b);
}

void RShift::Run(Stack &s, Stack &r, ptrdiff_t &ip) {
    BinOp(s, [](auto a, auto b) { return a>>b; });
}

void LShift::Run(Stack &s, Stack &r, ptrdiff_t &ip) {
    BinOp(s, [](auto a, auto b) { return a<<b; });
}

void Yes::Run(Stack &s, Stack &r, ptrdiff_t &ip) {
    s.push(1);
}

void No::Run(Stack &s, Stack &r, ptrdiff_t &ip) {
    s.push(0);
}

Const::Const(ptrdiff_t c) : c(c) {}

void Const::Run(Stack &s, Stack &r, ptrdiff_t &ip) {
    s.push(c);
}

void More::Run(Stack &s, Stack &r, ptrdiff_t &ip) {
    BinOp(s, [](auto a, auto b) { return static_cast<ptrdiff_t>(a > b); });
}

void Less::Run(Stack &s, Stack &r, ptrdiff_t &ip) {
    BinOp(s, [](auto a, auto b) { return static_cast<ptrdiff_t>(a > b); });
}

void Eq::Run(Stack &s, Stack &r, ptrdiff_t &ip) {
    BinOp(s, [](auto a, auto b) { return static_cast<ptrdiff_t>(a == b); });
}
