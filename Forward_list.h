#pragma once

enum SortOrder
{
	INCREASE,
	DECREASE
};



template <typename T>
class Forward_list
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

	void swap(Node<T>* prev, Node<T>* current);

public:

	Forward_list();

	Forward_list(const Forward_list<T>& other);

	~Forward_list();



	int getSize() { return size; }



	T& operator[] (const int index);



	void push_back(T data);

	void push_front(const T& data);

	void insert(const T& value, int index);




	void pop_front();

	void pop_back();

	void removeAt(int index);

	void removeEach(int n);

	void clear();



	void movePos(int indexPrev, int n, bool vector);

	void connectList(Forward_list<T>& other);

	void sort(SortOrder sortorder);

	void clearRepeat();

};


template<typename T>
void repeatList(const Forward_list<T>& list1, const Forward_list<T>& list2, Forward_list<T>& list_copy);

template<typename T>
void Print_list(Forward_list<T>& list);


#include "Forward_list.inl"