#pragma once
#include <iostream>
#include "Forward_list.h"


template <typename T, typename Container>
struct Stack_traits
{

	using iterator_type = typename Iterator<T, Container>;

};



template <typename T>
struct Stack_traits<T, Forward_list<T>>
{

	using iterator_type = typename Forward_list_iterator<T>;

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

	Stack<T, Container>() : m_container(Container()) {}


};
