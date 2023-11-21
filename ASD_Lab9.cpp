#include <iostream>
#include "Tree.h"





enum class Menu_commands
{

    DEFAULT = 0,
    CLEAR_CONSOLE = 'c',
    QUIT_PROGRAM = 'q',
    PRINT_HELP = 'h',

    INSERT = '+',
    REMOVE = '-',
    SEARCH = '?',

    PRINT_PREORDER = '1',
    PRINT_POSTORDER = '2',
    PRINT_INORDER = '3',

};



void Print_command_info();





int main()
{

    Tree<int> tree;
    int key;

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
            std::cout << "Enter key: ";
            std::cin >> key;
            tree.insert(key);
            break;


        case Menu_commands::REMOVE:
            std::cout << "Enter key: ";
            std::cin >> key;
            tree.remove(key);
            break;


        case Menu_commands::SEARCH:
            std::cout << "Enter key: ";
            std::cin >> key;
            std::cout << std::boolalpha << (tree.search(key) != nullptr) << '\n';
            break;


        case Menu_commands::PRINT_PREORDER:
            std::cout << "Preorder travesal:\n";
            tree.print_preorder();
            std::cout << '\n';
            break;


        case Menu_commands::PRINT_POSTORDER:
            std::cout << "Postorder travesal:\n";
            tree.print_postorder();
            std::cout << '\n';
            break;


        case Menu_commands::PRINT_INORDER:
            std::cout << "Inorder travesal:\n";
            tree.print_inorder();
            std::cout << '\n';
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

        << "\'" << (char)Menu_commands::PRINT_PREORDER << "\' - print preorder travesal\n"
        << "\'" << (char)Menu_commands::PRINT_POSTORDER << "\' - print postorder travesal\n"
        << "\'" << (char)Menu_commands::PRINT_INORDER << "\' - print inorder travesal\n"

        << "\n\n";

}


