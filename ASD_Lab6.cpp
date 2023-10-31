#include <iostream>
#include "Pair.h"
#include "Hash_table.h"
#include <string>







enum class Menu_commands
{

    DEFAULT = 0,
    CLEAR_CONSOLE = 'c',
    QUIT_PROGRAM = 'q',
    PRINT_HELP = 'h',

    INSERT_PAIR = '+',
    ERASE_KEY = '-',
    CONTAINS_KEY = '?',

    PRINT_PAIR = 'p',
    PRINT_SIZE_INFO = 'i',

};

void Print_command_info();



template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, const Pair<T1, T2>& pair);

template <typename T1, typename T2>
std::istream& operator>>(std::istream& in, Pair<T1, T2>& pair);





int main()
{

    size_t table_size;
    std::cout << "Enter table size, before starting to work: ";
    std::cin >> table_size;

    Hash_table<int, int> table(table_size);
    Pair<int, int> temp;


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


        case Menu_commands::INSERT_PAIR:
            std::cout << "Enter key and value: ";
            std::cin >> temp;
            table.insert(temp);
            break;


        case Menu_commands::ERASE_KEY:
            std::cout << "Enter key: ";
            std::cin >> temp.first;
            table.erase(temp.first);
            break;


        case Menu_commands::CONTAINS_KEY:
            std::cout << "Enter key: ";
            std::cin >> temp.first;
            std::cout << std::boolalpha << table.contains_key(temp.first) << '\n';
            break;


        case Menu_commands::PRINT_PAIR:
            std::cout << "Enter key: ";
            std::cin >> temp.first;
            std::cout << table[temp.first] << '\n';
            break;


        case Menu_commands::PRINT_SIZE_INFO:
            std::cout << "Table current size: " << table.size() << '\n'
                      << "Table max size: " << table.max_size() << '\n';
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

        << "\'" << (char)Menu_commands::INSERT_PAIR << "\' - insert pair\n"
        << "\'" << (char)Menu_commands::ERASE_KEY << "\' - delete pair by key\n"
        << "\'" << (char)Menu_commands::CONTAINS_KEY << "\' - contains pair with such key\n"

        << "\'" << (char)Menu_commands::PRINT_PAIR << "\' - print pair by key\n"
        << "\'" << (char)Menu_commands::PRINT_SIZE_INFO << "\' - print table size info\n"

        << "\n\n";

}



template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, const Pair<T1, T2>& pair)
{
    return out << pair.first << ' ' << pair.second;
}

template<typename T1, typename T2>
std::istream& operator>>(std::istream& in, Pair<T1, T2>& pair)
{
    return in >> pair.first >> pair.second;
}
