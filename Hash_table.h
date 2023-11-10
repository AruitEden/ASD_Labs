#pragma once
#include "Pair.h"





template <class TKey, class TValue>
class Hash_table
{

private:

	size_t m_capacity;

	size_t m_size;

	Pair<TKey, TValue>** m_table;



	const Pair<TKey, TValue>* m_dummy;

	static const int probe_count = 3;



	bool is_prime(size_t n) const;

	size_t next_prime(size_t n) const;



	void rehash();
	

public:

	Hash_table(size_t size);

	Hash_table(const Hash_table<TKey, TValue>& other);
	Hash_table<TKey, TValue>& operator=(const Hash_table<TKey, TValue>& other);

	Hash_table(Hash_table<TKey, TValue>&& other);
	Hash_table<TKey, TValue>& operator=(Hash_table<TKey, TValue>&& other);

	~Hash_table();



	size_t get_hash(const TKey& key) const;

	bool contains_key(const TKey& key) const;



	size_t size() const;

	size_t max_size() const;



	TValue& at(const TKey& key);

	const TValue& at(const TKey& key) const;



	void insert(const Pair<TKey, TValue>& pair);

	void erase(const TKey& key);



	TValue& operator[](const TKey& key);

};



#include "Hash_table.inl"