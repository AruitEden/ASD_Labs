#include <iostream>
#include "Tree.h"



int main()
{
    
    Tree<int> tree;

    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(14);
    tree.insert(33);
    tree.insert(8);
    tree.insert(-2);
    tree.insert(11);
    tree.insert(6);
    tree.insert(9);
    tree.insert(7);

    tree.print_in();
    std::cout << '\n';

    tree.remove(9);

    tree.print_in();
    std::cout << '\n';


}


