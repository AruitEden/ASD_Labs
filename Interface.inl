#include "Interface.h"


void PrintHelp()
{
	std::cout << "\t\t------Команды------";
	std::cout << "\nВведите D - Хеш-функцiя методом дiлення";
	std::cout << "\nВведите M - Хеш-функцiя методом множення";
	std::cout << "\nВведите S - Хеш-функцiя методом рядкових ключiв";
	std::cout << "\nВведите E - Вихiд з програми";

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

		std::cout << "Введiть числовий ключ: ";
		std::cin >> k;
		std::cout << "Хеш-код: " << h1(k);


		std::cout << std::endl;
		PrintHelp();

		break;
	}

	case('M'):
	{
		system("cls");

		std::cout << "Введiть числовий ключ: ";
		std::cin >> k;
		std::cout << "Хеш-код: " << h2(k);

		std::cout << std::endl;

		PrintHelp();

		break;
	}

	case('S'):
	{
		system("cls");

		std::cout << "Введiть рядковий ключ: ";

		std::cin.ignore(1);
		getline(std::cin, K);
		std::cout << "Хеш-код: " << h3(K);

		std::cout << std::endl;

		PrintHelp();

		break;
	}

	default:
		std::cout << "Ви ввели невiдому команду. Спробуйте ще раз\n";
		break;
	}
}