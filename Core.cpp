#include "Core.hpp"

DDRef GetCoreDict() {
    auto d = std::make_shared<DefDict>();
    (*d)["+"] = std::make_shared<Add>();
    (*d)["-"] = std::make_shared<Sub>();
    (*d)["*"] = std::make_shared<Mul>();
    (*d)["/"] = std::make_shared<Div>();
    (*d)["MOD"] = std::make_shared<Mod>();
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