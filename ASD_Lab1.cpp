#include <iostream>
#include "Student.h"

void PrintArray(Student* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i].Print();
        std::cout << std::endl;
    }
}


int main()
{
    Student A("PZ-22-1", "Hanna", 3);
    Student B("PZ-22-2", "Oleg", 6);
    Student C("PZ-22-3", "Ruslan", 7);
    A.Print();
    std::cout << std::endl << std::endl;

    Student arr[3]{ A, B, C };
    PrintArray(arr, 3);
}
