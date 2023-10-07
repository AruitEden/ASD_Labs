#pragma once
#include <iostream>
#include "Iterator.h"







template <class T>
class Forward_list
{


protected:

	using List_iterator = Iterator<T, Forward_list<T>>;

	template<class T>
	class Node
	{

	private:

		T* const m_data;
		Node* m_next;


	public:

		Node(Node* const next, const T& data) :
			m_next(next), m_data(new T(data)) {}



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

		T& GetData() 
		{
			return *m_data;
		}

		const T& GetData() const 
		{
			return *m_data;
		}

	};


	Node m_head;
	
	template <class T, class S> class Iterator;

	template <class T, class S>
	friend class Iterator;

	static int a;
	

	

};



template<class T> class A;

template<class T> class B;

template<class T>
class A 
{

	template<class T> friend class B;


protected:

	class Type
	{
		
	public:

		int _a;
		Type(int a):_a(a){}

		operator int()
		{
			return _a;
		}

	};

private:
	static int a;

protected:
	static int b;

public:
	static int c;

	void Foo()
	{
		
	}

};


template <class T>
class B 
{

private:
	static int a;

protected:
	static int b;

public:
	static int c;

	using A_Type = typename A<T>::Type;

	void Foo()
	{
		A_Type type = 6;
		std::cout << type << '\n';
	}
	

};




template <class T>
class Iterator<T, Forward_list<T>> 
{



protected:

	T* m_element;


public:

	void Foo()
	{
		
	}

};



#include "Forward_list.inl"

