#pragma once

template<typename T>
class Looped_forward_list
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

	Looped_forward_list();

	~Looped_forward_list();



	int getSize() { return size; }


	void push_back(T data);

	void push_front(const T& data);

	void insert(const T& value, int index);




	void pop_front();

	void pop_back();

	void removeAt(int index);

	void removeEach(int n);

	void clear();



	T& operator[] (const int index);
};


template<typename T>
void Print_LoopedList(Looped_forward_list<T>& list);

int find_alive(int size, int n);

#include "Looped_forward_list.inl"