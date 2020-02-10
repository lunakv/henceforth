//
// Created by vaasa on 2/10/20.
//

#include <string>
#include "StackObject.hpp"

StackObject::StackObject(int val) : val(val), str()
{}

StackObject::StackObject(std::string str) : str(std::move(str)), val()
{}

StackObject::StackObject(std::string &&str) : str(std::move(str)), val()
{}
