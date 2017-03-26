#include <iostream>
#include <string>
#include <locale>
#include "group.h"

using namespace std;

int main()
{
    locale::global(locale("spanish"));
    cout << "Hello World!" << endl;

    Group grupo;

    return 0;
}
