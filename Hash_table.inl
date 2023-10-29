#include "Hash_table.h"





template<class TKey, class TValue>
Hash_table<TKey, TValue>::Hash_table(size_t size) : m_size(size), m_table(new bucket[size]{}) {}



template<class TKey, class TValue>
Hash_table<TKey, TValue>::Hash_table(const Hash_table<TKey, TValue>& other) : m_size(other.m_size), m_table(new bucket[other.m_size])
{
	for (size_t i = 0; i < m_size; ++i)
	{
		m_table[i] = other.m_table[i];
	}
}

template<class TKey, class TValue>
Hash_table<TKey, TValue>& Hash_table<TKey, TValue>::operator=(const Hash_table<TKey, TValue>& other)
{

	if(this == &other)
	{
		return *this;
	}

	delete[] m_table;
	m_size = other.m_size;
	m_table = new bucket[other.m_size];
	for (size_t i = 0; i < m_size; ++i)
	{
		m_table[i] = other.m_table[i];
	}

	return *this;

}



template<class TKey, class TValue>
Hash_table<TKey, TValue>::Hash_table(Hash_table<TKey, TValue>&& other) : m_size(other.m_size), m_table(other.m_table)
{
	other.m_size = 0;
	other.m_table = nullptr;
}

template<class TKey, class TValue>
Hash_table<TKey, TValue>& Hash_table<TKey, TValue>::operator=(Hash_table<TKey, TValue>&& other)
{

	if (this == &other)
	{
		return *this;
	}

	delete[] m_table;
	m_size = other.m_size;
	m_table = other.m_table;

	other.m_size = 0;
	other.m_table = nullptr;

	return *this;

}



template<class TKey, class TValue>
Hash_table<TKey, TValue>::~Hash_table()
{
	delete[] m_table;
}

template<class TKey, class TValue>
inline size_t Hash_table<TKey, TValue>::get_hash(const TKey& key) const
{
	return key % m_size;
}


