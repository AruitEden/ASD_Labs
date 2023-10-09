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

	

	/*void Insertion_sort()
	{

		bool changes = true;

		while(changes)
		{

			changes = false;

			List_iterator<T> new_pos;

			for(List_iterator<T> i = new_pos; i.m_element->get_next() != nullptr; ++i)
			{

				if(*i > i.m_element->get_next()->get_data())
				{
					
					changes = true;
				}

			}

		}

	}*/

	/*
	void Merge_sort(List_iterator<T> begin, List_iterator<T> end, size_t size)
	{
		if(size < 2)
		{
			return;
		}

		List_iterator<T> mid = begin;
		for (size_t i = 0; i < size / 2; ++i, ++mid);

		List_iterator<T> begin_1 = begin, end_1 = mid, begin_2 = mid, end_2 = end;
		size_t size_1 = size / 2, size_2 = size / 2 + 1;

		Merge_sort(begin_1, end_1, size_1);
		Merge_sort(begin_2, end_2, size_2);
		Merge(begin_1, end_1, size_1, begin_2, end_2, size_2);

	}

	void Merge(List_iterator<T> begin_1, List_iterator<T> end_1, size_t size_1, List_iterator<T> begin_2, List_iterator<T> end_2, size_t size_2)
	{

		Forward_list<T> new_lst;

		bool new_head = (m_head == begin_1.m_element);

		List_iterator<T> it1 = begin_1, it2 = begin_2;

		while(it1 != end_1 || it2 != end_2)
		{
			if(*it1 > *it2)
			{
				new_lst.push_front(*it1);
				++it1;
			}
			else
			{
				new_lst.push_front(*it2);
				++it2;
			}
		}

		while(it1 != end_1)
		{
			new_lst.push_front(*it1);
			++it1;
		}
		while (it2 != end_2)
		{
			new_lst.push_front(*it2);
			++it2;
		}

		for(auto i : new_lst)
		{
			std::cout << i << '\n';
		}

		//.end().m_element = end_2.m_element;

		Forward_list<T> temp;
		temp.m_size = size_1 + size_2;
		temp.m_head = begin_1.m_element;
		temp.end().m_element = nullptr;
		temp.clear();

		begin_1.m_element = new_lst.m_head;

		if (new_head) 
		{
			m_head = begin_1.m_element;
		}

	}
	*/

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

	~Forward_list<T>() 
	{
		for (size_t i = 0; i < m_size; ++i)
		{
			pop_front();
		}
	}



	void push_front(const T& value)
	{
		m_head = new Node(value, m_head);
		++m_size;
	}

	void push_back(const T& value)
	{
		if(m_size < 1)
		{
			push_front(value);
			return;
		}

		List_iterator<T> current = begin();
		for (size_t i = 0; i < m_size - 1; ++i, ++current);

		current.m_element->set_next(new Node(value, nullptr));
		++m_size;
	}

	void insert_after(List_iterator<T>& location, const T& value)
	{
		location.m_element->set_next(new Node(value, location.m_element->get_next()));
		++m_size;
	}

	void move_by(List_iterator<T>& location, size_t n)
	{
		Node* temp = location.m_element;
		List_iterator<T> current = begin();

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

	void erase(List_iterator<T>& location)
	{

		Node* temp = location.m_element;
		List_iterator<T> current = begin();

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

	void erase_every(size_t n)
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

		List_iterator<T> current = begin();

		for(size_t i = 0, count = m_size / n; i < count; ++i)
		{
			for (size_t j = 0; j < n - 1; ++j, ++current);

			List_iterator<T> temp = current++;

			erase(temp);
		}
	}

	void pop_front()
	{
		Node* temp = m_head;

		m_head = m_head->get_next();

		--m_size;

		delete temp;
	}

	void clear() 
	{
		while(m_size > 0)
		{
			pop_front();
		}
	}

	void sort()
	{
		if(m_size == 0)
		{
			return;
		}

		Forward_list new_list;

		while(m_size > 0)
		{
			List_iterator<T> max = begin();

			List_iterator<T> list_end = end();

			for(List_iterator<T> it = begin(); it != list_end; ++it)
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

	void reverse_sort()
	{
		if (m_size == 0)
		{
			return;
		}

		Forward_list new_list;

		while (m_size > 0)
		{
			List_iterator<T> min = begin();

			List_iterator<T> list_end = end();

			for (List_iterator<T> it = begin(); it != list_end; ++it)
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

	size_t size()
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

	//List_iterator<T> it_1 = l1.begin(), it_2 = l2.begin(), end_1 = l1.end(), end_2 = l2.end();

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
	


	List_iterator<T>& operator++()
	{
		m_element = m_element->get_next();
		return *this;
	}

	List_iterator<T> operator++(int)
	{
		List_iterator<T> temp(*this);
		m_element = m_element->get_next();
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