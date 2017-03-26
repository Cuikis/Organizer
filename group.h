#ifndef GROUP_H
#define GROUP_H

#include <iostream>
#include "child.h"
#include <vector>

class Group
{
public:
    // Constructors
    Group();
    Group(int);

    // Members
    std::vector<Child> mChilds;     // Childs of the group
    std::string mGroupName;         // Group's name

    // Methods
    Child newChild();                           // Adds a new child to the group
    void newChild(std::string, int, char);

    void childList();                           // List all the group childs
};

#endif // GROUP_H
