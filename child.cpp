#include "child.h"

Child::Child()
{

}

Child::Child(std::string _name, int _course, char _gender)
{
    if( (_course != 5) && (_course != 6) && (_course != 1) && (_course != 2) )
    {
        std::cout << "ERROR: solo se admiten como cursos 5, 6, 1 y 2" << std::endl;
        system("Pause");
        this->mError = 1;
        return;
    }

    if( _gender != 'H' && _gender != 'h' && _gender != 'm' && _gender != 'M' )
    {
        std::cout << "ERROR: solo se admiten como sexos H (hembra) o M (macho)" << std::endl;
        system("Pause");
        this->mError = 1;
        return;
    }

    // Name with blank spaces fill 35 characters
    this->mName = _name;
    std::string blankSpaces(this->maxNameLength-_name.size(),' ');
    this->mName.insert(this->mName.size(),blankSpaces);

    this->mGender = _gender;

    this->mCourse = _course;

    this->mError = 0;
}

void Child::showChild()
{
    std::cout << this->mName;
    std::string blankSpaces(7,' ');

    std::cout << this->mCourse << blankSpaces;

    if( this->mGender == 'H' || this->mGender == 'h')
    {
        std::cout << "Hembra";
    }
    else
    {
        std::cout << "Macho";
    }
}
