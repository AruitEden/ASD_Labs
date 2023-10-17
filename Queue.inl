#include "Queue.h"

template<typename T>
inline Queue<T>::Queue()
{
	size = 0;
	head = nullptr;
	tail = nullptr;
}

template<typename T>
inline Queue<T>::~Queue()
{
	clear();
}






template<typename T>
inline void Queue<T>::push(T data)
{
	Node<T> *node = new Node<T>(data);

	if (head == nullptr)
	{
		head = tail = node;
	}
	else
	{
		
		tail = tail->pNext = node;
	}
	size++;
}




template<typename T>
inline void Queue<T>::pop()
{
	if (size == 0) return;

	Node<T>* temp = head->pNext;
	delete head;
	head = temp;

	size--;
}


template<typename T>
inline void Queue<T>::clear()
{
	while (size!=0)
	{
		pop();
	}
}





template<typename T>
inline void Queue<T>::revers()
{
	if (size == 0 || size == 1) return;

	if (size == 2 || size == 3)
	{
		swap();
	}
	else
	{
		tail = head;

		Node<T>* prhead = nullptr;
		Node<T>* p;

		while (head != nullptr)
		{
			p = head->pNext;
			head->pNext = prhead;
			prhead = head;
			head = p;
		}

		head = prhead;
	}
}

template<typename T>
inline bool Queue<T>::search(const T& dat)
{
	for (Node<T>* i = head; i != nullptr; i = i->pNext)
	{
		if (i->data == dat)
		{
			return true;
		}
	}

	return false;
}

template<typename T>
inline void Queue<T>::swap()
{
	if (size == 0 || size == 1) return;

	T dat = tail->data;
	tail->data = head->data;
	head->data = dat;
}


template<typename T>
inline void Queue<T>::Print_Queue()
{
	for (Node<T>* i = this->head; i != nullptr; i = i->pNext)
	{
		std::cout << i->data << '\n';
	}
}