#pragma once
#include <iostream>
#include "Forward_list.h"





template <typename T, typename Container>
struct Queue_traits
{};

template <typename T>
struct Queue_traits<T, Forward_list<T>>
{

	using iterator_type = Forward_list_iterator<T>;

};





template <class T, class Container = Forward_list<T>>
class Queue;



template <typename T, typename Container = Forward_list<T>>
using Queue_iterator = typename Queue_traits<T, Container>::iterator_type;






template <class T, class Container>
class Queue
{

protected:

	Container m_container;


public:


};




template <class T>
class Queue<T, Forward_list<T>>
{

protected:

	Forward_list<T> m_container;


public:

	Queue<T, Forward_list<T>>() : m_container(Forward_list<T>()) {}



	void push(const T& value);

	void pop();



	void exchange();

	void reverse();

	bool contains(const T& value);

	void clear();



	size_t size();

	Queue_iterator<T> begin();

	Queue_iterator<T> end();

};



#include "Queue.inl"
