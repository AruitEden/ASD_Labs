#include "Iterator.h"





template<class T, class S>
inline T& Iterator<T, S>::operator*()
{
	return *m_element;
}

template<class T, class S>
inline T& Iterator<T, S>::operator->()
{
	return *m_element;
}



template<class T, class S>
Iterator<T, S>& Iterator<T, S>::operator++()
{
	return *this;
}

template<class T, class S>
Iterator<T, S> Iterator<T, S>::operator++(int)
{
	return *this;
}



template<class T, class S>
Iterator<T, S>& Iterator<T, S>::operator--()
{
	return *this;
}

template<class T, class S>
Iterator<T, S> Iterator<T, S>::operator--(int)
{
	return *this;
}



template<class T, class S>
bool Iterator<T, S>::operator==(const Iterator& other)
{
	return false;
}

template<class T, class S>
bool Iterator<T, S>::operator!=(const Iterator& other)
{
	return false;
}





template<class T, class S>
inline T& Reverse_iterator<T, S>::operator*()
{
	return *m_element;
}

template<class T, class S>
inline T& Reverse_iterator<T, S>::operator->()
{
	return *m_element;
}



template<class T, class S>
Reverse_iterator<T, S>& Reverse_iterator<T, S>::operator++()
{
	return *this;
}

template<class T, class S>
Reverse_iterator<T, S> Reverse_iterator<T, S>::operator++(int)
{
	return *this;
}



template<class T, class S>
Reverse_iterator<T, S>& Reverse_iterator<T, S>::operator--()
{
	return *this;
}

template<class T, class S>
Reverse_iterator<T, S> Reverse_iterator<T, S>::operator--(int)
{
	return *this;
}



template<class T, class S>
bool Reverse_iterator<T, S>::operator==(const Reverse_iterator& other)
{
	return false;
}

template<class T, class S>
bool Reverse_iterator<T, S>::operator!=(const Reverse_iterator& other)
{
	return false;
}





template<class T, class S>
inline const T& Const_iterator<T, S>::operator*()
{
	return *m_element;
}

template<class T, class S>
const T& Const_iterator<T, S>::operator->()
{
	return *m_element;
}



template<class T, class S>
Const_iterator<T, S>& Const_iterator<T, S>::operator++()
{
	return *this;
}

template<class T, class S>
Const_iterator<T, S> Const_iterator<T, S>::operator++(int)
{
	return *this;
}



template<class T, class S>
Const_iterator<T, S>& Const_iterator<T, S>::operator--()
{
	return *this;
}

template<class T, class S>
Const_iterator<T, S> Const_iterator<T, S>::operator--(int)
{
	return *this;
}



template<class T, class S>
bool Const_iterator<T, S>::operator==(const Const_iterator& other)
{
	return false;
}

template<class T, class S>
bool Const_iterator<T, S>::operator!=(const Const_iterator& other)
{
	return false;
}