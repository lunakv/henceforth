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
    return std::move(d);
}