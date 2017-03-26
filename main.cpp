#include <iostream>
#include <string>
#include <locale>
#include <fstream>

#include "group.h"
#include "memory.h"

using namespace std;

int main()
{
    locale::global(locale("spanish"));

    int instruction = 0;

    std::vector<Group> groupInUse;

    string fileName;

    Group group;

    Memory memory;

    while( instruction != -1 )
    {
        switch (instruction)
        {
        case 1:
            group = Group(1);
            groupInUse.push_back(group);
            instruction = 0;
            break;
        case 2:
            for( unsigned i=0; i<groupInUse.size(); i++)
            {
                groupInUse[i].childList();
            }
            system("Pause");
            instruction = 0;
            break;
        case 3:
            cout << "Seleccione el grupo cuyos datos quiere guardar" << endl;
            std::cout << "0. No guardar ningun grupo" << std::endl;
            for( unsigned i = 0; i<groupInUse.size(); i++)
            {
                std::cout << i+1 << ". " << groupInUse[i].mGroupName << endl;
            }
            cin >> instruction;

            if( instruction )
            {
                memory.save(groupInUse[instruction-1]);
                instruction = 0;
            }
            break;
        case 4:
            std::cin.ignore(256,'\n');
            cout << "Introduzca el nombre del grupo a cargar: " << endl;
            getline(cin,fileName);
            group = memory.load(fileName);
            groupInUse.push_back(group);
            instruction = 0;
            break;
        case 5:
            instruction = -1;
            break;
        default:
            system("cls");
            cout << "MENU" << endl;
            cout << "1. Crear un nuevo grupo" << endl;
            cout << "2. Listar los grupos existentes" << endl;
            cout << "3. Guardar los datos de un grupo" << endl;
            cout << "4. Cargar los datos de un grupo" << endl;
            cout << "5. Salir del programa" << endl;

            cin >> instruction;
            system("cls");
            break;
        }

    }

//    Memory memoria;

    //memoria.save(grupo);

//    grupo = memoria.load();

//    grupo.childList();

//    memoria.save(grupo);

//    // APERTURA DE ARCHIVO PARA ESCRITURA
//    ofstream fichero("guardado");

//    fichero << "Jose                               " << "5" << "m";
//    fichero.close();

//    // APERTURA DE ARCHIVO PARA LECTURA
//    ifstream fichero2("guardado");

//    char line[38];

//    fichero2.getline(line,38);
//    cout << line << endl;

//    // COPIA CHAR A STRING (caracteres que queramos)
////    string pureba(cadena,0,5);
////    string segunda(cadena,5,6);

////    cout << pureba << endl;
////    cout << segunda << endl;
//    std::string name(line,0,35);
//    cout << name << endl;

//    char number[1];
//    number[0] = line[35];
//    int course = atoi(number);

//    cout << course << endl;

//    char gender = line[36];

//    cout << gender << endl;

    return 0;
}
