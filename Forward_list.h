#pragma once
#include <iostream>
#include "Iterator.h"





template <class T>
class Forward_list;



template <typename T>
struct Forward_list_traits
{

	using collection_type = typename Forward_list<T>;

	using element_type = typename Forward_list<T>::Node;

	using iterator_type = typename Iterator<T, Forward_list<T>>;

};



template <typename T>
using List_iterator = typename Forward_list_traits<T>::iterator_type;





template <class T>
class Forward_list
{

private:

	template<class T, class S> friend class Iterator;

	template<typename T> friend struct Forward_list_traits;
	

protected:

	using node_T = T;

	class Node
	{

	private:

		node_T* const m_data;
		Node* m_next;


	public:

		Node(const node_T& data, Node* const next) :
			m_data(new node_T(data)), m_next(next) {}



		~Node()
		{
			delete m_data;
		}



		bool Has_next() const
		{
			return m_next != nullptr ? true : false;
		}

		Node* Get_next() const
		{
			return m_next;
		}

		void Set_next(Node* next)
		{
			m_next = next;
		}

		node_T& Get_data()
		{
			return *m_data;
		}

		const node_T& Get_data() const
		{
			return *m_data;
		}

	};



	size_t m_size;

	Node* m_head;


public:

	Forward_list<T>() : m_size(0), m_head(nullptr) {}

	Forward_list<T>(const Forward_list<T>& other) : m_size(other.m_size)
	{

	}

	~Forward_list<T>() {}; //TODO



	void Push_front(const T& value)
	{
		m_head = new Node(value, m_head);
		++m_size;
	}

	void Insert_after(List_iterator<T>& location, const T& value)
	{
		location.m_element->Set_next(new Node(value, location.m_element->Get_next()));
		++m_size;
	}

	void Move_by(List_iterator<T>& location, size_t n)
	{
		Node* temp = location.m_element;
		List_iterator<T> current = begin();

		if (current != location)
		{
			while (current.m_element->Get_next() != temp)
			{
				++current;
			}
		}
		else
		{
			m_head = temp->Get_next();
		}

		current.m_element->Set_next(location.m_element->Get_next());

		for (size_t i = 0; i < n; ++i, ++current);

		temp->Set_next(current.m_element->Get_next());
		current.m_element->Set_next(temp);
	}

	void Erase(List_iterator<T>& location)
	{

		Node* temp = location.m_element;
		List_iterator<T> current = begin();

		if(current == location)
		{
			Pop_front();
			return;
		}

		while (current.m_element->Get_next() != temp)
		{
			++current;
		}

		current.m_element->Set_next(temp->Get_next());

		--m_size;

		delete temp;
	}

	void Erase_every(size_t n)
	{
		if(n == 0)
		{
			return;
		}

		if (n == 1)
		{
			//clear; TODO
			return;
		}

		List_iterator<T> current = begin();

		for(size_t i = 0, count = m_size / n; i < count; ++i)
		{
			for (size_t j = 0; j < n - 1; ++j, ++current);

			List_iterator<T> temp = current++;

			Erase(temp);
		}
	}

	void Pop_front()
	{
		Node* temp = m_head;

		m_head = m_head->Get_next();

		--m_size;

		delete temp;
	}



	size_t Size()
	{
		return m_size;
	}


	List_iterator<T> begin()
	{
		return List_iterator<T>(m_head);
	}

	List_iterator<T> end()
	{
		List_iterator<T> temp(m_head);
		
		for (int i = 0; i < m_size; ++i, ++temp);

		return temp;
	}

};







template <class T>
class Iterator<T, Forward_list<T>>
{

protected:

	using Node_t = typename Forward_list_traits<T>::element_type;

	Node_t* m_element;

	template<class T> friend class Forward_list;



	Iterator<T, Forward_list<T>>(Node_t& node)
	{

		m_element = &node;

	}

	Iterator<T, Forward_list<T>>(Node_t* node)
	{

		m_element = node;

	}


public:

	Iterator<T, Forward_list<T>>()
	{

		m_element = nullptr;
		
	}
	
	Iterator<T, Forward_list<T>>(const List_iterator<T>& other)
	{

		m_element = other.m_element;

	}

	List_iterator<T>& operator=(const List_iterator<T>& other)
	{
		m_element = other.m_element;
	}



	T& operator*()
	{
		return m_element->Get_data();
	}

	T& operator->()
	{
		return m_element->Get_data();
	}
	


	List_iterator<T>& operator++()
	{
		m_element = m_element->Get_next();
		return *this;
	}

	List_iterator<T> operator++(int)
	{
		List_iterator<T> temp(*this);
		m_element = m_element->Get_next();
		return temp;
	}



	bool operator==(const List_iterator<T>& other)
	{
		return m_element == other.m_element;
	}

	bool operator!=(const List_iterator<T>& other)
	{
		return m_element != other.m_element;
	}

};



#include "Forward_list.inl"