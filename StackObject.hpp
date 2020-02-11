#ifndef HENCEFORTH_STACKOBJECT_HPP
#define HENCEFORTH_STACKOBJECT_HPP

#include <string>

struct StackObject {
    int val;
    std::string str;
    explicit StackObject(int val);
    explicit StackObject(std::string str);
    explicit StackObject(std::string && str);
};

#endif //HENCEFORTH_STACKOBJECT_HPP
