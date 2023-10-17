#include "Interface.h"


void PrintHelp()
{
	std::cout << "\t\t------Команды------";
	std::cout << "\nВведите A - Если хотите добавить элемент";
	std::cout << "\nВведите P - Если хотите удалить элемент";
	std::cout << "\nВведите V - Если хотите вывести очередь";
	std::cout << "\nВведите S - Если хотите поменять местами первый и последний элемент \nВведите R - Если хотите развернут очередь";
	std::cout << "\nВведите C - Если хотите очистить весю очередь";
	std::cout << "\nВведите F - Если хотите узнать есть ли такой элемент в очереди \nВведите E - Если хотите окончить работу с программой";

	std::cout << std::endl << std::endl;
}



template<typename T>
void interface(char action, Queue<T>& queue)
{
	T data;

	switch (action)
	{

	case('A'):
	{
		system("cls");

		std::cout << "Введите элемент который хотите добавить: ";
		std::cin >> data;
		queue.push(data);

		std::cout << std::endl;
		PrintHelp();

		break;
	}

	case('P'):
	{
		system("cls");

		queue.pop();

		PrintHelp();

		break;
	}

	case('S'):
	{
		system("cls");

		std::cout << "----QUEUE BEFORE----\n";
		queue.Print_Queue();
		std::cout << std::endl << std::endl;

		queue.swap();

		std::cout << "----QUEUE AFTER----\n";
		queue.Print_Queue();
		std::cout << std::endl << std::endl;

		PrintHelp();

		break;
	}

	case('R'):
	{
		system("cls");

		std::cout << "----QUEUE BEFORE----\n";
		queue.Print_Queue();
		std::cout << std::endl << std::endl;

		queue.revers();

		std::cout << "----QUEUE AFTER----\n";
		queue.Print_Queue();
		std::cout << std::endl << std::endl;

		PrintHelp();

		break;
	}

	case('F'):
	{
		system("cls");

		std::cout << "Введите элемент который хотите найти: ";
		std::cin >> data;

		if (queue.search(data))
		{
			std::cout << "\nТакой элемент есть в очереди\n";
		}
		else
		{
			std::cout << "\nТакого элемента нет в очереди\n";
		}

		std::cout << std::endl;
		PrintHelp();

		break;
	}

	case('C'):
	{
		system("cls");

		queue.clear();

		PrintHelp();

		break;
	}

	case('V'):
	{
		system("cls");

		std::cout << "----QUEUE----\n";
		queue.Print_Queue();

		std::cout << std::endl;
		PrintHelp();

		break;
	}

	default:
		std::cout << "Вы ввели незвестную команду. Попробуйте ещё раз\n";
		break;
	}
}