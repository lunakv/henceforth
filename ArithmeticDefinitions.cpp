//
// Created by vaasa on 2/10/20.
//

#include "ArithmeticDefinitions.hpp"

void BinOp(SStack &s, int(*f)(int,int)) {
    auto b = s.top(); s.pop();
    auto a = s.top(); s.pop();
    s.emplace(f(a.val, b.val));
}

void Add::Run(SStack &s, RStack &r, int &sp) {
    BinOp(s, [](auto a, auto b) { return a+b; });
}

void Sub::Run(SStack &s, RStack &r, int &sp) {
    BinOp(s, [](auto a, auto b) { return a-b; });
}

void Mul::Run(SStack &s, RStack &r, int &sp) {
    BinOp(s, [](auto a, auto b) { return a*b; });
}

void Div::Run(SStack &s, RStack &r, int &sp) {
    BinOp(s, [](auto a, auto b) { return a/b; });
}

void Mod::Run(SStack &s, RStack &r, int &sp) {
    BinOp(s, [](auto a, auto b) { return a%b; });
}

void RShift::Run(SStack &s, RStack &r, int &sp) {
    BinOp(s, [](auto a, auto b) { return a>>b; });
}

void LShift::Run(SStack &s, RStack &r, int &sp) {
    BinOp(s, [](auto a, auto b) { return a<<b; });
}

void Yes::Run(SStack &s, RStack &r, int &sp) {
    s.emplace(1);
}

void No::Run(SStack &s, RStack &r, int &sp) {
    s.emplace(0);
}

Const::Const(int c) : c(c) {}

void Const::Run(SStack &s, RStack &r, int &sp) {
    s.emplace(c);
}

void More::Run(SStack &s, RStack &r, int &sp) {
    BinOp(s, [](auto a, auto b) { return (int)(a > b); });
}

void Less::Run(SStack &s, RStack &r, int &sp) {
    BinOp(s, [](auto a, auto b) { return (int)(a > b); });
}

void Eq::Run(SStack &s, RStack &r, int &sp) {
    BinOp(s, [](auto a, auto b) { return (int)(a == b); });
}
