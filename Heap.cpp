#include "Heap.h"


void Heap::resize()
{
	capacity = capacity * 2;

	int* new_arr = new int[capacity];

	for (int i = 0; i < size; i++)
	{
		new_arr[i] = arr[i];
	}

	delete[] arr;

	arr = new_arr;
}



void Heap::siftUp(int i)
{
	int parent = (i - 1) / 2;

	while (i != 0 && arr[i] < arr[parent])
	{
		int temp = arr[i];
		arr[i] = arr[parent];
		arr[parent] = temp;


		i = parent;
		parent = (i - 1) / 2;
	}
}

void Heap::siftDown(int i)
{
	while (2 * i + 1 < size)
	{
		int minChild = 2 * i + 1;

		if (minChild + 1 < size && arr[minChild] > arr[minChild + 1])
		{
			minChild++;
		}

		if (arr[i] <= arr[minChild])
		{
			break;
		}


		int temp = arr[i];
		arr[i] = arr[minChild];
		arr[minChild] = temp;

		i = minChild;
	}
}



void Heap::pop()
{
	if (size == 0)
	{
		return;
	}


	arr[0] = arr[size - 1];

	siftDown(0);

	size--;
}



void Heap::erase(int index)
{
	if (index > size - 1 || index < 0 || size == 0)
	{
		return;
	}

	if (index == size - 1)
	{
		size--;
	}
	else
	{
		arr[index] = arr[size - 1];

		siftUp(index);
		siftDown(index);

		size--;
	}
}

void Heap::print()
{
	for (int i = 0; i < size; i++)
	{
		int a = arr[i];
		std::cout << arr[i] << " ";
	}
}
