#pragma once
#include "Forward_list.h"



template <class T>
class Circular_forward_list : protected Forward_list<T>
{

private:

	template<typename T> friend class Circular_forward_list;


protected:

	using Node = typename Forward_list<T>::Node;

	Node* m_tail;


public:

	Circular_forward_list<T>() : Forward_list<T>(), m_tail(nullptr) {}
	
	~Circular_forward_list<T>() 
	{
		clear();
	}



	virtual void push_front(const T& value) override
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

	virtual void clear() override
	{
		if (Forward_list<T>::m_size > 0) {

			m_tail->set_next(nullptr);

			this->Forward_list<T>::clear();

		}
	}

	virtual void pop_front() override
	{
		if(Forward_list<T>::m_size == 1)
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

	virtual void erase(Forward_list_iterator<T> location) override
	{
		Forward_list<T>::erase(location);

		if(Forward_list<T>::m_size > 0)
		{
			Forward_list_iterator<T> it = begin();

			while(it.m_element->get_next() != Forward_list<T>::m_head)
			{
				++it;
			}

			m_tail = it.m_element;
		}
	}

	virtual Forward_list_iterator<T> begin() override
	{
		return Forward_list_iterator<T>(Forward_list<T>::m_head);
	}

	virtual size_t size() override 
	{
		return Forward_list<T>::m_size;
	}

};

