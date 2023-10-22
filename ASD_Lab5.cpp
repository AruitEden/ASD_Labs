#include <iostream>
#include <string>




size_t division_hash(size_t key, size_t size);

size_t multiplication_hash(size_t key, size_t size, double factor = 0.61803398875);

size_t string_hash(const char* key, size_t size);





enum class Menu_commands
{
    DEFAULT = 0,
    CLEAR_CONSOLE = 'c',
    QUIT_PROGRAM = 'q',
    PRINT_HELP = 'h',

    DIVISION_HASH = 1,
    MULTIPLICATION_HASH = 2,
    STRING_HASH = 3
};

void Print_command_info();







int main()
{

    size_t num_key, table_size;
    std::string str_key;

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


        case Menu_commands::DIVISION_HASH:
            std::cout << "Enter key value: ";
            std::cin >> num_key;
            std::cout << "Enter table size: ";
            std::cin >> table_size;

            std::cout << "Hashing result: " << division_hash(num_key, table_size) << '\n';
            break;


        case Menu_commands::MULTIPLICATION_HASH:
            std::cout << "Enter key value: ";
            std::cin >> num_key;
            std::cout << "Enter table size: ";
            std::cin >> table_size;

            std::cout << "Hashing result: " << multiplication_hash(num_key, table_size) << '\n';
            break;


        case Menu_commands::STRING_HASH:
            std::cout << "Enter key value: ";
            std::getline(std::cin, str_key);
            std::cout << "Enter table size: ";
            std::cin >> table_size;

            std::cout << "Hashing result: " << string_hash(str_key.c_str(), table_size) << '\n';
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

        << "\'" << (char)Menu_commands::PRINT_HELP << "\' - print help\n"
        << "\'" << (char)Menu_commands::CLEAR_CONSOLE << "\' - clear console\n"
        << "\'" << (char)Menu_commands::QUIT_PROGRAM << "\' - quit program\n"

        << "\'" << (int)Menu_commands::DIVISION_HASH << "\' - division hash\n"
        << "\'" << (int)Menu_commands::MULTIPLICATION_HASH << "\' - multiplication hash\n"
        << "\'" << (int)Menu_commands::STRING_HASH << "\' - string hash\n"

        << "\n\n";

}



size_t division_hash(size_t key, size_t size)
{
    return key % size;
}

size_t multiplication_hash(size_t key, size_t size, double factor) 
{
    return double(size) * (double(key) * factor - int(double(key) * factor));
}

size_t string_hash(const char* key, size_t size)
{
    size_t key_length = strlen(key);

    size_t hash = 0;

    for (size_t i = 0, factor = 5; i < key_length; ++i, factor += 6)
    {
        hash += size_t(key[i]) * size_t(pow(factor, i));
    }

    return hash % size;
}
