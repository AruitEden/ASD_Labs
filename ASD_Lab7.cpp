#include <iostream>
#include "Hash_Table.h"

void PrintHelp()
{
	std::cout << "\t\t------Команди------";
	std::cout << "\nВведiть A - Якщо бажаєте додати елемент";
	std::cout << "\nВведiть P - Якщо бажаєте видалить елемент";
	std::cout << "\nВведiть V - Якщо бажаєте вивести таблицю";
	std::cout << "\nВведiть S - Якщо бажаєте знайти елемент\nВведіть E - Якщо бажаєте завершити работу з програмою";
	std::cout << std::endl << std::endl;
}


template<typename Value>
void Show(const Hash_Table<Value>& table, const int& key)
{
	try
	{
		std::cout << key << ": " << table.search(key) << "\n\n";
	}

	catch (const std::out_of_range& exc)
	{
		std::cout << exc.what() << "\n\n";
	}
}



int main()
{
	setlocale(LC_ALL, "ru");

	int key, value, size;
	char action;

	std::cout << "Введiть розмiр таблицi: ";
	std::cin >> size;
	std::cout << std::endl;

	Hash_Table<int> table(size);


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

			std::cout << "Введiть ключ: ";
			std::cin >> key;

			std::cout << "Введiть значення: ";
			std::cin >> value;
			table.insert(key, value);

			std::cout << std::endl;
			std::cout << "----Table----\n";
			table.print();

			std::cout << std::endl;
			PrintHelp();

			break;
		}

		case('P'):
		{
			system("cls");

			std::cout << "Введiть ключ: ";
			std::cin >> key;

			table.remove(key);

			std::cout << std::endl;
			std::cout << "----Table----\n";
			table.print();

			std::cout << std::endl;
			PrintHelp();

			break;
		}

		case('S'):
		{
			system("cls");

			std::cout << "Введiть ключ елемента який бажаєте знайти: ";
			std::cin >> key;

			Show<int>(table, key);

			std::cout << std::endl;
			PrintHelp();

			break;
		}

		case('V'):
		{
			system("cls");

			std::cout << "----Table----\n";
			table.print();

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




