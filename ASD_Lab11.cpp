#include <iostream>
#include "RB_tree.h"
#include <vector>



int main()
{

//#define TESTS

#ifdef TESTS

    std::vector<int> vec{ 1, 3, 5, 7, 8 };

    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << "tree.insert(" << vec[i] << ");\n";
    }
    std::cout << "---------------------------\n";
    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << "tree.remove(" << vec[i] << ");\n";
    }

#endif





    RB_tree<int> tree;
    tree.insert(4);
    tree.insert(2);
    tree.insert(6);
    tree.insert(1);
    tree.insert(5);
    tree.insert(7);
    tree.insert(3);
    tree.insert(8);


    tree.remove(10);
    tree.remove(20);
    tree.remove(30);





    std::cout << "------- TREE -------\n";
    tree.print_tree();
    std::cout << "--------------------\n";

    std::cout << "inorder: ";
    tree.print_inorder();
    std::cout << '\n';

    std::cout << "preorder: ";
    tree.print_preorder();
    std::cout << '\n';

    std::cout << "postorder: ";
    tree.print_postorder();
    std::cout << '\n';




    /*
    RB_tree<int> tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.insert(7);


    tree.remove(5);
    tree.remove(10);
    tree.remove(1);


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
    tree.print_tree();
    std::cout << "-------------------------\n\n";
    tree.insert(6);
    tree.print_tree();
    std::cout << "-------------------------\n\n";
    tree.insert(9);
    tree.print_tree();
    std::cout << "-------------------------\n\n";
    tree.insert(7);
    tree.print_tree();
    std::cout << "-------------------------\n\n";
    tree.insert(4);
    tree.print_tree();
    std::cout << "-------------------------\n\n";



    tree.remove(10);
    tree.print_tree();
    std::cout << "-------------------------\n\n";

    tree.remove(11);
    tree.print_tree();
    std::cout << "-------------------------\n\n";

    tree.remove(14);
    tree.print_tree();
    std::cout << "-------------------------\n\n";

    tree.remove(8);
    tree.print_tree();
    std::cout << "-------------------------\n\n";

    tree.print_tree();
    */

}


