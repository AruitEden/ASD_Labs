#pragma once

template<typename T>
class Queue
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
	Node<T>* tail;
	int size;

public:

	Queue();

	~Queue();



	int getSize() { return size; }


	void push_back(T data);




	void pop_front();

	void clear();



	void Print_Queue();
};

#include "Queue.inl"