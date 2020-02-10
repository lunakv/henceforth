//
// Created by vaasa on 2/10/20.
//

#ifndef HENCEFORTH_STACKOBJECT_HPP
#define HENCEFORTH_STACKOBJECT_HPP

struct StackObject {
    int val;
    std::string str;
    explicit StackObject(int val);
    explicit StackObject(std::string str);
    explicit StackObject(std::string && str);
};

#endif //HENCEFORTH_STACKOBJECT_HPP
