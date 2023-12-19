#include <iostream>
#include "Heap.h"

int main()
{
    Heap h;

    h.push(31);
    h.push(17);
    h.push(42);
    h.push(55);
    h.push(24);

    h.push(22);
    h.push(99);
    h.push(44);
    h.push(38);
    h.push(11);

    h.push(9);

    h.print();
    std::cout << "\n\n";

    //h.pop();

    h.erase(1);

    h.print();
    std::cout << "\n\n";

}
