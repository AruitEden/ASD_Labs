#include "Hash_table.h"





template<class TKey, class TValue>
Hash_table<TKey, TValue>::Hash_table(size_t size) : m_capacity(size), m_size(0), m_table(new bucket[m_capacity]{}) {}



template<class TKey, class TValue>
Hash_table<TKey, TValue>::Hash_table(const Hash_table<TKey, TValue>& other) : m_capacity(other.m_capacity), m_size(other.m_size), m_table(new bucket[m_capacity])
{
	for (size_t i = 0; i < m_capacity; ++i)
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
	m_capacity = other.m_capacity;
	m_size = other.m_size;
	m_table = new bucket[m_capacity];
	for (size_t i = 0; i < m_capacity; ++i)
	{
		m_table[i] = other.m_table[i];
	}

	return *this;

}



template<class TKey, class TValue>
Hash_table<TKey, TValue>::Hash_table(Hash_table<TKey, TValue>&& other) : m_capacity(other.m_capacity), m_size(other.m_size), m_table(other.m_table)
{
	// TODO: Rehash here
	/*other.m_size = 0;
	other.m_size = 0; 
	other.m_table = nullptr;*/
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

	// TODO: Rehash here

	return *this;

}



template<class TKey, class TValue>
Hash_table<TKey, TValue>::~Hash_table()
{
	delete[] m_table;
}



template<class TKey, class TValue>
size_t Hash_table<TKey, TValue>::get_hash(const TKey& key) const
{
	return key % m_capacity;
}



template<class TKey, class TValue>
bool Hash_table<TKey, TValue>::contains_key(const TKey& key) const
{

	for (auto& i : m_table[get_hash(key)])
	{
		if (i.first == key)
		{
			return true;
		}
	}

	return false;

}



template<class TKey, class TValue>
size_t Hash_table<TKey, TValue>::size() const
{
	return m_size;
}



template<class TKey, class TValue>
size_t Hash_table<TKey, TValue>::max_size() const
{
	return m_capacity * max_nodes;
}



template<class TKey, class TValue>
TValue& Hash_table<TKey, TValue>::at(const TKey& key)
{

	for (auto& i : m_table[get_hash(key)])
	{
		if(i.first == key)
		{
			return i.second;
		}
	}

	throw std::out_of_range("There isn't a value with such key");
	
}

template<class TKey, class TValue>
const TValue& Hash_table<TKey, TValue>::at(const TKey& key) const
{

	for (auto& i : m_table[get_hash(key)])
	{
		if (i.first == key)
		{
			return i.second;
		}
	}

	throw std::out_of_range("There isn't a value with such key");

}



template<class TKey, class TValue>
TValue& Hash_table<TKey, TValue>::operator[](const TKey& key)
{

	try
	{
		return at(key);
	}
	catch(const std::out_of_range& e)
	{
		// TODO: Insert here
	}

}








