#include "Interface.h"


void PrintHelp()
{
	std::cout << "\t\t------�������------";
	std::cout << "\n������� A - ���� ������ �������� �������";
	std::cout << "\n������� P - ���� ������ ������� �������";
	std::cout << "\n������� V - ���� ������ ������� �������";
	std::cout << "\n������� S - ���� ������ �������� ������� ������ � ��������� ������� \n������� R - ���� ������ ��������� �������";
	std::cout << "\n������� C - ���� ������ �������� ���� �������";
	std::cout << "\n������� F - ���� ������ ������ ���� �� ����� ������� � ������� \n������� E - ���� ������ �������� ������ � ����������";

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

		std::cout << "������� ������� ������� ������ ��������: ";
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

		std::cout << "������� ������� ������� ������ �����: ";
		std::cin >> data;

		if (queue.search(data))
		{
			std::cout << "\n����� ������� ���� � �������\n";
		}
		else
		{
			std::cout << "\n������ �������� ��� � �������\n";
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
		std::cout << "�� ����� ���������� �������. ���������� ��� ���\n";
		break;
	}
}