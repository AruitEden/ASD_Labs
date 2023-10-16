#pragma once


template <typename T>
class Stack
{

private:

	template <typename T>
	struct Node
	{
		Node* pNext;
		T data;

		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};


	Node<T>* head;
	int size;

public:

	Stack();

	~Stack();



	int getSize() { return size; }



	void push(const T& data);




	void pop();

	void clear();



	void Print_list();
};



#include "Stack.inl"