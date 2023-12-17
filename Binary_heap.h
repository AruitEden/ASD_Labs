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



	void print_spaces(int space_count)
	{
		for (int i = 0; i < space_count; i++)
		{
			std::cout << ' ';
		}
	}

	void heap_printing(int space_count)
	{

		for (size_t i = 0; i < size; i++)
		{
			std::cout << harr[i] << ' ';
		}

		std::cout << '\n';


		
		print_spaces(space_count * size / 2);
		std::cout << harr[0] << '\n';

		for (int i = 0; i < log2(size); i++)
		{

			print_spaces(space_count * size / ((i + 1) * 4));

			for (int j = i; j < i * 2 + 1; j++)
			{

				if (left(j) < size)
				{
					std::cout << harr[left(j)];
				}

				print_spaces(space_count * size / 2 / (i + 1));

				if (right(j) < size)
				{
					std::cout << harr[right(j)];
				}
				
			}

			std::cout << '\n';

		}

	}


public:

	const T BH_T_MIN;

	Binary_heap(T min) : capacity(0), size(0), harr(nullptr), BH_T_MIN(min) {}

	Binary_heap(size_t capacity, T min) : capacity(capacity), size(0), harr(new T[capacity]), BH_T_MIN(min) {}

	Binary_heap(const T* arr, size_t size, T min) : capacity(0), size(0), harr(nullptr), BH_T_MIN(min) {}

	~Binary_heap()
	{
		delete[] harr;
	}



	size_t parent(size_t i) { return (i - 1) / 2; }

	size_t left(size_t i) { return (2 * i + 1); }

	size_t right(size_t i) { return (2 * i + 2); }



	void push(const T& key);

	void remove(size_t index);

	T pop_min();

	void dec_key(size_t index, T new_value);



	void heapify(size_t index);

	void create_from_array(const T* arr, size_t size);



	void print_heap()
	{
		heap_printing(size * 7);
	}

};



#include "Binary_heap.inl"