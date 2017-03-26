#include "child.h"

Child::Child()
{

}

Child::Child(std::string _name, int _course, char _gender)
{
    this->mName = _name;

    if( (_course != 5) && (_course != 6) && (_course != 1) && (_course != 2) )
    {
        std::cout << "ERROR: solo se admiten como cursos 5, 6, 1 y 2" << std::endl;
        this->mError = 1;
        return;
    }

    if( _gender != 'H' && _gender != 'h' && _gender != 'm' && _gender != 'M' )
    {
        std::cout << "ERROR: solo se admiten como sexos H (hembra) o M (macho)" << std::endl;
        this->mError = 1;
        return;
    }

    this->mGender = _gender;
    this->mCourse = _course;
    this->mError = 0;
}

void Child::showChild()
{
    unsigned maxNameLength = 35;

    //std::cout << "Nombre: " << this->mName << std::endl;
    std::cout << this->mName;

    for( unsigned i = this->mName.size(); i<maxNameLength; i++ )
    {
        std::cout << " ";
    }

    //std::cout << "Curso: " << this->mCourse << std::endl;
    std::cout << this->mCourse << "       ";
    if( this->mGender == 'H' || this->mGender == 'h')
    {
        //std::cout << "Sexo: hembra" << std::endl;
        std::cout << "Hembra";
    }else{
        //std::cout << "Sexo: macho" << std::endl;
        std::cout << "Macho";
    }
}
