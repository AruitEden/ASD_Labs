#include "Interface.h"


void PrintHelp()
{
	std::cout << "\t\t------�������------";
	std::cout << "\n������� A - ���� ������ �������� �������";
	std::cout << "\n������� P - ���� ������ ������� �������";
	std::cout << "\n������� V - ���� ������ ������� ����";
	std::cout << "\n������� S - ���� ������ �������� ������� ������ � ��������� ������� \n������� R - ���� ������ ��������� ����";
	std::cout << "\n������� C - ���� ������ �������� ���� ����";
	std::cout << "\n������� F - ���� ������ ������ ���� �� ����� ������� � ����� \n������� E - ���� ������ �������� ������ � ����������";

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

		std::cout << "������� ������� ������� ������ ��������: ";
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

		std::cout << "������� ������� ������� ������ �����: ";
		std::cin >> data;

		if (stack.search(data))
		{
			std::cout << "\n����� ������� ���� � �����\n";
		}
		else
		{
			std::cout << "\n������ �������� ��� � �����\n";
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
		std::cout << "�� ����� ���������� �������. ���������� ��� ���\n";
		break;
	}
}