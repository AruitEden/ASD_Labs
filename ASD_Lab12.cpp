#include <iostream>
#include "Binary_heap.h"



int main()
{
    
    Binary_heap<int> heap(INT_MIN);

    heap.push(4);
    heap.push(1);
    heap.push(3);
    heap.push(2);
    heap.push(16);
    heap.push(9);
    heap.push(10);
    heap.push(14);
    heap.push(18);
    heap.push(7);

    heap.print_heap();

    return 0;

}


