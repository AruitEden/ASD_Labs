#pragma once
#include<iostream>




template<class T, class S>
class Iterator
{

protected:

	T* m_element;


public:

	T& operator*() = 0;
	const T& operator*() const = 0;

};

//template <class T, class C>
//class Iterator
//{
//protected:
//
//	C* collection;
//
//public:
//
//	virtual void push_back(const T& element) = 0;
//	virtual void push_front(const T& element) = 0;
//
//};
//
//
//
//
//
//template <class T>
//class List_iterator : Iterator<T, Forward_list<T>>
//{
//protected:
//
//	virtual void push_front(const T& element) override {}
//	using Iterator<T, Forward_list<T>>::push_front;
//
//public:
//
//	virtual void push_back(const T& element) override 
//	{
//		std::cout << "push_back\n";
//	}
//
//};