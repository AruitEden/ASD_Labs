#include "Binary_heap.h"





template<class T>
void Binary_heap<T>::heap_printing(size_t index, int space_count, int spacing) const
{

	space_count += spacing;

	if (right(index) < size)
	{
		heap_printing(right(index), space_count);
	}

	for (int i = 0; i < space_count; i++)
	{
		std::cout << ' ';
	}
	std::cout << harr[index] << '\n';

	if (left(index) < size)
	{
		heap_printing(left(index), space_count);
	}

}



template<class T>
void Binary_heap<T>::push(const T& key)
{

	if (size == capacity)
	{

		capacity = (capacity + 1) * 2;

		T* new_harr = new T[capacity];

		for (size_t i = 0; i < size; i++)
		{
			new_harr[i] = harr[i];
		}

		delete harr;
		harr = new_harr;

	}

	harr[size] = key;

	for (size_t i = size++; i > 0 && harr[parent(i)] > harr[i]; i = parent(i))
	{
		swap(harr[i], harr[parent(i)]);
	}

}

template<class T>
void Binary_heap<T>::remove(size_t index)
{
	if (index < size)
	{
		dec_key(index, BH_T_MIN);
		pop_min();
	}
}

template<class T>
T Binary_heap<T>::pop_min()
{
	
	if (size == 0)
	{
		return T();
	}

	--size;

	if (size == 0)
	{
		return harr[0];
	}

	T root_element = harr[0];
	harr[0] = harr[size];
	heapify(0);

	return root_element;

}

template<class T>
void Binary_heap<T>::dec_key(size_t index, T new_value)
{

	harr[index] = new_value;
	
	while (index > 0 && harr[parent(index)] > harr[index])
	{
		swap(harr[index], harr[parent(index)]);
		index = parent(index);
	}

}



template<class T>
void Binary_heap<T>::heapify(size_t index)
{

	size_t l = left(index);
	size_t r = right(index);
	size_t lowest = index;

	if (l < size && harr[l] < harr[index])
	{
		lowest = l;
	}
	if (r < size && harr[r] < harr[lowest])
	{
		lowest = r;
	}

	if (lowest != index)
	{
		swap(harr[lowest], harr[index]);
		heapify(lowest);
	}

}

template<class T>
void Binary_heap<T>::create_from_array(const T* arr, size_t size)
{

	delete[] harr;
	this->capacity = this->size = size;
	harr = new T[size];

	for (size_t i = 0; i < size; i++)
	{
		harr[i] = arr[i];
	}

	for (size_t i = 0; i <= size / 2; i++)
	{
		heapify(size / 2 - i);
	}

}
