#include "memory.h"

Memory::Memory()
{
}

void Memory::save(Group _group)
{
    this->mOutFile = std::ofstream("data");

    std::vector<Child> childsVector = _group.mChilds;

    for( unsigned i=0; i<childsVector.size(); i++)
    {
        Child child = childsVector[i];
        // First 35 characters are name, next 1 are course and last 1 is gender = 38
        this->mOutFile << child.mName << child.mCourse << child.mGender << std::endl;
    }
}

Group Memory::load()
{
    this->mInFile = std::ifstream("data");

    Group group_;

    while( !this->mInFile.eof() )
    {
        char line[38];
        this->mInFile.getline(line,38);

        std::string name(line,0,35);
        std::cout << name << std::endl;
        char number[1];
        number[0] = line[35];
        int course = atoi(number);

        std::cout << course << std::endl;

        char gender = line[36];

        std::cout << gender << std::endl;

        group_.newChild(name,course,gender);
    }

    return Group();
}
