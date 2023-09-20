#include <iostream>
#include "Student.h"

void PrintArray(Student* arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << std::endl;
    }
}


void Range(Student* arr, int size, int count)
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
   
    if (start < end)
    {
        int mid = (start + end) / 2;
        MergSort(arr, start, mid);
        MergSort(arr, mid + 1, end);
        Merg(arr, start, end, mid);
    }
}



void push_back(Student*& arr, int& size, const Student value)
{
    Student* NewArr = new Student[size + 1];

    for (int i = 0; i < size; ++i)
    {
        NewArr[i] = arr[i];
    }

    NewArr[size] = value;
    size++;

    delete[] arr;

    arr = NewArr;
}


int main()
{
    setlocale(LC_ALL, "ru");

    int n = 3;
    Student A("PZ-22-1", "Olga Petrova Andriivna", 70);
    Student B("PZ-22-2", "Gennady Komarov Ivanovych", 30);
    Student C("PZ-22-3", "Igor Zomich Oleksiyovych", 60);


    Student *arr = new Student [n]{ A, B, C };



    std::cout << "Введите A - если вы хотитк добавить элемент\nВведите S - если хотите отсортировать массив\n";
    std::cout << "Введите R - Что бы увдеть заданое колтсество лучших учинеков (после этого массив будет отсортирван)\n";
    std::cout << "Ввкдите P - если хотите вывести массив\nВведите E - если хотитк окончить работу с рограммой";


    std::cout << std::endl << std::endl;

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

            push_back(arr, n, student);
            break;

        }

        case('S'):
        {
            MergSort(arr, 0, n - 1);
            break;
        }

        case('R'):
        {
            int count;
            std::cout << "Введитк количество лучших студентов которое хотите увидеть: ";
            std::cin >> count;

            MergSort(arr, 0, n - 1);
            Range(arr, n, count);
            break;
        }

        case('P'):
        {
            PrintArray(arr, n);
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
