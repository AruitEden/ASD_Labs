#include <iostream>
#include <string>
#include "Stack.h"






enum class Menu_commands
{
    DEFAULT = 0,
    CLEAR_CONSOLE = 'c',
    QUIT_PROGRAM = 'q',
    PRINT_HELP = 'h',

    PRINT_STACK = 'p',
    PUSH = '+',
    POP = '-',
    EXCHANGE = 'e',
    REVERSE = 'r',
    CONTAINS = '?',
    CLEAR = '/'
};

void Print_command_info();




template <typename T>
void Print_stack(Stack<T>& st);




int main()
{

    Stack<int> st;
    int value;

    char command;
    bool run = true;
    Print_command_info();

    while (run)
    {

        std::cout << "----- MAIN MENU -----\n" << "Enter command: ";
        if (std::cin.peek() == '\n')
        {
            std::cin.ignore(1);
        }
        std::cin >> command;

        switch ((Menu_commands)command)
        {

        case Menu_commands::CLEAR_CONSOLE:
            system("cls");
            break;


        case Menu_commands::PRINT_HELP:
            Print_command_info();
            break;


        case Menu_commands::QUIT_PROGRAM:
            run = false;
            break;


        case Menu_commands::PRINT_STACK:
            Print_stack(st);
            break;

            
        case Menu_commands::PUSH:
            std::cout << "Enter value: ";
            std::cin >> value;

            st.push(value);

            Print_stack(st);
            break;


        case Menu_commands::POP:
            st.pop();

            Print_stack(st);
            break;


        case Menu_commands::EXCHANGE:
            st.exchange();

            Print_stack(st);
            break;


        case Menu_commands::REVERSE:
            st.reverse();

            Print_stack(st);
            break;


        case Menu_commands::CONTAINS:
            std::cout << "Enter value: ";
            std::cin >> value;

            std::cout << std::boolalpha << st.contains(value) << '\n';
            break;


        case Menu_commands::CLEAR:
            st.clear();

            Print_stack(st);
            break;


        default:
            std::cout << "There is no such command.\n";
            break;

        }

    }

    return 0;

}







void Print_command_info() 
{

    std::cout << "Commands list:\n"

        << "\'" << (char)Menu_commands::PRINT_HELP        << "\' - print help\n"
        << "\'" << (char)Menu_commands::CLEAR_CONSOLE     << "\' - clear console\n"
        << "\'" << (char)Menu_commands::QUIT_PROGRAM      << "\' - quit program\n"

        << "\'" << (char)Menu_commands::PRINT_STACK << "\' - print stack\n"
        << "\'" << (char)Menu_commands::PUSH << "\' - push\n"
        << "\'" << (char)Menu_commands::POP << "\' - pop\n"
        << "\'" << (char)Menu_commands::EXCHANGE << "\' - exchange\n"
        << "\'" << (char)Menu_commands::REVERSE << "\' - reverse\n"
        << "\'" << (char)Menu_commands::CONTAINS << "\' - contains\n"
        << "\'" << (char)Menu_commands::CLEAR << "\' - clear stack\n"

             << "\n\n";

}





template <typename T>
void Print_stack(Stack<T>& st)
{
    std::cout << "Stack:\n";
    for (auto i : st)
    {
        std::cout << i << '\n';
    }
}