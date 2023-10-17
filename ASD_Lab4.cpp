#include <iostream>
#include <string>
#include "Forward_list.h"







enum class Menu_commands
{
    DEFAULT = 0,
    CLEAR_CONSOLE = 'c',
    QUIT_PROGRAM = 'q',
    PRINT_HELP = 'h'
};

void Print_command_info();







int main()
{

    

    return 0;

}







void Print_command_info() 
{

    std::cout << "Commands list:\n"

        << "\'" << (char)Menu_commands::PRINT_HELP        << "\' - print help\n"
        << "\'" << (char)Menu_commands::CLEAR_CONSOLE     << "\' - clear console\n"
        << "\'" << (char)Menu_commands::QUIT_PROGRAM      << "\' - quit program\n"

             << "\n\n";

}

