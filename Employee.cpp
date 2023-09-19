#include "Employee.h"







std::ostream& operator<<(std::ostream& out, const DateTime& date_time)
{

    out << date_time.day << '.' << date_time.month << '.' << date_time.year;

    return out;

}



std::ostream& operator<<(std::ostream& out, const Employee& emp)
{

    out << "First name: " << emp.m_first_name << "; " << "Second name: " << emp.m_second_name << "; "
        << "Middle name: " << emp.m_middle_name << "; " << "Born: " << emp.m_birth_date << "; "
        << "Gender: " << ((bool)emp.m_gender ? "Female" : "Male");

    return out;

}

std::istream& operator>>(std::istream& in, Employee& emp)
{

    std::getline(in, emp.m_first_name, CSV_FILE_DELIM);
    std::getline(in, emp.m_second_name, CSV_FILE_DELIM);
    std::getline(in, emp.m_middle_name, CSV_FILE_DELIM);

    std::string t;

    std::getline(in, t, '.');
    emp.m_birth_date.day = std::stoi(t);
    std::getline(in, t, '.');
    emp.m_birth_date.month = std::stoi(t);
    std::getline(in, t, CSV_FILE_DELIM);
    emp.m_birth_date.year = std::stoi(t);

    std::getline(in, t, '\n');
    emp.m_gender = (t == "Male") ? Gender::Male : Gender::Female;

    return in;

}



//Using insert sort here
void Sort_by_surname(Employee* employees, const uint32_t size)
{

    if (size == 1)
    {
        return;
    }

    for (int i = 1; i < size; ++i)
    {

        Employee temp = employees[i];

        int j = i - 1;

        for (j; j > 0 && employees[j].Get_second_name() > temp.Get_second_name(); --j)
        {

            employees[j + 1] = employees[j];

        }

        employees[j + 1] = temp;

    }

}



bool Equal_surnames(const std::string& surname1, const std::string& surname2)
{

    int size1 = surname1.size(), size2 = surname2.size();

    int min_size = size1 > size2 ? size2 - 1 : size1 - 1;

    for (int i = 0; i < min_size; ++i)
    {

        if (surname1[i] != surname2[i])
        {
            return false;
        }

    }

    return true;

}



Employee* Find_namesakes(const Employee* const employees, const uint32_t size, uint32_t& returned_size)
{

    returned_size = 0;

    if (size == 1)
    {
        return nullptr;
    }


    const Employee** arr = new const Employee * [size];

    bool equality = false;
    for (int i = 1; i < size; ++i)
    {

        if (Equal_surnames(employees[i - 1].Get_second_name(), employees[i].Get_second_name()))
        {

            arr[returned_size] = &employees[i - 1];
            ++returned_size;
            equality = true;

        }
        else if (equality)
        {

            arr[returned_size] = &employees[i - 1];
            ++returned_size;
            equality = false;

        }

    }


    if (returned_size == 0)
    {
        delete[] arr;
        return nullptr;
    }


    Employee* new_arr = new Employee[returned_size];

    for (int i = 0; i < returned_size; ++i)
    {
        new_arr[i] = *(arr[i]);
    }

    delete[] arr;
    return new_arr;

}