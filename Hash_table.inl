#include "Hash_table.h"





template<class TKey, class TValue>
Hash_table<TKey, TValue>::Hash_table(size_t size) : m_capacity(size), m_size(0), m_table(new Pair<TKey, TValue>*[size] {}) {}



template<class TKey, class TValue>
Hash_table<TKey, TValue>::Hash_table(const Hash_table<TKey, TValue>& other)
	: m_capacity(other.m_capacity), m_size(other.m_size), m_table(new Pair<TKey, TValue>*[other.m_size])
{

	for (size_t i = 0; i < m_capacity; i++)
	{

		if(other.m_table[i] != nullptr)
		{
			m_table[i] = new Pair<TKey, TValue>(*other.m_table[i]);
		}
		else
		{
			m_table[i] = nullptr;
		}

	}

}

template<class TKey, class TValue>
Hash_table<TKey, TValue>& Hash_table<TKey, TValue>::operator=(const Hash_table<TKey, TValue>& other)
{

	if (m_table == other.m_table)
	{
		return *this;
	}


	for (size_t i = 0; i < m_capacity; i++)
	{
		delete m_table[i];
	}
	delete[] m_table;

	m_capacity = other.m_capacity;
	m_size = other.m_size;
	m_table = new Pair<TKey, TValue>*[other.m_capacity];

	for (size_t i = 0; i < m_capacity; i++)
	{

		if (other.m_table[i] != nullptr)
		{
			m_table[i] = new Pair<TKey, TValue>(*other.m_table[i]);
		}
		else
		{
			m_table[i] = nullptr;
		}

	}

	return *this;

}



template<class TKey, class TValue>
Hash_table<TKey, TValue>::Hash_table(Hash_table<TKey, TValue>&& other)
	: m_capacity(other.m_capacity), m_size(other.m_size), m_table(other.m_table)
{
	other.m_capacity = 1;
	other.m_size = 0;
	other.m_table = new Pair<TKey, TValue>* [1] {};
}

template<class TKey, class TValue>
Hash_table<TKey, TValue>& Hash_table<TKey, TValue>::operator=(Hash_table<TKey, TValue>&& other)
{
	
	if (m_table == other.m_table)
	{
		return *this;
	}

	for (size_t i = 0; i < m_capacity; i++)
	{
		delete m_table[i];
	}
	delete[] m_table;

	m_capacity = other.m_capacity;
	m_size = other.m_size;
	m_table = other.m_table;

	other.m_capacity = 1;
	other.m_size = 0;
	other.m_table = new Pair<TKey, TValue>* [1] {};

	return *this;

}



template<class TKey, class TValue>
Hash_table<TKey, TValue>::~Hash_table()
{

	for (size_t i = 0; i < m_capacity; i++)
	{
		delete m_table[i];
	}

	delete[] m_table;

}



template<class TKey, class TValue>
size_t Hash_table<TKey, TValue>::get_hash(const TKey& key) const
{
	return key % m_capacity;
}



template<class TKey, class TValue>
size_t Hash_table<TKey, TValue>::size() const
{
	return m_size;
}

template<class TKey, class TValue>
size_t Hash_table<TKey, TValue>::max_size() const
{
	return m_capacity;
}
