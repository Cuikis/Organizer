#ifndef GROUP_H
#define GROUP_H

#include <iostream>
#include "child.h"
#include <vector>

class Group
{
public:
    Group();
    Group(int);

    // Members
    std::vector<Child> mChilds;
    std::string mGroupName;

    // Methods
    Child newChild();
    void newChild(std::string, int, char);

    void childList();
};

#endif // GROUP_H
