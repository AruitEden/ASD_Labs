#include <iostream>
#include "Treap.h"

int main()
{
    Treap treap;

    //treap.insert(1, 14);
    //treap.insert(3, 72);
    //treap.insert(2, 31);
    //treap.insert(6, 54);
    //treap.insert(5, 45);
    //treap.insert(7, 38);
    //treap.insert(4, 25);


    treap.insert(1, 14);
    treap.insert(2, 31);
    treap.insert(3, 72);   
    treap.insert(4, 25);
    treap.insert(5, 45);
    treap.insert(6, 54);
    treap.insert(7, 38);

    treap.insert(8, 41);
    treap.insert(9, 70);
    treap.insert(10, 24);
    treap.insert(11, 57);
    treap.insert(12, 35);
    treap.insert(13, 64);
    treap.insert(14, 11);

    treap.print_l();
    std::cout << "\n\n";


    std::cout << "-------------------------------------";


    treap.remove(12);
    treap.remove(13);
    treap.remove(3);

    treap.print_l();
    std::cout << "\n\n";
}
