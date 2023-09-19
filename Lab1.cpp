#include <iostream>
#include <string>
#include <fstream>
#include "Employee.h"





void Add_employee(Employee*& staff, uint32_t& size, const Employee& emp);

Employee Read_selected(std::fstream &fs, const uint32_t n);





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
    
    int n;

    while (true) 
    {

        std::cout << "Enter n: ";
        std::cin >> n;
        std::cin.ignore(1);

        Add_employee(staff, staff_size, Read_selected(fs, n));

        std::cout << "\n\n";

        for (size_t i = 0; i < staff_size; i++)
        {
            std::cout << staff[i] << '\n';
        }

        std::cout << "\n\n";

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