#include <iostream>
#include "Student.h"

void PrintArray(Student* arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        arr[i].Print();
        std::cout << std::endl;
    }
}



void Merg(Student* arr, int start, int end, int mid)
{
    Student ara[sizeof(arr)];
    int start1 = start;
    int start2 = start;
    int start_mid = mid + 1;

    while (start1 <= mid && start_mid <= end)
    {
        if (arr[start1].GetGPA() > arr[start_mid].GetGPA())
        {
            ara[start2] = arr[start1];
            start1++;
            start2++;
        }

        else
        {
            ara[start2] = arr[start_mid];
            start_mid++;
            start2++;
        }
    }


    while (start1 <= mid)
    {
        ara[start2] = arr[start1];
        start1++;
        start2++;
    }

    while (start_mid <= end)
    {
        ara[start2] = arr[start_mid];
        start_mid++;
        start2++;
    }

    for (int i = start; i < start_mid; ++i)
    {
        arr[i] = ara[i];
    }
}



void MergSort(Student* arr, int start, int end)
{
    int mid;

    if (start < end)
    {
        mid = (start + end) / 2;
        MergSort(arr, start, mid);
        MergSort(arr, mid + 1, end);
        Merg(arr, start, end, mid);
    }
}


int main()
{
    Student A("PZ-22-1", "Hanna", 7);
    Student B("PZ-22-2", "Oleg", 3);
    Student C("PZ-22-3", "Ruslan", 6);
    A.Print();
    std::cout << std::endl << std::endl;

    Student arr[3]{ A, B, C };
    PrintArray(arr, 3);

    std::cout << std::endl << std::endl;

    MergSort(arr, 0, 2);
    PrintArray(arr, 3);

}
