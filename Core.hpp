#ifndef HENCEFORTH_CORE_HPP
#define HENCEFORTH_CORE_HPP

#include <map>
#include <memory>
#include "ArithmeticDefinitions.hpp"

using DefDict = std::map<std::string, std::shared_ptr<Definition>>;
using DDRef = std::shared_ptr<DefDict>;
DDRef GetCoreDict();


#endif //HENCEFORTH_CORE_HPP
