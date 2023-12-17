#include <iostream>
#include "Binary_heap.h"



enum class Menu_commands
{

    DEFAULT = 0,
    CLEAR_CONSOLE = 'c',
    QUIT_PROGRAM = 'q',
    PRINT_HELP = 'h',

    ADD_KEY = '+',
    REMOVE_INDEX = '-',
    PRINT_HEAP = 'p',
    REMOVE_MIN = 'm',
    CREATE_FROM_ARRAY = 'a',

};



void Print_command_info();





int main()
{

    Binary_heap<int> heap(INT_MIN);
    int key;
    size_t index;

    int* arr = nullptr;
    size_t size;
    


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


        case Menu_commands::ADD_KEY:
            std::cout << "Enter key: ";
            std::cin >> key;
            heap.push(key);
            std::cout << "Heap:\n\n";
            heap.print_heap();
            break;


        case Menu_commands::REMOVE_INDEX:
            std::cout << "Enter index: ";
            std::cin >> index;
            heap.remove(index);
            std::cout << "Heap:\n\n";
            heap.print_heap();
            break;


        case Menu_commands::PRINT_HEAP:
            std::cout << "Heap:\n\n";
            heap.print_heap();
            break;


        case Menu_commands::REMOVE_MIN:
            std::cout << "Removed key: " << heap.pop_min() << '\n';
            std::cout << "Heap:\n\n";
            heap.print_heap();
            break;


        case Menu_commands::CREATE_FROM_ARRAY:
            std::cout << "Enter array size: ";
            std::cin >> size;
            delete arr;
            arr = new int[size];
            std::cout << "Enter array elements: ";
            for (size_t i = 0; i < size; i++)
            {
                std::cin >> arr[i];
            }
            heap.create_from_array(arr, size);
            std::cout << "Heap:\n\n";
            heap.print_heap();
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

        << "\'" << (char)Menu_commands::ADD_KEY << "\' - add key\n"
        << "\'" << (char)Menu_commands::REMOVE_INDEX << "\' - remove key\n"
        << "\'" << (char)Menu_commands::PRINT_HEAP << "\' - print heap\n"
        << "\'" << (char)Menu_commands::REMOVE_MIN << "\' - remove min\n"
        << "\'" << (char)Menu_commands::CREATE_FROM_ARRAY << "\' - create from array\n"

        << "\n\n";

}