#pragma once
#include <iostream>
#include "Iterator.h"







template <class T>
class Forward_list
{

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
	


	using List_iterator = Iterator<T, Forward_list<T>>;

	

	

};





template <class T>
class Iterator<T, Forward_list<T>> 
{

protected:

	T* m_element;

};



#include "Forward_list.inl"

