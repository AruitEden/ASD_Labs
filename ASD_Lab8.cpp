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

	if(tree.search(5))
	std::cout << "True";
	else 
	{
		std::cout << "False";
	}

	std::cout << "\n\n";

	tree.search1(8);



	std::cout << "\n\n";

	//tree.search2(5);
	if (tree.search2(9))
		std::cout << "\nTrue";
	else
	{
		std::cout << "\nFalse";
	}


	std::cout << "\n\n";



	if (tree.search3(6))
		std::cout << "\nTrue";
	else
	{
		std::cout << "\nFalse";
	}
}
