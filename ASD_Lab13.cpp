#include <iostream>
#include "Treap.h"
#include <random>



std::minstd_rand g_genegator;

unsigned int generate_random()
{
    return g_genegator();
}




int main()
{
    
    Treap<int, unsigned int> tr(generate_random);

    tr.insert(10);
    tr.insert(15);
    tr.insert(33);
    tr.insert(14);
    tr.insert(0);

    tr.print_tree();

    tr.erase(33);
    std::cout << "\n--------------------------------\n";

    tr.print_tree();

}


