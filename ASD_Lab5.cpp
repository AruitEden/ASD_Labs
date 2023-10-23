#include <iostream>
#include"Interface.h"
#include<string>
#include<cmath>

int HashFunction_Division(int k)
{
    int N = 13;
    return(k % N);
}

int HashFunction_Multiplication(int k)
{
    int N = 13;
    double A = 0.618033;
    int H = N * fmod(k * A, 1);
    return H;
}

int HashFunction_String(std::string k)
{
    int a = 26;
    int N = 13;
    int H = k[0];

    for (int i = 1; i < k.length(); i++)
    {
        H += k[i] * pow(a, i);
    }

    H = H % N;
    return H;
}

int main()
{
    setlocale(LC_ALL, "ru");

    char action;
    PrintHelp();

    while (true)
    {
        std::cout << "\n\nВведiть операцiю: ";
        std::cin >> action;
        std::cout << std::endl;

        if (action == 'E')
        {
            std::cout << "Гарного дня\n";
            return 0;
        }

        interface(action, HashFunction_Division, HashFunction_Multiplication, HashFunction_String);
    }
}
