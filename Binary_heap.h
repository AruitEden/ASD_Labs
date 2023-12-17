#pragma once
#include <iostream>



template <typename T>
void swap(T& left, T& right)
{
	T temp = left;
	left = right;
	right = temp;
}





template <class T>
class Binary_heap
{

private:

	size_t capacity;
	size_t size;
	T* harr;



	void heap_printing(size_t index, int space_count, int spacing = 5) const;


public:

	const T BH_T_MIN;



	Binary_heap(T min) : capacity(0), size(0), harr(nullptr), BH_T_MIN(min) {}

	Binary_heap(size_t capacity, T min) : capacity(capacity), size(0), harr(new T[capacity]), BH_T_MIN(min) {}

	Binary_heap(const T* arr, size_t size, T min) : capacity(0), size(0), harr(nullptr), BH_T_MIN(min) {}

	~Binary_heap()
	{
		delete[] harr;
	}



	size_t parent(size_t i) const { return (i - 1) / 2; }

	size_t left(size_t i) const { return (2 * i + 1); }

	size_t right(size_t i) const { return (2 * i + 2); }



	void push(const T& key);

	void remove(size_t index);

	T pop_min();

	void dec_key(size_t index, T new_value);



	void heapify(size_t index);

	void create_from_array(const T* arr, size_t size);



	void print_heap() const
	{

		std::cout << "As array: ";
		for (size_t i = 0; i < size; i++)
		{
			std::cout << harr[i] << ' ';
		}

		std::cout << "\nAs tree:\n";
		heap_printing(0, 0);

	}

};



#include "Binary_heap.inl"