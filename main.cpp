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

//    int instruction = 1;

//    while( instruction )
//    {
//        switch (instruction)

//    }

    Group grupo;

    Memory memoria;

    //memoria.save(grupo);

    grupo = memoria.load();

    grupo.childList();

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
