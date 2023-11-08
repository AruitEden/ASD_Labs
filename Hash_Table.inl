#include "Hash_Table.h"

template<typename Value>
inline void Hash_Table<Value>::resize()
{
	int past_size = size;
	size = (size == 0) ? size += 3 : size *= 2;

	real_size = 0;
	all_size = 0;

	Node** NewArr = new Node * [size] {};

	std::swap(table, NewArr);


	for (int i = 0; i < past_size; ++i)
	{
		if (NewArr[i] && NewArr[i]->state)
		{
			insert(NewArr[i]->key, NewArr[i]->value);
		}
	}

	for (int i = 0; i < past_size; i++)
	{
		if (NewArr[i])
		{
			delete NewArr[i];
		}
	}

	delete[]NewArr;

}


template<typename Value>
inline void Hash_Table<Value>::rehash()
{
	real_size = 0;
	all_size = 0;

	Node** NewArr = new Node * [size] {};

	std::swap(table, NewArr);


	for (int i = 0; i < size; ++i)
	{
		if (NewArr[i] && NewArr[i]->state)
		{
			insert(NewArr[i]->key, NewArr[i]->value);
		}
	}

	for (int i = 0; i < size; i++)
	{
		if (NewArr[i])
		{
			delete NewArr[i];
		}
	}

	delete[]NewArr;
}



template<typename Value>
inline size_t Hash_Table<Value>::HashFunction(const int& key) const
{
	return key%size;
}

template<typename Value>
inline int Hash_Table<Value>::hash_step(const int& key) const
{
	int a = key % size - 1;
	return (size - 1) - a;
}



template<typename Value>
inline Hash_Table<Value>::~Hash_Table()
{
	clear();
	delete[] table;
}



template<typename Value>
inline void Hash_Table<Value>::clear()
{
	for (int i = 0; i < size; i++)
	{
		if (table[i])
		{
			delete table[i];
		}
	}
}



template<typename Value>
inline void Hash_Table<Value>::insert(const int& key, const Value& value)
{
	int c = 0.75 * size;

	if (real_size + 1 > c) { resize(); }
	else if (all_size > 2 * real_size) { rehash(); }

	size_t index = HashFunction(key);

	int first_del = -3;
	int i = 0;

	while (table[index] != nullptr && i < size)
	{
		if (table[index]->key == key && table[index]->state)
		{
			table[index]->value;
			return;
		}

		if (!table[i]->state && first_del == -3)
		{
			first_del = index;
		}

		index = (index + hash_step(key)) % size;
		i++;
	}

	if (first_del == -3)
	{
		table[index] = new Node(key, value);
		all_size++;
	}

	else
	{
		table[first_del]->key = key;
		table[first_del]->value = value;
		table[first_del]->state = true;
	}
	real_size++;
}



template<typename Value>
inline const Value& Hash_Table<Value>::search(const int& key) const
{
	size_t index = HashFunction(key);

	int i = 0;

	while (table[index] != nullptr && i < size)
	{
		if (table[index]->key == key && table[index]->state)
		{			
			return table[index]->value;
		}

		index = (index + hash_step(key)) % size;
		i++;
	}

	throw std::out_of_range("key was not found");
}



template<typename Value>
inline void Hash_Table<Value>::remove(const int& key)
{
	size_t index = HashFunction(key);

	int i = 0;

	while (table[index] != nullptr && i < size)
	{
		if (table[index]->key == key && table[index]->state)
		{
			table[index]->state = false;
			all_size--;
			return;
		}

		index = (index + hash_step(key)) % size;
		i++;
	}
}




template<typename Value>
inline void Hash_Table<Value>::print()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << i << ". ";

		if (table[i] && table[i]->state)
		{
			std::cout << table[i]->key << ", " << table[i]->value;
		}

		std::cout << "\n";
	}
}