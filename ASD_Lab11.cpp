﻿#include <iostream>
#include "RB_tree.h"



int main()
{
    
    RB_tree<int> tree;
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

    tree.print_tree();

}


