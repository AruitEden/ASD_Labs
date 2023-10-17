#include <iostream>
#include"Stack.h"

int main()
{
    Stack<int> A;

    A.push(3);
    A.push(5);
    A.push(8);
    A.push(7);
    A.push(9);

    A.Print_list();

    std::cout << std::endl << std::endl;

    A.revers();
    A.Print_list();

    std::cout << std::endl << std::endl;

    int a;

    std::cout << "Inpot data: ";
    std::cin >> a;
    std::cout << "Result: " << A.search(a);

    std::cout << std::endl << std::endl;

    std::cout << "Inpot data: ";
    std::cin >> a;
    std::cout << "Result: " << A.search(a);
    
}
