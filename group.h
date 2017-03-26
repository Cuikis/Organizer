#ifndef GROUP_H
#define GROUP_H

#include <iostream>
#include "child.h"
#include <vector>

class Group
{
public:
    Group();

    // Members
    std::vector<Child> mChilds;

    // Methods
    Child newChild();

    void childList();
};

#endif // GROUP_H
