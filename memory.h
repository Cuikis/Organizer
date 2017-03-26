#ifndef MEMORY_H
#define MEMORY_H

#include "group.h"
#include <fstream>

class Memory
{
public:
    Memory();

    // Members
    std::ofstream mOutFile;
    std::ifstream mInFile;

    // Methods
    void save(Group);
    Group load();
};

#endif // MEMORY_H
