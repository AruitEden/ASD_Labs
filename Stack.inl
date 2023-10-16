#include "Stack.h"



template<class T>
void Stack<T, Forward_list<T>>::push(const T& value)
{

	m_container.push_front(value);

}

template<class T>
void Stack<T, Forward_list<T>>::pop()
{

	m_container.pop_front();

}



template<class T>
void Stack<T, Forward_list<T>>::exchange()
{
	if(size() < 2)
	{
		return;
	}


	Stack_iterator<T> it = begin();

	for (size_t i = 0; i < size() - 1; ++i, ++it);


	T new_head = *it;

	m_container.erase(it);

	m_container.move_by(begin(), size() - 1);

	m_container.push_front(new_head);
}



template<class T>
size_t Stack<T, Forward_list<T>>::size()
{
	return m_container.size();
}



template<class T>
inline Stack_iterator<T> Stack<T, Forward_list<T>>::begin()
{

	return m_container.begin();

}

template<class T>
inline Stack_iterator<T> Stack<T, Forward_list<T>>::end()
{

	return m_container.end();

}

