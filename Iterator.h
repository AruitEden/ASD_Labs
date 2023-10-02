#pragma once
#include<iostream>




template<class T, class S>
class Iterator
{

protected:

	T* m_element;

	



	T& operator*() 
	{
		return *m_element;
	}
	T& operator->()
	{
		return *m_element;
	}



	Iterator<T, S>& operator++() 
	{
		return *this;
	}

	Iterator<T, S> operator++(int) 
	{
		return *this;
	}



	Iterator<T, S>& operator--() 
	{
		return *this;
	}

	Iterator<T, S> operator--(int) 
	{
		return *this;
	}



	bool operator==(const Iterator& other)
	{
		return true;
	}

	bool operator!=(const Iterator& other)
	{
		return true;
	}

};





template<class T, class S>
class Const_iterator
{

protected:

	const T* m_element;





	const T& operator*()
	{
		return *m_element;
	}
	const T& operator->()
	{
		return *m_element;
	}



	Const_iterator<T, S>& operator++()
	{
		return *this;
	}

	Const_iterator<T, S> operator++(int)
	{
		return *this;
	}



	Const_iterator<T, S>& operator--()
	{
		return *this;
	}

	Const_iterator<T, S> operator--(int)
	{
		return *this;
	}



	bool operator==(const Const_iterator& other)
	{
		return true;
	}

	bool operator!=(const Const_iterator& other)
	{
		return true;
	}

};








