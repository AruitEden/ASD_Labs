#include "Interface.h"


void PrintHelp()
{
	std::cout << "\t\t------Команды------";
	std::cout << "\nВведите A - Если хотите добавить элемент";
	std::cout << "\nВведите P - Если хотите удалить элемент";
	std::cout << "\nВведите V - Если хотите вывести стек";
	std::cout << "\nВведите S - Если хотите поменять местами первый и последний элемент \nВведите R - Если хотите развернут стек";
	std::cout << "\nВведите C - Если хотите очистить весь стек";
	std::cout << "\nВведите F - Если хотите узнать есть ли такой элемент в стеке \nВведите E - Если хотите окончить работу с программой";

	std::cout << std::endl << std::endl;
}



template<typename T>
void interface(char action, Stack<T>& stack)
{
	T data;

	switch (action)
	{

	case('A'):
	{
		system("cls");

		std::cout << "Введите элемент который хотите добавить: ";
		std::cin >> data;
		stack.push(data);

		std::cout << std::endl;
		PrintHelp();

		break;
	}

	case('P'):
	{
		system("cls");

		stack.pop();

		PrintHelp();

		break;
	}

	case('S'):
	{
		system("cls");

		std::cout << "----STACK BEFORE----\n";
		stack.Print_stack();
		std::cout << std::endl << std::endl;

		stack.swap();

		std::cout << "----STACK AFTER----\n";
		stack.Print_stack();
		std::cout << std::endl << std::endl;

		PrintHelp();

		break;
	}

	case('R'):
	{
		system("cls");

		std::cout << "----STACK BEFORE----\n";
		stack.Print_stack();
		std::cout << std::endl << std::endl;

		stack.revers();

		std::cout << "----STACK AFTER----\n";
		stack.Print_stack();
		std::cout << std::endl << std::endl;

		PrintHelp();

		break;
	}

	case('F'):
	{
		system("cls");

		std::cout << "Введите элемент который хотите найти: ";
		std::cin >> data;

		if (stack.search(data))
		{
			std::cout << "\nТакой элемент есть в стеке\n";
		}
		else
		{
			std::cout << "\nТакого элемента нет в стеке\n";
		}

		std::cout << std::endl;
		PrintHelp();

		break;
	}

	case('C'):
	{
		system("cls");

		stack.clear();

		PrintHelp();

		break;
	}

	case('V'):
	{
		system("cls");

		std::cout << "----STACK----\n";
		stack.Print_stack();

		std::cout << std::endl;
		PrintHelp();

		break;
	}

	default:
		std::cout << "Вы ввели незвестную команду. Попробуйте ещё раз\n";
		break;
	}
}