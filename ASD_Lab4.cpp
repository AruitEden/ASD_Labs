#include <iostream>
#include"Interface.h"
#include"Queue.h"

int main()
{
    setlocale(LC_ALL, "ru");

    Queue<int>A;

    A.push(3);
    A.push(7);
    A.push(10);
    A.push(18);
    A.push(19);

    char action;
    PrintHelp();

    while (true)
    {
        std::cout << "\n\nВведите операцию: ";
        std::cin >> action;
        std::cout << std::endl;

        if (action == 'E')
        {
            std::cout << "Хорошего дня\n";
            return 0;
        }

        interface(action, A);
    }
}
