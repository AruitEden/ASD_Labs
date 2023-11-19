#include <iostream>
#include "General_tree.h"




int main()
{
    std::cout << "Hello World!\n";

    General_tree<int> tree;

    tree.insert(5);
    tree.insert(10);

    tree.insert(7);
    tree.insert(1);
    tree.insert(-1);
    tree.insert(2);


}


