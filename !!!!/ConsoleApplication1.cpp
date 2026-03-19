#include <iostream>
#include "library.h"

int main()
{
    system("chcp 1251");
    std::cout << "Hello World!\n";
    library lib;
    lib.AddFromConsole();
    lib.AddFromConsole();
    lib.AddFromConsole();

    lib.PrintAll();
}
