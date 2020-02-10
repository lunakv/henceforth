//
// Created by vaasa on 2/10/20.
//

#include "Core.hpp"

std::unique_ptr<DefDict> GetCoreDict() {
    auto d = std::make_unique<DefDict>();
    (*d)["ADD"] = std::make_shared<Add>();
    (*d)["SUB"] = std::make_shared<Sub>();
    (*d)["MUL"] = std::make_shared<Mul>();
    (*d)["DIV"] = std::make_shared<Div>();
    (*d)["MOD"] = std::make_shared<Mod>();
    (*d)["TRUE"] = std::make_shared<Yes>();
    (*d)["FALSE"] = std::make_shared<No>();
    (*d)["RSHIFT"] = std::make_shared<RShift>();
    (*d)["LSHIFT"] = std::make_shared<LShift>();
    (*d)["<"] = std::make_shared<Less>();
    (*d)[">"] = std::make_shared<More>();
    (*d)["="] = std::make_shared<Eq>();
    return std::move(d);
}