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

    h.print();
    std::cout << "\n\n";
}
