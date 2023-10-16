#include "Looped_forward_list.h"

template<typename T>
inline Looped_forward_list<T>::Looped_forward_list()
{
	size = 0;
	head = nullptr;
	tail = nullptr;
}


template<typename T>
inline Looped_forward_list<T>::~Looped_forward_list()
{
	clear();
}





template<typename T>
inline void Looped_forward_list<T>::push_front(const T& data)
{
	head = new Node<T>(data, head);
	size++;
}


template<typename T>
inline void Looped_forward_list<T>::push_back(T data)
{
	Node<T> *node = new Node<T>(data);

	if (head == nullptr)
	{
		head = node;
		tail = node;
		tail->pNext = head;
	}
	else
	{
		node->pNext = head;
		tail->pNext = node;
		tail = node;
	}
	size++;
}


template<typename T>
inline void Looped_forward_list<T>::insert(const T& value, int index)
{
	if (index < 0 || index >= size)
	{
		std::cout << "Incorrect index\n";
		return;
	}

	if (index == 0)
	{
		push_front(value);
	}

	else
	{
		Node<T>* prev = head;

		for (int i = 0; i < index - 1; i++)
		{
			prev = prev->pNext;
		}

		Node<T>* newNode = new Node<T>(value, prev->pNext);

		prev->pNext = newNode;

		size++;
	}
}




template<typename T>
inline void Looped_forward_list<T>::pop_back()
{
	removeAt(size - 1);
}



template<typename T>
inline void Looped_forward_list<T>::pop_front()
{
	Node<T>* temp = head->pNext;
	delete head;
	head = temp;

	size--;
}


template<typename T>
inline void Looped_forward_list<T>::removeAt(int index)
{
	if (index < 0 || index >= size)
	{
		std::cout << "Incorrect index\n";
		return;
	}

	if (index == 0)
	{
		pop_front();
	}

	else
	{
		Node<T>* prev = head;

		for (int i = 0; i < index - 1; i++)
		{
			prev = prev->pNext;
		}

		Node<T>* toDelete = prev->pNext;
		prev->pNext = toDelete->pNext;

		delete toDelete;
		size--;
	}

}


template<typename T>
inline void Looped_forward_list<T>::removeEach(int n)
{
	if (n <= 0 || n > size)
	{
		std::cout << "Incorrect number\n";
		return;
	}

	if (n == 1) clear();

	else
	{
		int i = n - 1;

		while (!(size == 1))
		{
			if (i >= size)
			{
				i = i - size;
			}

			removeAt(i);
			i += n - 1;
		}
	}
}


template<typename T>
inline void Looped_forward_list<T>::clear()
{
	while (size!=0)
	{
		pop_front();
	}
}



template<typename T>
inline T& Looped_forward_list<T>::operator[](const int index)
{
	Node<T>* current = this->head;

	if (index >= size || index < 0)
	{
		throw "Incorrect index";
	}


	for (int i = 0; i < size; i++)
	{
		if (i == index)
		{
			return current->data;
		}
		current = current->pNext;
	}
}



int find_alive(int size, int n)
{
	if (size == 1) return 0;
	if (n == 1) return size - 1;

	if (n > size)
	{
		return (find_alive(size - 1, n) + n) % size;
	}

	int cut = size / n;
	int res = find_alive(size - cut, n);

	res -= size % n;

	if (res < 0)
	{
		res += size;
	}

	else
	{
		res += res / (n - 1);
	}

	return res;
}


template<typename T>
inline void Print_LoopedList(Looped_forward_list<T>& list)
{
	for (int i = 0; i < list.getSize(); i++)
	{
		std::cout << list[i] << "\n";
	}
}