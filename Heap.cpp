#include "Heap.h"

void Heap::resize()
{
	capacity = capacity * 2;

	int* new_arr = new int[capacity];

	for (int i = 0; i < size; i++)
	{
		new_arr[i] = arr[i];
	}

	delete arr;

	arr = new_arr;
}

void Heap::siftUp(int i)
{
	while (i != 0 && arr[i] < arr[(i - 1) / 2])
	{
		int temp = arr[i];
		arr[i] = arr[(i - 1) / 2];
		arr[(i - 1) / 2] = temp;

		i = (i - 1) / 2;
	}
}

void Heap::siftDown(int i)
{
	while (2*i+1 < size)
	{
		int maxChild = 2 * i + 1;

		if (maxChild + 1 < size && arr[maxChild] > arr[maxChild + 1])
		{
			maxChild++;
		}

		if (arr[i] <= arr[maxChild])
		{
			break;
		}


		int temp = arr[i];
		arr[i] = arr[maxChild];
		arr[maxChild] = temp;

		i = maxChild;
	}
}



void Heap::pop()
{
	int* new_arr = new int[capacity];

	for (int i = 0; i < size - 1; i++)
	{
		if(i == 0)
		{
			new_arr[i] = arr[size];
		}
		else
		{
			new_arr[i] = arr[i];
		}		
	}

	size--;

	delete arr;

	arr = new_arr;

	siftDown(0);
}




void Heap::print()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
}
