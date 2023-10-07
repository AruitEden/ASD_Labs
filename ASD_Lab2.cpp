#include <iostream>
#include <string>
#include "Forward_list.h"






enum Menu_commands
{
    DEFAULT = 0,
    PRINT_COLLECTION = 'p',
    ADD_ELEMENT = 'a',
    CLEAR_CONSOLE = 'c',
    QUIT_PROGRAM = 'q',
    SORT_COLLECTION = 's',
    PRINT_HELP = 'h'
};

void Print_command_info();







int main()
{

    /*Iterator<int, Forward_list<int>> it;

    it.Foo();*/

    B<int> b;
    b.Foo();

    return 0;

}







void Print_command_info() 
{

    std::cout << "Commands list:\n"

        << "\'" << Menu_commands::PRINT_HELP        << "\' - print help\n"
        << "\'" << Menu_commands::CLEAR_CONSOLE     << "\' - clear console\n"
        << "\'" << Menu_commands::QUIT_PROGRAM      << "\' - quit program\n"
        << "\'" << Menu_commands::PRINT_COLLECTION  << "\' - print collection\n"
        << "\'" << Menu_commands::ADD_ELEMENT       << "\' - add element\n"
        << "\'" << Menu_commands::SORT_COLLECTION   << "\' - sort array\n"

             << "\n\n";

}

