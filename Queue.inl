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
inline void Queue<T>::push_back(T data)
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
inline void Queue<T>::pop_front()
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
		pop_front();
	}
}




template<typename T>
inline void Queue<T>::Print_Queue()
{
	for (Node<T>* i = this->head; i != nullptr; i = i->pNext)
	{
		std::cout << i->data << '\n';
	}
}