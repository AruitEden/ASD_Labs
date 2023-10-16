#include "Forward_list.h"



template<class T>
Forward_list<T>::Forward_list(Forward_list<T>& other) : m_size(other.m_size)
{
	if (m_size == 0)
	{
		m_head = nullptr;
		return;
	}

	m_head = new Node(other.m_head->get_data(), other.m_head->get_next());
	Node* temp = m_head;

	for (size_t i = 0; i < m_size - 1; ++i)
	{
		temp->set_next(new Node(temp->get_next()->get_data(), temp->get_next()->get_next()));
		temp = temp->get_next();
	}
}

template<class T>
Forward_list<T>& Forward_list<T>::operator=(Forward_list<T>& other)
{
	if (m_head == other.m_head)
	{
		return *this;
	}

	clear();

	m_size = other.m_size;

	m_head = new Node(other.m_head->get_data(), other.m_head->get_next());
	Node* temp = m_head;

	for (size_t i = 0; i < m_size - 1; ++i)
	{
		temp->set_next(new Node(temp->get_next()->get_data(), temp->get_next()->get_next()));
		temp = temp->get_next();
	}

	return *this;
}

template<class T>
Forward_list<T>::Forward_list(Forward_list<T>&& other)
	: m_size(other.m_size), m_head(other.m_head)
{
	other.m_size = 0;
}

template<class T>
Forward_list<T>& Forward_list<T>::operator=(Forward_list<T>&& other)
{
	if (m_head == other.m_head)
	{
		return *this;
	}

	clear();

	m_size = other.m_size;

	m_head = other.m_head;

	other.m_size = 0;

	return *this;
}

template<class T>
void Forward_list<T>::push_front(const T& value)
{
	m_head = new Node(value, m_head);
	++m_size;
}

template<class T>
void Forward_list<T>::push_back(const T& value)
{
	if (m_size < 1)
	{
		push_front(value);
		return;
	}

	Forward_list_iterator<T> current = begin();
	for (size_t i = 0; i < m_size - 1; ++i, ++current);

	current.m_element->set_next(new Node(value, nullptr));
	++m_size;
}

template<class T>
void Forward_list<T>::insert_after(Forward_list_iterator<T> location, const T& value)
{
	location.m_element->set_next(new Node(value, location.m_element->get_next()));
	++m_size;
}

template<class T>
void Forward_list<T>::move_by(Forward_list_iterator<T> location, size_t n)
{
	if (n == 0)
	{
		return;
	}

	Node* temp = location.m_element;
	Forward_list_iterator<T> current = begin();

	if (current != location)
	{
		while (current.m_element->get_next() != temp)
		{
			++current;
		}
	}
	else
	{
		m_head = temp->get_next();
	}

	current.m_element->set_next(location.m_element->get_next());

	for (size_t i = 0; i < n; ++i, ++current);

	temp->set_next(current.m_element->get_next());
	current.m_element->set_next(temp);
}

template<class T>
void Forward_list<T>::erase(Forward_list_iterator<T> location)
{

	Node* temp = location.m_element;
	Forward_list_iterator<T> current = begin();

	if (current == location)
	{
		pop_front();
		return;
	}

	while (current.m_element->get_next() != temp)
	{
		++current;
	}

	current.m_element->set_next(temp->get_next());

	--m_size;

	delete temp;
}

template<class T>
void Forward_list<T>::erase_every(size_t n)
{
	if (n == 0)
	{
		return;
	}

	if (n == 1)
	{
		clear();
		return;
	}

	Forward_list_iterator<T> current = begin();

	for (size_t i = 0, count = m_size / n; i < count; ++i)
	{
		for (size_t j = 0; j < n - 1; ++j, ++current);

		Forward_list_iterator<T> temp = current++;

		erase(temp);
	}
}

template<class T>
void Forward_list<T>::pop_front()
{
	Node* temp = m_head;

	m_head = m_head->get_next();

	--m_size;

	delete temp;
}

template<class T>
void Forward_list<T>::clear()
{
	while (m_size > 0)
	{
		Forward_list<T>::pop_front();
	}
}

template<class T>
void Forward_list<T>::sort()
{
	if (m_size == 0)
	{
		return;
	}

	Forward_list new_list;

	while (m_size > 0)
	{
		Forward_list_iterator<T> max = begin();

		Forward_list_iterator<T> list_end = end();

		for (Forward_list_iterator<T> it = begin(); it != list_end; ++it)
		{
			if (*it > *max)
			{
				max = it;
			}
		}

		new_list.push_front(*max);

		erase(max);
	}

	*this = std::move(new_list);
}

template<class T>
void Forward_list<T>::reverse_sort()
{
	if (m_size == 0)
	{
		return;
	}

	Forward_list new_list;

	while (m_size > 0)
	{
		Forward_list_iterator<T> min = begin();

		Forward_list_iterator<T> list_end = end();

		for (Forward_list_iterator<T> it = begin(); it != list_end; ++it)
		{
			if (*it < *min)
			{
				min = it;
			}
		}

		new_list.push_front(*min);

		erase(min);
	}

	*this = std::move(new_list);
}

template<typename T>
Forward_list<T> conjoin(Forward_list<T>& l1, Forward_list<T>& l2)
{

	Forward_list<T> conjoined;

	for (T& i : l1)
	{
		conjoined.push_back(i);
	}
	for (T& i : l2)
	{
		conjoined.push_back(i);
	}

	return conjoined;

}

template<typename T>
Forward_list<T> intersect(Forward_list<T>& l1, Forward_list<T>& l2)
{

	Forward_list<T> new_list, l2_copy(l2);

	for (auto i : l1)
	{
		for (Forward_list_iterator<T> j = l2_copy.begin(), last = l2_copy.end(); j != last; ++j)
		{
			if (i == *j)
			{
				new_list.push_back(i);
				l2_copy.erase(j);
				break;
			}
		}
	}

	return std::move(new_list);

}


