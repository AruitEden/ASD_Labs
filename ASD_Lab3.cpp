#include <iostream>
#include"Stack.h"

int main()
{
    Stack<int> A;

    A.push(3);
    A.push(5);
    A.push(8);

    A.Print_list();

    std::cout << std::endl << std::endl;

    A.swap();
    A.Print_list();
}
