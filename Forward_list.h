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
using Forward_list_iterator = typename Forward_list_traits<T>::iterator_type;





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

	Forward_list<T>(Forward_list<T>& other) : m_size(other.m_size)
	{
		if(m_size == 0)
		{
			m_head = nullptr;
			return;
		}

		m_head = new Node(other.m_head->get_data(), other.m_head->get_next());
		Node* temp = m_head;

		for (size_t i = 0; i < m_size - 1; ++i)
		{
			temp->set_next(new Node(temp->get_next()->get_data(), temp->get_next()->get_next()));
			temp = temp->get_next();
		}
	}

	Forward_list<T>& operator=(Forward_list<T>& other)
	{
		if(m_head == other.m_head)
		{
			return *this;
		}

		clear();

		m_size = other.m_size;

		m_head = new Node(other.m_head->get_data(), other.m_head->get_next());
		Node* temp = m_head;

		for (size_t i = 0; i < m_size - 1; ++i)
		{
			temp->set_next(new Node(temp->get_next()->get_data(), temp->get_next()->get_next()));
			temp = temp->get_next();
		}

		return *this;
	}

	Forward_list<T>(Forward_list<T>&& other)
		: m_size(other.m_size), m_head(other.m_head)
	{
		other.m_size = 0;
	}

	Forward_list<T>& operator=(Forward_list<T>&& other)
	{
		clear();

		m_size = other.m_size;

		m_head = other.m_head;

		other.m_size = 0;

		return *this;
	}

	virtual ~Forward_list<T>() 
	{
		clear();
	}



	virtual void push_front(const T& value)
	{
		m_head = new Node(value, m_head);
		++m_size;
	}

	virtual void push_back(const T& value)
	{
		if(m_size < 1)
		{
			push_front(value);
			return;
		}

		Forward_list_iterator<T> current = begin();
		for (size_t i = 0; i < m_size - 1; ++i, ++current);

		current.m_element->set_next(new Node(value, nullptr));
		++m_size;
	}

	virtual void insert_after(Forward_list_iterator<T> location, const T& value)
	{
		location.m_element->set_next(new Node(value, location.m_element->get_next()));
		++m_size;
	}

	virtual void move_by(Forward_list_iterator<T> location, size_t n)
	{
		Node* temp = location.m_element;
		Forward_list_iterator<T> current = begin();

		if (current != location)
		{
			while (current.m_element->get_next() != temp)
			{
				++current;
			}
		}
		else
		{
			m_head = temp->get_next();
		}

		current.m_element->set_next(location.m_element->get_next());

		for (size_t i = 0; i < n; ++i, ++current);

		temp->set_next(current.m_element->get_next());
		current.m_element->set_next(temp);
	}

	virtual void erase(Forward_list_iterator<T> location)
	{

		Node* temp = location.m_element;
		Forward_list_iterator<T> current = begin();

		if(current == location)
		{
			pop_front();
			return;
		}

		while (current.m_element->get_next() != temp)
		{
			++current;
		}

		current.m_element->set_next(temp->get_next());

		--m_size;

		delete temp;
	}

	virtual void erase_every(size_t n)
	{
		if(n == 0)
		{
			return;
		}

		if (n == 1)
		{
			clear();
			return;
		}

		Forward_list_iterator<T> current = begin();

		for(size_t i = 0, count = m_size / n; i < count; ++i)
		{
			for (size_t j = 0; j < n - 1; ++j, ++current);

			Forward_list_iterator<T> temp = current++;

			erase(temp);
		}
	}

	virtual void pop_front()
	{
		Node* temp = m_head;

		m_head = m_head->get_next();

		--m_size;

		delete temp;
	}

	virtual void clear() 
	{
		while(m_size > 0)
		{
			Forward_list<T>::pop_front();
		}
	}

	virtual void sort()
	{
		if(m_size == 0)
		{
			return;
		}

		Forward_list new_list;

		while(m_size > 0)
		{
			Forward_list_iterator<T> max = begin();

			Forward_list_iterator<T> list_end = end();

			for(Forward_list_iterator<T> it = begin(); it != list_end; ++it)
			{
				if(*it > *max)
				{
					max = it;
				}
			}

			new_list.push_front(*max);

			erase(max);
		}

		*this = std::move(new_list);
	}

	virtual void reverse_sort()
	{
		if (m_size == 0)
		{
			return;
		}

		Forward_list new_list;

		while (m_size > 0)
		{
			Forward_list_iterator<T> min = begin();

			Forward_list_iterator<T> list_end = end();

			for (Forward_list_iterator<T> it = begin(); it != list_end; ++it)
			{
				if (*it < *min)
				{
					min = it;
				}
			}

			new_list.push_front(*min);

			erase(min);
		}

		*this = std::move(new_list);
	}

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
Forward_list<T> conjoin(Forward_list<T>& l1, Forward_list<T>& l2)
{

	Forward_list<T> conjoined;

	for(T& i : l1)
	{
		conjoined.push_back(i);
	}
	for(T& i : l2)
	{
		conjoined.push_back(i);
	}

	return conjoined;

}

template <typename T>
Forward_list<T> intersect(Forward_list<T>& l1, Forward_list<T>& l2)
{

	Forward_list<T> new_list;

	for(auto i : l1)
	{
		for (auto j : l2) 
		{
			if(i == j)
			{
				new_list.push_back(i);
				break;
			}
		}
	}

	return std::move(new_list);

}





template <class T>
class Iterator<T, Forward_list<T>>
{

protected:

	using Node_t = typename Forward_list_traits<T>::element_type;

	Node_t* m_element;

	template<class T> friend class Forward_list;

	template<class T> friend class Circular_forward_list;



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

	T& operator->()
	{
		return m_element->get_data();
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