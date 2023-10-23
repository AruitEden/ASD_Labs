#include "Interface.h"


void PrintHelp()
{
	std::cout << "\t\t------�������------";
	std::cout << "\n������� D - ���-�����i� ������� �i�����";
	std::cout << "\n������� M - ���-�����i� ������� ��������";
	std::cout << "\n������� S - ���-�����i� ������� �������� ����i�";
	std::cout << "\n������� E - ���i� � ��������";

	std::cout << std::endl << std::endl;
}



void interface(char action, int(*h1)(int), int(*h2)(int), int(*h3)(std::string))
{
	int k;
	std::string K;

	switch (action)
	{

	case('D'):
	{
		system("cls");

		std::cout << "����i�� �������� ����: ";
		std::cin >> k;
		std::cout << "���-���: " << h1(k);


		std::cout << std::endl;
		PrintHelp();

		break;
	}

	case('M'):
	{
		system("cls");

		std::cout << "����i�� �������� ����: ";
		std::cin >> k;
		std::cout << "���-���: " << h2(k);

		std::cout << std::endl;

		PrintHelp();

		break;
	}

	case('S'):
	{
		system("cls");

		std::cout << "����i�� �������� ����: ";

		std::cin.ignore(1);
		getline(std::cin, K);
		std::cout << "���-���: " << h3(K);

		std::cout << std::endl;

		PrintHelp();

		break;
	}

	default:
		std::cout << "�� ����� ���i���� �������. ��������� �� ���\n";
		break;
	}
}