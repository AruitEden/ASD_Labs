#include <iostream>
#include <string>
#include <fstream>
#include "Employee.h"







int main()
{

    const int STAFF_COUNT = 10;

    Employee staff[STAFF_COUNT]
    {
        Employee("Andriy", "Bulka", "Gennadiyovych", DateTime{1993, 3, 26}, Gender::Female),
        Employee("Bogdan", "Kuzmenko", "Vasylovych", DateTime{2000, 11, 12}, Gender::Female),
        Employee("Vasyl", "Gordienko", "Mykhailovych", DateTime{2001, 5, 12}, Gender::Female),
        Employee("Olga", "Petrova", "Andriivna", DateTime{2003, 4, 28}, Gender::Male),
        Employee("Natalia", "Kuzmenko", "Oleksiivna", DateTime{1994, 2, 14}, Gender::Male),
        Employee("Alexei", "Bushmanov", "Serhiyovych", DateTime{1992, 7, 22}, Gender::Female),
        Employee("Hanna", "Komarova", "Volodymyrivna", DateTime{1994, 10, 24}, Gender::Male),
        Employee("Artem", "Movchan", "Yehorovych", DateTime{1997, 5, 17}, Gender::Female),
        Employee("Gennady", "Komarov", "Ivanovych", DateTime{1998, 8, 4}, Gender::Female),
        Employee("Igor", "Zomich", "Oleksiyovych", DateTime{1995, 3, 18}, Gender::Female),
    };



    for (int i = 0; i < STAFF_COUNT; ++i) 
    {
        std::cout << staff[i] << '\n';
    }

    Sort_by_surname(staff, STAFF_COUNT);



    std::cout << "-------AFTER SORT-------\n\n";

    for (int i = 0; i < STAFF_COUNT; ++i)
    {
        std::cout << staff[i] << '\n';
    }



    std::cout << "-------NAMESAKES-------\n\n";

    uint32_t n_size = 0;

    Employee* namesakes = Find_namesakes(staff, STAFF_COUNT, n_size);

    for (int i = 0; i < n_size; ++i)
    {
        std::cout << namesakes[i] << '\n';
    }

    delete[] namesakes;



    return 0;

}







