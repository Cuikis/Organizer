#include "group.h"
#include <stdlib.h>
#include <conio.h>

Group::Group()
{

}

Group::Group(int value)
{
    int instruction = value*0;
    int numberOfChild = 0;

    Child child;

    std::string groupName;

    system("cls");

    std::cin.ignore(256,'\n');

    std::cout << "Introducir nombre del grupo: " << std::endl;
    std::getline(std::cin,groupName);
    this->mGroupName = groupName;


    while( instruction != -1 )
    {
        switch (instruction)
        {
        case 0:
            system("cls");
            std::cout << "MENU GRUPO NUEVO (Nombre grupo: " << this->mGroupName << "; chavales: " << this->mChilds.size() << ")" << std::endl;
            std::cout << "1. Cambiar nombre del grupo" << std::endl;
            std::cout << "2. Introducir un chaval nuevo" << std::endl;
            std::cout << "3. Mostrar lista del grupo" << std::endl;
            std::cout << "4. Cerrar grupo" << std::endl;
            std::cin >> instruction;

            if( !std::cin.good() )
            {
                std::cout << "AVISO: debes introducir un numero del 1 al 4" << std::endl;
                std::cin.clear();
                std::cin.ignore(256,'\n');
                instruction = 0;
                system("Pause");
            }
            else
            {
                std::cin.ignore(256,'\n');
            }
            system("cls");
            break;
        case 1:
            std::cin.ignore(256,'\n');
            std::cout << "Nuevo nombre: " << std::endl;
            std::getline(std::cin,groupName);
            std::cin >> groupName;
            this->mGroupName = groupName;
            instruction = 0;
            break;
        case 2:
            child = this->newChild();
            if( !child.mError )
            {
                this->mChilds.push_back(child);
                this->mChilds[numberOfChild].showChild();
                numberOfChild++;
            }
            instruction = 0;
            break;
        case 3:
            this->childList();
            system("Pause");
            instruction = 0;
            break;
        case 4:
            instruction =  -1;
            break;
        default:
            instruction = 0;
            std::cout << "AVISO: introduce un numero del 1 al 4" << std::endl;
            system("Pause");
            break;
        }
    }

    system("cls");
    this->childList();
    system("pause");
}

Child Group::newChild()
{
    std::string name;
    int course;
    char gender;

    std::cout << "Nombre: ";
    std::getline(std::cin,name);

    std::cout << "Curso (5, 6, 1, 2): ";
    std::cin >> course;

    std::cout << "Sexo (M o H): ";
    std::cin >> gender;

    return Child(name,course,gender);
}

void Group::newChild(std::string _name, int _course, char _gender)
{
    Child child(_name,_course,_gender);
    this->mChilds.push_back(child);
}

void Group::childList()
{
    std::cout << "Grupo: " << this->mGroupName << std::endl;
    std::cout << "     " << "Nombre" << "                             " << "Curso" << "   " << "Sexo" << std::endl;
    for( unsigned i = 0; i<this->mChilds.size(); i++)
    {
        std::cout << i+1 << ".   ";
        this->mChilds[i].showChild();
        std::cout << std::endl;
    }
}
