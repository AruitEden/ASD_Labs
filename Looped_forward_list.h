#pragma once
#include "Forward_list.h"



template <typename T>
struct Looped_forward_list_traits
{

	using collection_base_type = typename Forward_list_traits<T>::collection_base_type;

	using element_type = typename Forward_list_traits<T>::element_type;

	using iterator_type = typename Forward_list_traits<T>::iterator_type;

};



template <class T>
using Looped_forward_list_iterator = Forward_list_iterator<T>;





template <class T>
class Looped_forward_list : protected Forward_list<T>
{

private:

	template<typename T> friend class Looped_forward_list;


protected:

	using Node = typename Forward_list<T>::Node;

	Node* m_tail;


public:

	Looped_forward_list<T>() : Forward_list<T>(), m_tail(nullptr) {}
	
	~Looped_forward_list<T>() 
	{
		clear();
	}



	virtual void push_front(const T& value) override;


	virtual void clear() override;

	virtual void pop_front() override;

	virtual void erase(Looped_forward_list_iterator<T> location) override;

	virtual Looped_forward_list_iterator<T> begin() override
	{
		return Looped_forward_list_iterator<T>(Forward_list<T>::m_head);
	}

	virtual size_t size() override 
	{
		return Forward_list<T>::m_size;
	}

};



#include "Looped_forward_list.inl"