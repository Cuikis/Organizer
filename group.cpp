#include "group.h"
#include <stdlib.h>
#include <conio.h>

Group::Group()
{
    int flag = 1;
    int numberOfChild = 0;

    Child child;

    while( flag )
    {
        std::cout << "Introduzca 1 si quiere añadir un niño," << std::endl;
        std::cout << "y 0 si quiere cerrar el grupo" << std::endl;

        std::cin >> flag;
        std::cin.ignore(256,'\n');

        if(flag)
        {
            child = this->newChild();
            if( !child.mError )
            {
                this->mChilds.push_back(child);
                this->mChilds[numberOfChild].showChild();
                numberOfChild++;
                std::cout << std::endl << "Introducidos " << numberOfChild << " niños." << std::endl;
                system("Pause");
            }
        }

        system("cls");
    }
}

Child Group::newChild()
{
    std::string name;
    int course;
    char gender;

    std::cout << "Nombre: ";
    std::getline(std::cin,name);
    std::cout << std::endl;

    std::cout << "Curso (5, 6, 1, 2): ";
    std::cin >> course;
    std::cout << std::endl;

    std::cout << "Sexo (M o H): ";
    std::cin >> gender;
    std::cout << std::endl;

    return Child(name,course,gender);
}

void Group::childList()
{
    for( unsigned i = 0; i<this->mChilds.size(); i++)
    {
        std::cout << "Niño numero " << i+1 << std::endl;
        this->mChilds[i].showChild();
        std::cout << std::endl;
    }
}
