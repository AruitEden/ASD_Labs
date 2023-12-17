#include <iostream>
#include "Binary_heap.h"



int main()
{

    Binary_heap<int> heap1(INT_MIN);

    const int size = 10;
    int arr[size]{ 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
    heap1.create_from_array(arr, size);

    heap1.print_heap();

    std::cout << "\n---------------------------------\n\n";

    Binary_heap<int> heap2(INT_MIN);

    heap2.push(4);
    heap2.push(1);
    heap2.push(3);
    heap2.push(2);
    heap2.push(16);
    heap2.push(9);
    heap2.push(10);
    heap2.push(14);
    heap2.push(8);
    heap2.push(7);

    heap2.print_heap();



    return 0;

}


