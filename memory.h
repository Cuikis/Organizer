#ifndef MEMORY_H
#define MEMORY_H

#include "group.h"
#include <fstream>

class Memory
{
public:
    Memory();

    // Members
    std::ofstream mOutFile;         // To write in a file
    std::ifstream mInFile;          // To read of a file

    // Methods
    void save(Group);                   // Saves group data
    Group load(std::string _fileName);  // Loads group data
};

#endif // MEMORY_H
