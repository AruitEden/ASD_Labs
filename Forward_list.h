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

	template<class T> friend struct Forward_list_traits;
	

protected:

	using node_T = T;

	class Node
	{

	private:

		node_T* const m_data;
		Node* m_next;


	public:

		Node(Node* const next, const node_T& data) :
			m_next(next), m_data(new node_T(data)) {}



		~Node()
		{
			delete m_data;
		}



		bool HasNext() const
		{
			return m_next != nullptr ? true : false;
		}

		Node* GetNext() const
		{
			return m_next;
		}

		void SetNext(Node* next)
		{
			m_next = next;
		}

		node_T& GetData()
		{
			return *m_data;
		}

		const node_T& GetData() const
		{
			return *m_data;
		}

	};



	size_t m_size;

	Node* m_head;


public:

	Forward_list<T>() : m_size(0), m_head(nullptr) {}

	~Forward_list<T>() {}; //TODO





};







template <class T>
class Iterator<T, Forward_list<T>>
{

protected:

	using Node_t = typename Forward_list_traits<T>::element_type;

	Node_t* m_element;


public:

	Iterator<T, Forward_list<T>>()
	{


		
	}

	Iterator<T, Forward_list<T>>(Node_t& node)
	{

		m_element = &node;

	}
	
	Iterator<T, Forward_list<T>>(const List_iterator<T>& other)
	{

		m_element = other.m_element;

	}



	T& operator*()
	{
		return m_element->GetData();
	}

	T& operator->()
	{
		return m_element->GetData();
	}
	


	List_iterator<T>& operator++()
	{
		return (m_element = m_element->GetNext());
	}

	List_iterator<T> operator++(int)
	{
		Node_t temp = m_element;
		m_element = m_element->GetNext();
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