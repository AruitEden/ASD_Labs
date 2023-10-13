#include "Looped_forward_list.h"


template<class T>
inline void Looped_forward_list<T>::push_front(const T& value)
{
	if (Forward_list<T>::m_size == 0)
	{
		Forward_list<T>::m_head = m_tail = new Node(value, nullptr);
		Forward_list<T>::m_head->set_next(Forward_list<T>::m_head);

		++Forward_list<T>::m_size;

		return;
	}

	Node* temp = new Node(value, Forward_list<T>::m_head);

	m_tail->set_next(temp);

	Forward_list<T>::m_head = temp;

	++Forward_list<T>::m_size;
}

template<class T>
inline void Looped_forward_list<T>::clear()
{
	if (Forward_list<T>::m_size > 0) {

		m_tail->set_next(nullptr);

		this->Forward_list<T>::clear();

	}
}

template<class T>
inline void Looped_forward_list<T>::pop_front()
{
	if (Forward_list<T>::m_size == 1)
	{
		--Forward_list<T>::m_size;

		delete Forward_list<T>::m_head;

		Forward_list<T>::m_head = nullptr;
		m_tail = nullptr;

		return;
	}

	Node* temp = Forward_list<T>::m_head;

	m_tail->set_next(Forward_list<T>::m_head->get_next());

	Forward_list<T>::m_head = m_tail->get_next();

	delete temp;

	--Forward_list<T>::m_size;
}

template<class T>
inline void Looped_forward_list<T>::erase(Looped_forward_list_iterator<T> location)
{
	Forward_list<T>::erase(location);

	if (Forward_list<T>::m_size > 0)
	{
		Looped_forward_list_iterator<T> it = begin();

		while (it.m_element->get_next() != Forward_list<T>::m_head)
		{
			++it;
		}

		m_tail = it.m_element;
	}
}
