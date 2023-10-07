#pragma once
#include <iostream>
#include "Iterator.h"








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



public:

	using iterator_trait = typename Iterator<T, Forward_list<T>>;




};



template <typename T>
struct Forward_list_traits
{

	using collection_type = typename Forward_list<T>;

	using iterator_type = typename collection_type::iterator_trait;

};





template <typename T>
using List_iterator = typename Forward_list_traits<T>::iterator_type;



template <class T>
class Iterator<T, Forward_list<T>>
{

protected:

	using Node_t = typename Forward_list<T>::Node;

	Node_t* element;


public:

	

	

};



#include "Forward_list.inl"