#include "Queue.h"



template<class T>
void Queue<T, Forward_list<T>>::push(const T& value)
{
	m_container.push_front(value);
}

template<class T>
void Queue<T, Forward_list<T>>::pop()
{
	Queue_iterator<T> it = begin();

	for (size_t i = 0; i < size() - 1; ++i, ++it);

	m_container.erase(it);
}



template<class T>
void Queue<T, Forward_list<T>>::exchange()
{
	if (size() < 2)
	{
		return;
	}


	Queue_iterator<T> it = begin();

	for (size_t i = 0; i < size() - 1; ++i, ++it);


	T new_head = *it;

	m_container.erase(it);

	m_container.move_by(begin(), size() - 1);

	m_container.push_front(new_head);
}



template<class T>
size_t Queue<T, Forward_list<T>>::size()
{
	return m_container.size();
}



template<class T>
void Queue<T, Forward_list<T>>::reverse()
{
	Queue<T> reversed_queue;

	for (auto i : *this)
	{
		reversed_queue.push(i);
	}

	(*this) = std::move(reversed_queue);
}



template<class T>
bool Queue<T, Forward_list<T>>::contains(const T& value)
{
	for (auto i : *this)
	{
		if (i == value)
		{
			return true;
		}
	}

	return false;
}



template<class T>
void Queue<T, Forward_list<T>>::clear()
{
	m_container.clear();
}



template<class T>
inline Queue_iterator<T> Queue<T, Forward_list<T>>::begin()
{
	return m_container.begin();
}

template<class T>
inline Queue_iterator<T> Queue<T, Forward_list<T>>::end()
{
	return m_container.end();
}