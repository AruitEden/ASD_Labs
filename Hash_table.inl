#include "Hash_table.h"





template<class TKey, class TValue>
Hash_table<TKey, TValue>::Hash_table(size_t size) :
	m_capacity(size), m_size(0), m_table(new Pair<TKey, TValue>*[size] {}), m_dummy(new Pair<TKey, TValue>()) {}


/*
template<class TKey, class TValue>
Hash_table<TKey, TValue>::Hash_table(const Hash_table<TKey, TValue>& other)
	: m_capacity(other.m_capacity), m_size(other.m_size), m_table(new Pair<TKey, TValue>*[other.m_size]), m_dummy(new Pair<TKey, TValue>(-1, -1))
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
*/


template<class TKey, class TValue>
Hash_table<TKey, TValue>::~Hash_table()
{

	delete m_dummy;
	m_dummy = nullptr;

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



template<class TKey, class TValue>
bool Hash_table<TKey, TValue>::is_prime(size_t n) const
{

	if (n == 1)
	{
		return false;
	}

	for (size_t i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}

	return true;

}

template<class TKey, class TValue>
size_t Hash_table<TKey, TValue>::next_prime(size_t n) const
{

	while (!is_prime(n))
	{
		++n;
	}

	return n;

}

template<class TKey, class TValue>
size_t Hash_table<TKey, TValue>::make_step(size_t index) const
{

	return next_prime(m_capacity + 1) % m_capacity;

}



template <class TKey, class TValue>
TValue& Hash_table<TKey, TValue>::at(const TKey& key)
{

	size_t original_index = get_hash(key);
	size_t index = original_index;
	size_t step = make_step(index);

	do {

		if (m_table[index] != nullptr)
		{
			if (m_table[index] != m_dummy )
			{
				if (m_table[index]->first == key)
				{
					return m_table[index]->second;
				}
			}
		}
		else
		{
			break;
		}

		index = (index + step) % m_capacity;

	} while (index != original_index);

	throw std::out_of_range("There isn't a value with such key");

}



template<class TKey, class TValue>
void Hash_table<TKey, TValue>::insert(const Pair<TKey, TValue>& pair)
{

	if (float(m_size) / float(m_capacity) > 0.7f)
	{
		//TODO: rehash();
	}


	size_t original_index = get_hash(pair.first);
	size_t index = original_index;
	size_t step = make_step(index);

	do {

		if (m_table[index] == nullptr || m_table[index] == m_dummy)
		{
			m_table[index] = new Pair<TKey, TValue>(pair);
			return;
		}

		index = (index + step) % m_capacity;

	} while (index != original_index);

}
