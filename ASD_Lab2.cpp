#include <iostream>
#include"Warrior.h"
#include "Forward_list.h"
#include "Looped_forward_list.h"


void PrintHelp()
{
    std::cout << "\t\t------Команды------";
    std::cout << "\n\n\t------Список 1------";
    std::cout << "\nВведите A - Если вы хотите добавить элемент в начало списка";
    std::cout << "\nВведите I - Если вы хотите добавить элемент в после n - го элемента";
    std::cout << "\nВведите R - Если вы хотите переместить элемент списка \nВведите V - Если вы хотите вывести список";
    std::cout << "\nВведите P - Если хотите удалить n-ый элемента \nВведите D - Если хотите удалить каждый n-ый элемент списка";
    std::cout << "\nВведите S - Если хотите отсортировать список \nВведите О - Если хотите создать копию списка";
    std::cout << "\nВведите C - Если хотите очистить весь список \nВведите U - Если хотите склеить два списка";
    std::cout << "\nВведите L - Если хотите создать список совместных элементов списков \nВведите E - Если хотите окончить работу с программой";
    std::cout << "\n\n\t------Список 2------";
    std::cout << "\nВведите a - Если вы хотите добавить элемент в конец второго списка \nВведите v - Если вы хотите вывести второй список";

    std::cout << std::endl << std::endl;
}

template<typename T>
bool isSorted(const T& a, const T& b, SortOrder sortorder)
{
    if (sortorder == INCREASE)
    {
        return a <= b;
    }
    else
    {
        return a >= b;
    }
}

int main()
{
    setlocale(LC_ALL, "ru");

    Warrior A("Olga", 70);
    Warrior B("Genna", 30);
    Warrior C("Igor", 60);
    Warrior D("Egor", 78);
    Warrior E("Liza", 100);


    Forward_list<Warrior> list1;
    list1.push_back(A);
    list1.push_back(B);
    list1.push_back(C);
    list1.push_back(D);


    Forward_list<Warrior> list2;
    list2.push_back(A);
    list2.push_back(B);
    list2.push_back(E);


    char action;
    int prev = 0;
    int sortorder;
    int index;
    bool vector;
    Warrior warrior;



    PrintHelp();

    while (true)
    {
        std::cout << "\n\nВведите операцию: ";
        std::cin >> action;
        std::cout << std::endl;


        switch (action)
        {

        case('A'):
        {
            system("cls");

            std::cout << "Ввндите данные о войне через запятую (Имя, сила):\n";
            std::cin.ignore();
            std::cin >> warrior;

            list1.push_front(warrior);

            std::cout << std::endl << std::endl;
            PrintHelp();

            break;
        }
        case('a'):
        {
            system("cls");

            std::cout << "Ввндите данные о войне через запятую (Имя, сила):\n";
            std::cin.ignore();
            std::cin >> warrior;

            list2.push_back(warrior);

            std::cout << std::endl << std::endl;
            PrintHelp();

            break;
        }
        case('I'):
        {
            system("cls");

            std::cout << "LIST\n";
            Print_list(list1);
            std::cout << std::endl << std::endl;

            std::cout << "Ввндите данные о войне через запятую (Имя, сила):\n";
            std::cin.ignore();
            std::cin >> warrior;

            std::cout << std::endl;

            
            std::cout << "Ввндите номер элемента после которого хотите вставить свой: ";
            std::cin >> index;

            list1.insert(warrior, index);

            std::cout << std::endl << std::endl;
            PrintHelp();

            break;
        }
        case('R'):
        {
            system("cls");

            std::cout << "LIST\n";
            Print_list(list1);
            std::cout << std::endl << std::endl;
            
            std::cout << "Введите номер элемента который хотите сместить: ";
            std::cin >> prev;

            std::cout << std::endl;

            std::cout << "Введите количество позиций на которую хотите сместить элемент: ";
            std::cin >> index;

            std::cout << std::endl;

            
            std::cout << "Введите вектор перемещения элемента(0 - назад, 1 - вперед): ";
            std::cin >> vector;


            list1.movePos(prev, index, vector);

            std::cout << std::endl << std::endl;
            PrintHelp();

            break;
        }
        case('V'):
        {
            system("cls");

            std::cout << "LIST\n";
            Print_list(list1);

            std::cout << std::endl << std::endl;
            PrintHelp();
            break;
        }
        case('v'):
        {
            system("cls");

            std::cout << "LIST 2\n";
            Print_list(list2);

            std::cout << std::endl << std::endl;
            PrintHelp();
            break;
        }
        case('P'):
        {
            system("cls");

            std::cout << "LIST\n";
            Print_list(list1);

            std::cout << "Введите номер элемента который хотите удалить: ";
            std::cin >> prev;

            list1.removeAt(prev);

            PrintHelp();
            break;
        }
        case('D'):
        {
            system("cls");

            std::cout << "LIST\n";
            Print_list(list1);

            std::cout << "Введите шаг с которым будут удаляться элементы: ";
            std::cin >> prev;

            list1.removeEach(prev);

            std::cout << "LIST\n";
            Print_list(list1);

            PrintHelp();
            break;
        }
        case('S'):
        {
            system("cls");

            std::cout << "LIST\n";
            Print_list(list1);

            std::cout << "Введите как будет сортироваться список (0 - возростанию или 1 - убыванию): ";
            std::cin >> sortorder;

            list1.sort(SortOrder(sortorder));

            std::cout << "LIST\n";
            Print_list(list1);

            PrintHelp();
            break;
        }

        case('O'):
        {
            system("cls");

            Forward_list<Warrior> list_copy(list1);

            std::cout << "LIST\n";
            Print_list(list1);
            std::cout << "\n\n";

            std::cout << "COPY LIST\n";
            Print_list(list_copy);
            std::cout << "\n\n";

            PrintHelp();
            break;
        }
        case('C'):
        {
            system("cls");

            list1.clear();

            PrintHelp();
            break;
        }

        case('U'):
        {
            system("cls");

            std::cout << "LIST\n";
            Print_list(list1);
            std::cout << "\n\n";


            std::cout << "LIST2\n";
            Print_list(list2);
            std::cout << "\n\n";


            list1.connectList(list2);

            std::cout << "MERG LIST\n";
            Print_list(list1);
            std::cout << "\n\n";

            PrintHelp();
            break;
        }
        case('L'):
        {
            system("cls");

            Forward_list<Warrior> list_copy;

            repeatList(list1, list2, list_copy);

            std::cout << "LIST\n";
            Print_list(list1);
            std::cout << "\n\n";


            std::cout << "LIST2\n";
            Print_list(list2);
            std::cout << "\n\n";


            std::cout << "LIST COPY\n";
            Print_list(list_copy);
            std::cout << "\n\n";

            PrintHelp();
            break;
        }
        case('E'):
        {
            std::cout << "Хорошего дня";
            return 0;
        }

        default:
        {
            std::cout << "Вы ввели незвестную команду. Попробуйте ещё раз\n";
            break;
        }
        }
    }

}
