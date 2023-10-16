#include "Stack.h"

template<typename T>
inline Stack<T>::Stack()
{
	size = 0;
	head = nullptr;
}


template<typename T>
inline Stack<T>::~Stack()
{
	clear();
}




template<typename T>
void Stack<T>::push(const T& data)
{
	head = new Node<T>(data, head);
	size++;
}




template<typename T>
void Stack<T>::pop()
{
	if (size == 0)
	{
		return;
	}

	Node<T>* temp = head;
	head = head->pNext;
	delete temp;

	size--;
}


template<typename T>
void Stack<T>::clear()
{
	while (size != 0)
	{
		pop();
	}
}





template<typename T>
inline void Stack<T>::swap()
{
	Node<T>* temp = head;

	while (temp->pNext != nullptr)
	{
		temp = temp->pNext;
	}

	T dat = temp->data;
	temp->data = head->data;
	head->data = dat;
}


template<typename T>
inline void Stack<T>::Print_list()
{
	for (Node<T> *i = head; i != nullptr; i = i->pNext)
	{
		std::cout << i->data << '\n';
	}
}
