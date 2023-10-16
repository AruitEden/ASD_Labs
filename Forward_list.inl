#include "Forward_list.h"

template<typename T>
inline Forward_list<T>::Forward_list()
{
	size = 0;
	head = nullptr;
}

template <typename T>
Forward_list<T>::Forward_list(const Forward_list<T>& other) :size(0), head(nullptr)
{

	Node<T>* last = nullptr;

	for (Node<T>* n = other.head; n != nullptr; n = n->pNext)
	{
		Node<T>* temp = new Node<T>(n->data);
		if (!head)
		{
			head = temp;
		}
		else
		{
			last->pNext = temp;
		}
		last = temp;
		size++;
	}
}

template<typename T>
inline Forward_list<T>::~Forward_list()
{
	clear();
}





template<typename T>
void Forward_list<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}

	else
	{
		Node<T>* current = this->head;

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}

		current->pNext = new Node<T>(data);
	}
	size++;
}


template<typename T>
void Forward_list<T>::push_front(const T& data)
{
	head = new Node<T>(data, head);
	size++;
}


template<typename T>
void Forward_list<T>::insert(const T& value, int index)
{
	if (index < 0 || index >= size)
	{
		std::cout << "Incorrect index\n";
		return;
	}


	Node<T>* prev = head;

	for (int i = 0; i < index; i++)
	{
		prev = prev->pNext;
	}

	Node<T>* newNode = new Node<T>(value, prev->pNext);

	prev->pNext = newNode;

	size++;
}



template<typename T>
void Forward_list<T>::pop_front()
{
	Node<T>* temp = head;
	head = head->pNext;
	delete temp;

	size--;
}


template<typename T>
void Forward_list<T>::pop_back()
{
	removeAt(size - 1);
}


template<typename T>
void Forward_list<T>::removeAt(int index)
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
void Forward_list<T>::removeEach(int n)
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

		while (i < size)
		{
			removeAt(i);
			i += n - 1;
		}
	}
}


template<typename T>
void Forward_list<T>::clear()
{
	while (size != 0)
	{
		pop_front();
	}
}



template<typename T>
void Forward_list<T>::movePos(int indexPrev, int n, bool vector)
{

	if (vector == true && n + indexPrev >= size || vector == false && indexPrev - n < 0)
	{
		std::cout << "I cant move";
		return;
	}

	Node<T>* prev = head;

	Node<T>* temp;

	if (indexPrev == 0)
	{
		temp = head;
		head = prev->pNext;
	}
	else
	{
		for (int i = 0; i < indexPrev - 1; i++)
		{
			prev = prev->pNext;
		}

		temp = prev->pNext;

		prev->pNext = temp->pNext;
	}

	size--;

	if (vector)
	{
		insert(temp->data, indexPrev + (n - 1));
	}
	else
	{
		if (indexPrev - n == 0)
		{
			push_front(temp->data);
		}

		else
		{
			insert(temp->data, indexPrev - (n + 1));
		}
	}
}


template<typename T>
void Forward_list<T>::connectList(Forward_list<T>& list2) 
{

	for (Node<T>* temp = list2.head; temp != nullptr; temp = temp->pNext)
	{
		push_back(temp->data);
	}

	list2.clear();
}



template<typename T>
void Forward_list<T>::sort(SortOrder sortorder)
{
	bool flag = false;

	if (size == 0 || size == 1)
	{
		return;
	}

	for (int i = 1; i < getSize(); i++)
	{
		Node<T>* current = head->pNext;
		Node<T>* prev = head;

		flag = false;

		for (int j = 0; j < getSize()-1; j++)
		{
			if (!isSorted(prev->data, current->data, sortorder))
			{
				swap(prev, current);

				flag = true;
			}

			prev = prev->pNext;
			current = current->pNext;
		}

		if (!flag)
		{
			break;
		}
	}
}


template<typename T>
void Forward_list<T>::swap(Node<T> *prev, Node<T>* current)
{
	T t = prev ->data;
	prev->data = current->data;
	current->data = t;
}


template<typename T>
void Forward_list<T>::clearRepeat()
{
	Node<T>* prev = head, *temp, *dup;
	while (prev!=nullptr && prev ->pNext != nullptr)
	{
		temp = prev;
		while (temp->pNext != nullptr)
		{
			if (prev->data == temp->pNext->data)
			{
				dup = temp->pNext;
				temp->pNext = temp->pNext->pNext;
				delete dup;
				size--;
			}
			else temp = temp->pNext;
		}
		prev = prev->pNext;
	}
}



template<typename T>
inline void Print_list(Forward_list<T>& list)
{
	for (int i = 0; i < list.getSize(); i++)
	{
		std::cout<< i << ". " << list[i] << '\n';
	}
}



template<typename T>
T& Forward_list<T>::operator[](const int index)
{
	int count = 0;
	Node<T>* current = this->head;

	if (index >= size || index < 0)
	{
		throw "Incorrect index";
	}


	while (current != nullptr)
	{
		if (count == index)
		{
			return current->data;
		}

		current = current->pNext;
		count++;
	}

}



template<typename T>
inline void repeatList( Forward_list<T>& list1, Forward_list<T>& list2, Forward_list<T>& list_copy)
{
	for (int i = 0; i < list1.getSize(); i++)
	{
		for (int j = 0; j < list2.getSize(); j++)
		{
			if (list1[i] == list2[j])
			{
				list_copy.push_back(list1[i]);
				break;
			}
		}
	}

	list_copy.clearRepeat();
}




