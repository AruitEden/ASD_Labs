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
}
