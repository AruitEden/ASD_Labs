#pragma once
#include <iostream>
#include "Forward_list.h"



template <typename T, typename Container>
struct Stack_traits
{};

template <typename T>
struct Stack_traits<T, Forward_list<T>> 
{

	using iterator_type = Forward_list_iterator<T>;

};





template <class T, class Container = Forward_list<T>>
class Stack;



template <typename T, typename Container = Forward_list<T>>
using Stack_iterator = typename Stack_traits<T, Container>::iterator_type;






template <class T, class Container>
class Stack
{

protected:

	Container m_container;


public:


};



template <class T>
class Stack<T, Forward_list<T>>
{

protected:

	Forward_list<T> m_container;


public:

	Stack<T, Forward_list<T>>() : m_container(Forward_list<T>()) {}
	


	void push(const T& value);

	void pop();

	void exchange();

	void reverse();



	size_t size();

	Stack_iterator<T> begin();

	Stack_iterator<T> end();

};



#include "Stack.inl"