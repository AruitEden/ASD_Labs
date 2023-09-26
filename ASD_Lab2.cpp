#include <iostream>
#include <string>







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

    char command;
    bool run = true;
    Print_command_info();

    while (run)
    {

        std::cout << "Enter command: ";
        if (std::cin.peek() == '\n') 
        {
            std::cin.ignore(1);
        }
        std::cin >> command;

        switch ((Menu_commands)command)
        {


        case PRINT_COLLECTION:
            std::cout << "----------- PRINT COLLECTION -----------\n";

            //...

            std::cout << '\n';
            break;



        case ADD_ELEMENT:
            std::cout << "----------- ADD ELEMENT -----------\n";

            //...

            //std::cout << "ADDED: " << ... << "\n\n";
            break;



        case SORT_COLLECTION:

            //...

            std::cout << "----------- COLLECTION SORTED -----------\n\n";
            break;



        case CLEAR_CONSOLE:
            system("cls");
            break;


        case PRINT_HELP:
            Print_command_info();
            break;


        case QUIT_PROGRAM:
            run = false;
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

        << "\'" << Menu_commands::PRINT_HELP        << "\' - print help\n"
        << "\'" << Menu_commands::CLEAR_CONSOLE     << "\' - clear console\n"
        << "\'" << Menu_commands::QUIT_PROGRAM      << "\' - quit program\n"
        << "\'" << Menu_commands::PRINT_COLLECTION  << "\' - print collection\n"
        << "\'" << Menu_commands::ADD_ELEMENT       << "\' - add element\n"
        << "\'" << Menu_commands::SORT_COLLECTION   << "\' - sort array\n"

             << "\n\n";

}

