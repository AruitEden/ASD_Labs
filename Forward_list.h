#pragma once
#include <iostream>
#include "Iterator.h"





template <class T>
class Forward_list;





template <typename T>
using Forward_list_iterator = Iterator<T, Forward_list<T>>;





template <class T>
class Forward_list
{

private:

	template<class T, class S> friend class Iterator;
	

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



		bool has_next() const
		{
			return m_next != nullptr ? true : false;
		}

		Node* get_next() const
		{
			return m_next;
		}

		void set_next(Node* next)
		{
			m_next = next;
		}

		node_T& get_data()
		{
			return *m_data;
		}

		const node_T& get_data() const
		{
			return *m_data;
		}

	};



	size_t m_size;

	Node* m_head;


public:

	Forward_list<T>() : m_size(0), m_head(nullptr) {}



	Forward_list<T>(Forward_list<T>& other);

	Forward_list<T>& operator=(Forward_list<T>& other);



	Forward_list<T>(Forward_list<T>&& other);

	Forward_list<T>& operator=(Forward_list<T>&& other);



	virtual ~Forward_list<T>() 
	{
		clear();
	}





	virtual void push_front(const T& value);

	virtual void push_back(const T& value);

	virtual void insert_after(Forward_list_iterator<T> location, const T& value);



	virtual void move_by(Forward_list_iterator<T> location, size_t n);



	virtual void erase(Forward_list_iterator<T> location);

	virtual void erase_every(size_t n);

	virtual void pop_front();

	virtual void clear();



	virtual void sort();

	virtual void reverse_sort();



	virtual size_t size()
	{
		return m_size;
	}

	virtual Forward_list_iterator<T> begin()
	{
		return Forward_list_iterator<T>(m_head);
	}

	virtual Forward_list_iterator<T> end()
	{
		Forward_list_iterator<T> temp(m_head);
		
		for (int i = 0; i < m_size; ++i, ++temp);

		return temp;
	}

};



template <typename T>
Forward_list<T> conjoin(Forward_list<T>& l1, Forward_list<T>& l2);

template <typename T>
Forward_list<T> intersect(Forward_list<T>& l1, Forward_list<T>& l2);






template <class T>
class Iterator<T, Forward_list<T>>
{

protected:

	using Node_t = typename Forward_list<T>::Node;

	Node_t* m_element;

	template<class T> friend class Forward_list;

	template<class T> friend class Looped_forward_list;



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
	
	Iterator<T, Forward_list<T>>(const Forward_list_iterator<T>& other)
	{

		m_element = other.m_element;

	}

	Forward_list_iterator<T>& operator=(const Forward_list_iterator<T>& other)
	{
		m_element = other.m_element;

		return *this;
	}



	T& operator*()
	{
		return m_element->get_data();
	}

	T* operator->()
	{
		return &(m_element->get_data());
	}
	


	Forward_list_iterator<T>& operator++()
	{
		m_element = m_element->get_next();
		return *this;
	}

	Forward_list_iterator<T> operator++(int)
	{
		Forward_list_iterator<T> temp(*this);
		m_element = m_element->get_next();
		return temp;
	}



	bool operator==(const Forward_list_iterator<T>& other)
	{
		return m_element == other.m_element;
	}

	bool operator!=(const Forward_list_iterator<T>& other)
	{
		return m_element != other.m_element;
	}

};








#include "Forward_list.inl"