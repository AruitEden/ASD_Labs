#pragma once
#include<cmath>
#include <iostream>


template<typename Value>
class Hash_Table
{
private:
	struct Node
	{
		int key;
		Value value;
		bool state;

		Node(int key, Value value, Node* next = nullptr): key(key), value(value), state(true){}
	};

	int size;
	int real_size;
	int all_size;

	Node** table;

	size_t HashFunction(const int& key) const;
	int hash_step(const int& key) const;

public:

	Hash_Table(int size = 10):size(size),real_size(0), all_size(0), table(new Node* [size] {}) {}
	~Hash_Table();


	void resize();
	void rehash();

	void clear();
	void insert(const int& key, const Value& value);
	const Value& search(const int& key) const;
	void remove(const int& key);

	void print();
};


#include"Hash_Table.inl"