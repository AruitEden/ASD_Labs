#include <iostream>
#include <string>
#include <fstream>





struct DateTime
{

    uint16_t    year;
    uint16_t    month;
    uint16_t    day;

    friend std::ostream& operator << (std::ostream& out, const DateTime& time);

};

enum class Gender
{
    Male = 0,
    Female = 1
};



class Employee 
{

private:


    std::string     m_first_name;
    std::string     m_second_name;
    std::string     m_middle_name;

    DateTime        m_birth_date;

    Gender          m_gender;


public:


    Employee(std::string first_name = "", std::string second_name = "", std::string middle_name = "",
        DateTime birth_date = DateTime{ 0, 0, 0 }, Gender gender = Gender::Male) :
        m_first_name(first_name), m_second_name(second_name), m_middle_name(middle_name),
        m_birth_date(birth_date), m_gender(gender) {}



    friend std::ostream& operator << (std::ostream& out, const Employee& emp);



    const std::string& Get_first_name() const
    {
        return m_first_name;
    }

    const std::string& Get_second_name() const
    {
        return m_second_name;
    }

    const std::string& Get_middle_name() const
    {
        return m_middle_name;
    }

};



void Sort_by_surname(Employee* employees, const uint32_t size);

bool Equal_surnames(const std::string& surname1, const std::string& surname2);

//Returns a sorted array of namesakes, if there aren't any in given array, returns nullptr
Employee* Find_namesakes(Employee* employees, const uint32_t size);





int main()
{

    const int STAFF_COUNT = 10;

    Employee staff[STAFF_COUNT]
    {
        Employee("Andriy", "Bulka", "Gennadiyovych", DateTime{1993, 3, 26}, Gender::Female),
        Employee("Bogdan", "Kuzmnenko", "Vasylovych", DateTime{2000, 11, 12}, Gender::Female),
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

}





std::ostream& operator<<(std::ostream& out, const DateTime& date_time)
{

    out << date_time.day << '.' << date_time.month << '.' << date_time.year;

    return out;

}



std::ostream& operator<<(std::ostream& out, const Employee& emp)
{

    out << "First name: "  << emp.m_first_name <<  "; " << "Second name: " << emp.m_second_name << "; "
        << "Middle name: " << emp.m_middle_name << "; " << "Born: "        << emp.m_birth_date <<  "; "
        << "Gender: "      << ((bool)emp.m_gender ? "Female" : "Male");

    return out;

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

        for(j; j > 0 && employees[j].Get_second_name() > temp.Get_second_name(); --j)
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

        if(surname1[i] != surname2[i])
        {
            return false;
        }

    }

    return true;

}

Employee* Find_namesakes(Employee* employees, const uint32_t size)
{

    if(size == 1)
    {
        return nullptr;
    }

    uint32_t new_size = 0;
    Employee** arr = new Employee*[size];

    Employee* temp = employees;
    for(int i = 1; i < size; ++i)
    {

        if (Equal_surnames(temp->Get_second_name(), employees[i].Get_second_name()))
        {
            
        }

        ++temp

    }

    return nullptr;

}