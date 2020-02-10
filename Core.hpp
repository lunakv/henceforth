//
// Created by vaasa on 2/10/20.
//

#ifndef HENCEFORTH_CORE_HPP
#define HENCEFORTH_CORE_HPP

#include <map>
#include <memory>
#include "ArithmeticDefinitions.hpp"

using DefDict = std::map<std::string, std::shared_ptr<Definition>>;
std::unique_ptr<DefDict> GetCoreDict();


#endif //HENCEFORTH_CORE_HPP
