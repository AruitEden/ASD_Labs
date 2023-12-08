#include <iostream>
#include "RB_tree.h"



int main()
{
    
    RB_tree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.print_tree();
    std::cout << "-------------------------\n\n";

    tree.insert(3);
    tree.print_tree();
    std::cout << "-------------------------\n\n";

    tree.insert(14);
    tree.print_tree();
    std::cout << "-------------------------\n\n";

    tree.insert(33);
    tree.print_tree();
    std::cout << "-------------------------\n\n";

    tree.insert(8);
    tree.print_tree();
    std::cout << "-------------------------\n\n";

    tree.insert(2);
    tree.print_tree();
    std::cout << "-------------------------\n\n";
    //RECOLOUR TEST




    tree.insert(1);
    tree.print_tree();
    std::cout << "-------------------------\n\n";


    tree.insert(11);
    tree.insert(6);
    tree.insert(9);
    tree.insert(7);

    tree.print_tree();

}


