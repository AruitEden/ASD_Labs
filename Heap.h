#pragma once
#include <iostream>

class Heap
{
private:

	int capacity;
	int size;
	int* arr;


	void resize();


	void siftUp(int i);

	void siftDown(int i);


public:

	Heap():capacity(10), size(0), arr(new int[capacity])
	{
	}

	~Heap()
	{
		delete[] arr;
	}



	void push(int data)
	{
		if (size == capacity)
		{
			resize();
		}

		arr[size] = data;


		siftUp(size);

		size++;
	}

	void pop();



	void erase(int index);


	void print();
};

