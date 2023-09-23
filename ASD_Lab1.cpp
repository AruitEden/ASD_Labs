﻿#include <iostream>
#include <string>
#include "Student.h"

void PrintArray(const Student* arr, const int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << std::endl;
    }
}


void PrintHelp()
{
    std::cout << "Введите A - Если вы хотите добавить элемент\nВведите S - Если хотите отсортировать массив\n";
    std::cout << "Введите R - Чтобы увидеть заданое количество лучших учеников (после этого массив будет отсортирован)\n";
    std::cout << "Введите P - Если хотите вывести массив\nВведите C - Если хотите очистить консоль\n";
    std::cout << "Введите E - Если хотите окончить работу с программой";
    std::cout << std::endl << std::endl;
}



void Range(const Student* arr, const int size, const int count)
{

    if (count > size)
    {
        std::cout << "Это больше чем количество элементов в массиве\n";
        return;
    }

    for (int i = 0; i < count; ++i)
    {
        std::cout << arr[i] << std::endl;
    }
}



void Merg(Student* arr, int start, int end, int mid)
{
    Student *ara = new Student[(end - start) + 1];
    int start1 = start;
    int start2 = 0;
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

    for (int i = start, j = 0; i < start_mid; ++i, ++j)
    {
        arr[i] = ara[j];
    }

    delete[] ara;
}



void MergSort(Student* arr, int start, int end)
{
   
    if (start < end)
    {
        int mid = (start + end) / 2;
        MergSort(arr, start, mid);
        MergSort(arr, mid + 1, end);
        Merg(arr, start, end, mid);
    }
}



void push_back(Student*& arr, int& size, int& capasity, const Student& value)
{
    if (size < capasity)
    {
        arr[size] = value;
        size++;
    }

    else
    {
        capasity = (capasity == 0) ? capasity += 3 : capasity *= 2;

        Student* NewArr = new Student[capasity];

        for (int i = 0; i < size; ++i)
        {
            NewArr[i] = arr[i];
        }

        NewArr[size] = value;
        size++;

        delete[] arr;

        arr = NewArr;
    }
}


int main()
{
    setlocale(LC_ALL, "ru");

    int capacity = 20;
    int size = 20;
    Student A("PZ-22-1", "Olga Petrova Andriivna", 70);
    Student B("PZ-22-2", "Gennady Komarov Ivanovych", 30);
    Student C("PZ-22-3", "Igor Zomich Oleksiyovych", 60);


    Student *arr = new Student [capacity]{ A, B, C, A, B, C , A, B, C , A, B, C, A, A, A, C, C, A, A, B};



    PrintHelp();



    char action;

    while (true)
    {
        std::cout << "\n\nВведите операцию: ";
        std::cin >> action;
        std::cout << std::endl;


        switch (action)
        {

        case('A'):
        {
            Student student;
            std::cout << "Ввндите данные о студенте через запятую (группа, ИФО, средний бал):\n";
            std::cin.ignore();
            std::cin >> student;

            push_back(arr, size, capacity, student);
            break;

        }

        case('S'):
        {
            MergSort(arr, 0, size - 1);
            break;
        }

        case('R'):
        {
            int count;
            std::cout << "Введитк количество лучших студентов которое хотите увидеть: ";
            std::cin >> count;

            MergSort(arr, 0, size - 1);
            Range(arr, size, count);
            break;
        }

        case('P'):
        {
            PrintArray(arr, size);
            break;

        }

        case('C'):
        {
            system("cls");
            PrintHelp();
            break;
        }

        case('E'):
        {
            std::cout << "Хорошего дня";
            return 0;
        }

        default:
            std::cout << "Вы ввели незвестную команду. Попробуйте ещё раз\n";
            break;
        }
    }


    delete[] arr;
}
