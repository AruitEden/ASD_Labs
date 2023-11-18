#include <iostream>
#include "Tree.h"

int main()
{
	Tree tree;

	tree.add(6);

	tree.add(4);
	tree.add(8);

	tree.add(2);
	tree.add(3);
	tree.add(5);
	tree.add(6);
	tree.add(7);

	tree.add(1);
	tree.add(4);
	tree.add(6);
	tree.add(6);

	tree.print();

	std::cout << "\n\n";



	tree.remove(8);

	tree.print();

	std::cout << "\n\n";

	if(tree.search(9))
	std::cout << "True";
	else 
	{
		std::cout << "False";
	}
}
