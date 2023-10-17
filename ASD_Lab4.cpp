#include <iostream>
#include"Queue.h"

int main()
{
    Queue<int>A;

    A.push_back(3);
    A.push_back(7);
    A.push_back(10);

    A.Print_Queue();
    std::cout << std::endl << std::endl;

    A.pop_front();
    A.pop_front();

    A.Print_Queue();
    std::cout << std::endl << std::endl;

    A.push_back(4);
    A.push_back(90);
    A.push_back(18);

    A.Print_Queue();
    std::cout << std::endl << std::endl;

    std::cout << "Queue\n";
    A.clear();
    A.Print_Queue();
}
