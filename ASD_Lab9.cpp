#include <iostream>
#include "Tree.h"

#define HURT char(3)

void PrintHelp()
{
	std::cout << "\t\t------Команди------";
	std::cout << "\nВведiть A - Якщо бажаєте додати елемент";
	std::cout << "\nВведiть P - Якщо бажаєте видалить елемент";
	std::cout << "\nВведiть V - Якщо бажаєте вивести дерево";
	std::cout << "\nВведiть S - Якщо бажаєте знайти елемент\nВведiть E - Якщо бажаєте завершити работу з програмою";
	std::cout << std::endl << std::endl;
}


int main()
{
	Tree tree;

	//tree.add(26);

	//tree.add(12);
	//tree.add(37);

	//tree.add(10);
	//tree.add(20);
	//tree.add(29);
	//tree.add(44);

	//tree.add(8);
	//tree.add(15);
	//tree.add(19);
	//tree.add(38);
	//tree.add(47);


	int value;
	char action;


	PrintHelp();

	while (true)
	{
		std::cout << "\n\nВведiть операцiю: ";
		std::cin >> action;
		std::cout << std::endl;

		switch (action)
		{

		case('A'):
		{
			system("cls");

			std::cout << "Введiть значення: ";
			std::cin >> value;
			tree.add(value);

			std::cout << std::endl;
			std::cout << HURT << HURT << HURT << "----Tree----" << HURT << HURT << HURT << "\n";
			tree.print();

			std::cout << std::endl;
			PrintHelp();

			break;
		}

		case('P'):
		{
			system("cls");

			std::cout << "Введiть значення: ";
			std::cin >> value;

			tree.remove(value);

			std::cout << std::endl;
			std::cout << HURT << HURT << HURT << "----Tree----" << HURT << HURT << HURT << "\n";
			tree.print();

			std::cout << std::endl;
			PrintHelp();

			break;
		}

		case('S'):
		{
			system("cls");

			std::cout << "Введiть ключ елемента який бажаєте знайти: ";
			std::cin >> value;


			std::cout << std::endl;

			if (tree.search(value))
			{
				std::cout << "\nTrue";
			}

			else
			{
				std::cout << "\nFalse";
			}

			std::cout << std::endl << std::endl;
			PrintHelp();

			break;
		}

		case('V'):
		{
			system("cls");

			std::cout << HURT << HURT << HURT << "----Tree----" << HURT << HURT << HURT << "\n";
			tree.print();

			std::cout << std::endl;
			PrintHelp();

			break;
		}

		case('E'):
		{
			std::cout << "Гарного дня\n";
			return 0;
		}

		default:
		{
			std::cout << "Ви ввели невiдому команду. Спробуйте ще раз\n";
			break;
		}
		}
	}
}
