#include <iostream>
#include <string>
#include <locale>
#include <fstream>

#include "group.h"
#include "memory.h"
#include "subgroup.h"
#include "functions.h"

using namespace std;

int main()
{
//    locale::global(locale("spanish"));

//    int instruction = 0;

//    std::vector<Group> groupInUse;

//    string fileName;

//    Group group;

//    Memory memory;

//    while( instruction != -1 )
//    {
//        switch (instruction)
//        {
//        case 1:
//            group = Group(1);
//            groupInUse.push_back(group);
//            instruction = 0;
//            break;
//        case 2:
//            for( unsigned i=0; i<groupInUse.size(); i++)
//            {
//                groupInUse[i].childList();
//            }
//            system("Pause");
//            instruction = 0;
//            break;
//        case 3:
//            cout << "Seleccione el grupo cuyos datos quiere guardar" << endl;
//            std::cout << "0. No guardar ningun grupo" << std::endl;
//            for( unsigned i = 0; i<groupInUse.size(); i++)
//            {
//                std::cout << i+1 << ". " << groupInUse[i].mGroupName << endl;
//            }
//            cin >> instruction;

//            if( instruction )
//            {
//                memory.save(groupInUse[instruction-1]);
//                instruction = 0;
//            }
//            break;
//        case 4:
//            std::cin.ignore(256,'\n');
//            cout << "Introduzca el nombre del grupo a cargar: " << endl;
//            getline(cin,fileName);
//            group = memory.load(fileName);
//            if( group.mChilds.size() != (unsigned)0 )
//            {
//                groupInUse.push_back(group);
//            }
//            instruction = 0;
//            break;
//        case 5:
//            instruction = -1;
//            break;
//        default:
//            system("cls");
//            cout << "MENU" << endl;
//            cout << "1. Crear un nuevo grupo" << endl;
//            cout << "2. Listar los grupos existentes" << endl;
//            cout << "3. Guardar los datos de un grupo" << endl;
//            cout << "4. Cargar los datos de un grupo" << endl;
//            cout << "5. Salir del programa" << endl;

//            cin >> instruction;

//            if( !std::cin.good() )
//            {
//                std::cout << "AVISO: debes introducir un numero del 1 al 5" << std::endl;
//                std::cin.clear();
//                std::cin.ignore(256,'\n');
//                instruction = 0;
//                system("Pause");
//            }

//            system("cls");
//            break;
//        }

//    }

//    allocate(groupInUse[0]);

    system("Pause");

    return 0;
}
