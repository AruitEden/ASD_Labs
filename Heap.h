#pragma once
#include <iostream>

class Heap
{
private:

	int* arr;
	int size;
	int capacity;


	void resize();


	void siftUp(int i);

	void siftDown(int i);


public:

	Heap():capacity(10), size(0), arr(new int[capacity]{})
	{
	}
	~Heap()
	{
		delete arr;
	}


	void push(int data)
	{
		if (size == capacity)
		{
			resize();
		}

		arr[size] = data;

		size++;


		siftUp(size - 1);
	}
	void pop();


	void print();
};

