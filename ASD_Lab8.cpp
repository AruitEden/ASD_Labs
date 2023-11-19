#include <iostream>
#include "General_tree.h"




int main()
{

    General_tree<int> tree;

    tree.insert(44);
    tree.insert(56);
    tree.insert(31);
    tree.insert(48);
    tree.insert(19);
    tree.insert(14);
    tree.insert(30);
    tree.insert(70);
    tree.insert(63);
    tree.insert(25);
    tree.insert(27);
    tree.insert(22);
    tree.insert(29);
    tree.insert(26);
    tree.insert(24);
    tree.insert(23);


    tree.remove(44);

    /*tree.remove(31);
    tree.remove(48);*/

    int a = 10;

}


