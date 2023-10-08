#pragma once
#include<iostream>




template<class T, class S>
class Iterator
{

protected:

	T* m_element;

	



	T& operator*();

	T& operator->();



	Iterator<T, S>& operator++();

	Iterator<T, S> operator++(int);



	Iterator<T, S>& operator--();

	Iterator<T, S> operator--(int);



	bool operator==(const Iterator<T, S>& other);

	bool operator!=(const Iterator<T, S>& other);

};





template<class T, class S>
class Reverse_iterator
{

protected:

	T* m_element;





	T& operator*();

	T& operator->();



	Reverse_iterator<T, S>& operator++();

	Reverse_iterator<T, S> operator++(int);



	Reverse_iterator<T, S>& operator--();

	Reverse_iterator<T, S> operator--(int);



	bool operator==(const Reverse_iterator<T, S>& other);

	bool operator!=(const Reverse_iterator<T, S>& other);

};





template<class T, class S>
class Const_iterator
{

protected:

	const T* m_element;





	const T& operator*();

	const T& operator->();



	Const_iterator<T, S>& operator++();

	Const_iterator<T, S> operator++(int);



	Const_iterator<T, S>& operator--();

	Const_iterator<T, S> operator--(int);



	bool operator==(const Const_iterator& other);

	bool operator!=(const Const_iterator& other);

};








