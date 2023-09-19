#pragma once
#include <iostream>







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



    friend std::ostream& operator << (std::ostream& out, const Employee& emp);

};





void Sort_by_surname(Employee* employees, const uint32_t size);

bool Equal_surnames(const std::string& surname1, const std::string& surname2);

//Returns a sorted array of namesakes, if there aren't any in given array, returns nullptr
Employee* Find_namesakes(const Employee const* employees, const uint32_t size, uint32_t& returned_size);
