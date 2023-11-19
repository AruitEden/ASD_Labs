#include <iostream>
#include "General_tree.h"



enum class Menu_commands
{

    DEFAULT = 0,
    CLEAR_CONSOLE = 'c',
    QUIT_PROGRAM = 'q',
    PRINT_HELP = 'h',

    INSERT = '+',
    REMOVE = '-',
    SEARCH = '?',

    PRE_SEARCH = '1',
    POST_SEARCH = '2',

    PRE_PRINT = '3',
    POST_PRINT = '4',

};

void Print_command_info();





int main()
{

    General_tree<int> tree;
    int value;
    bool result;

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


        case Menu_commands::INSERT:
            std::cout << "Enter value: ";
            std::cin >> value;
            tree.insert(value);
            break;


        case Menu_commands::REMOVE:
            std::cout << "Enter value: ";
            std::cin >> value;
            tree.remove(value);
            break;


        case Menu_commands::SEARCH:
            std::cout << "Enter value: ";
            std::cin >> value;
            result = tree.contains(value);
            std::cout << std::boolalpha << result << '\n';
            break;


        case Menu_commands::PRE_SEARCH:
            std::cout << "Enter value: ";
            std::cin >> value;
            result = tree.preorder_search(value);
            std::cout << std::boolalpha << result << '\n';
            break;


        case Menu_commands::POST_SEARCH:
            std::cout << "Enter value: ";
            std::cin >> value;
            result = tree.postorder_search(value);
            std::cout << std::boolalpha << result << '\n';
            break;


        case Menu_commands::PRE_PRINT:
            tree.preorder_print();
            break;

        case Menu_commands::POST_PRINT:
            tree.postorder_print();
            break;


        default:
            std::cout << "There is no such command.\n";
            break;

        }

        std::cout << "\n\n";

    }

    return 0;

}







void Print_command_info()
{

    std::cout << "Commands list:\n"

        << "\'" << (char)Menu_commands::PRINT_HELP << "\' - print help\n"
        << "\'" << (char)Menu_commands::CLEAR_CONSOLE << "\' - clear console\n"
        << "\'" << (char)Menu_commands::QUIT_PROGRAM << "\' - quit program\n"

        << "\'" << (char)Menu_commands::INSERT << "\' - insert\n"
        << "\'" << (char)Menu_commands::REMOVE << "\' - remove\n"
        << "\'" << (char)Menu_commands::SEARCH << "\' - search\n"

        << "\'" << (char)Menu_commands::PRE_SEARCH << "\' - preorder search\n"
        << "\'" << (char)Menu_commands::POST_SEARCH << "\' - postorder search\n"

        << "\'" << (char)Menu_commands::PRE_PRINT << "\' - preorder print\n"
        << "\'" << (char)Menu_commands::POST_PRINT << "\' - postorder print\n"

        << "\n\n";

}


