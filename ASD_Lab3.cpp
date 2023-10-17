#include <iostream>
#include"Stack.h"
#include"Interface.h"

int main()
{
    setlocale(LC_ALL, "ru");

    Stack<int> A;

    A.push(3);
    A.push(5);
    A.push(8);
    A.push(7);
    A.push(9);


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
