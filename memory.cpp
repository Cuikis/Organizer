#include "memory.h"
#include "direct.h"


Memory::Memory()
{
    mkdir("./saves");
}

void Memory::save(Group _group)
{
    // Directory and file
    this->mOutFile = std::ofstream("./saves/"+_group.mGroupName);

    std::vector<Child> childsVector = _group.mChilds;

    // First Line is group's name
    this->mOutFile << _group.mGroupName << std::endl;

    for( unsigned i=0; i<childsVector.size(); i++)
    {
        Child child = childsVector[i];
        // First 35 characters are name, next 1 are course and last 1 is gender = 38
        this->mOutFile << child.mName << child.mCourse << child.mGender << std::endl;
    }

    this->mOutFile.close();
}

Group Memory::load(std::string _fileName)
{
    // Directory and file
    this->mInFile = std::ifstream("./saves/"+_fileName);

    if( this->mInFile.fail() )
    {
        std::cout << "ERROR: el archivo no existe o no se abrio con exito" << std::endl;
        system("Pause");
        return Group();
    }

    Group group_;

    // I have to do this to know how many lines there are
    // because last line is not useful
    int index = 0;

    while( !this->mInFile.eof() )
    {
        char line[38];
        this->mInFile.getline(line,38);
        index++;
    }

    this->mInFile.close();

    this->mInFile = std::ifstream("./saves/"+_fileName);

    // Group's name reading
    char firstLine[15];
    this->mInFile.getline(firstLine,' ');

    std::string groupName(firstLine);

    std::cout << groupName << std::endl;

    group_.mGroupName = groupName;

    // Group's members data reading
    for( int i=1; i<index-1 ; i++ )
    {
        char line[38];
        this->mInFile.getline(line,38);

        std::string name(line,0,35);
        //std::cout << name << std::endl;
        char number[1];
        number[0] = line[35];
        int course = atoi(number);

        //std::cout << course << std::endl;

        char gender = line[36];

        //std::cout << gender << std::endl;

        group_.newChild(name,course,gender);

        //system("Pause");
    }

//    while( !this->mInFile.eof() )
//    {
//        char line[38];
//        this->mInFile.getline(line,38);

//        std::string name(line,0,35);
//        std::cout << name << std::endl;
//        char number[1];
//        number[0] = line[35];
//        int course = atoi(number);

//        std::cout << course << std::endl;

//        char gender = line[36];

//        std::cout << gender << std::endl;

//        group_.newChild(name,course,gender);

//        system("Pause");
//    }

    // Close file and return value
    this->mInFile.close();
    return group_;
}
