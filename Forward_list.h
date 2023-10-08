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

	~Forward_list<T>() {}; //TODO



	void Push_front(const T& value)
	{
		m_head = new Node(value, m_head);
		++m_size;
	}

	void Insert(const List_iterator<T>& location)
	{
		Node* temp = location.m_element;
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