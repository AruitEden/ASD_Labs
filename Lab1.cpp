#include <iostream>
#include <string>
#include <fstream>
#include "Employee.h"





void Add_employee(Employee*& staff, uint32_t& size, const Employee& emp);

Employee Read_selected(std::fstream &fs, const uint32_t n);

void Print_employees(const Employee* const staff, const uint32_t size);

void Print_command_info();



enum Menu_commands
{
    DEFAULT = 0,
    PRINT_ARRAY = 'p',
    ADD_ELEMENT = 'a',
    CLEAR_CONSOLE = 'c',
    QUIT_PROGRAM = 'q',
    PRINT_NAMESAKES = 'n',
    SORT_ARRAY = 's',
    PRINT_HELP = 'h'
};





int main()
{

    std::fstream fs("Data_pool.csv");
    if (!fs) 
    {
        std::cerr << "Couldn't open the file\n";
        return -1;
    }


    uint32_t staff_size = 0;
    Employee* staff = new Employee[staff_size];

    uint32_t namesakes_size = 0;
    Employee* namesakes = new Employee[namesakes_size];
    

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

        case PRINT_ARRAY:
            std::cout << "----------- PRINT ARRAY -----------\n";

            Print_employees(staff, staff_size);

            std::cout << '\n';
            break;


        case ADD_ELEMENT:
            std::cout << "----------- ADD ELEMENT -----------\n";

            int n;
            std::cout << "Enter record number: ";
            std::cin >> n;
            Add_employee(staff, staff_size, Read_selected(fs, n));

            std::cout << "ADDED: " << staff[staff_size - 1] << "\n\n";
            break;


        case PRINT_NAMESAKES:
            std::cout << "----------- PRINT NAMESAKES -----------\n";

            delete[] namesakes;
            namesakes_size = 0;
            namesakes = Find_namesakes(staff, staff_size, namesakes_size);
            Print_employees(namesakes, namesakes_size);

            std::cout << '\n';
            break;


        case SORT_ARRAY:

            Sort_by_surname(staff, staff_size);

            std::cout << "----------- ARRAY SORTED -----------\n\n";
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





void Add_employee(Employee*& staff, uint32_t& size, const Employee& emp)
{

    Employee* new_staff = new Employee[size + 1];

    for (int i = 0; i < size; ++i)
    {
        new_staff[i] = staff[i];
    }

    new_staff[size] = emp;

    delete[] staff;

    ++size;

    staff = new_staff;

}

Employee Read_selected(std::fstream& fs, const uint32_t n)
{
    
    Employee t;

    for (size_t i = 0; i < n; ++i)
    {
        fs >> t;
    }

    fs.clear();
    fs.seekg(0, std::ios::beg);

    return t;

}

void Print_employees(const Employee* const staff, const uint32_t size)
{

    for (int i = 0; i < size; ++i)
    {
        std::cout << staff[i] << '\n';
    }

}

void Print_command_info() 
{
    std::cout << "Commands list:\n"
        << "\'p\' - print array\n"
        << "\'a\' - add element\n"
        << "\'c\' - clear console\n"
        << "\'q\' - quit program\n"
        << "\'n\' - print namesakes(works only if the array is sorted)\n"
        << "\'s\' - sort array\n"
        << "\'h\' - print help\n\n\n";

}