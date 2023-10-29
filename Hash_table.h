#pragma once
#include "Pair.h"
#include "Forward_list.h"





template <class TKey, class TValue>
class Hash_table
{

private:

	using bucket = Forward_list<Pair<TKey, TValue>>;



	static const int max_chains = 3;

	size_t m_size;

	bucket* m_table;
	

public:

	Hash_table(size_t size);

	Hash_table(const Hash_table<TKey, TValue>& other);
	Hash_table<TKey, TValue>& operator=(const Hash_table<TKey, TValue>& other);

	Hash_table(Hash_table<TKey, TValue>&& other);
	Hash_table<TKey, TValue>& operator=(Hash_table<TKey, TValue>&& other);

	~Hash_table();



	size_t get_hash(const TKey& key) const;

	bool contains_key(const TKey& key) const;



	TValue& at(const TKey& key);

	const TValue& at(const TKey& key) const;







	TValue& operator[](const TKey& key);

	

};



#include "Hash_table.inl"