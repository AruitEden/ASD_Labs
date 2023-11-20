#pragma once



template <class T>
class Tree
{

private:

	template <typename T>
	struct Node
	{

		T key;
		Node<T>* left;
		Node<T>* right;

		Node(const T& key)
			: key(key), left(nullptr), right(nullptr) {}

	};



	Node<T>* root;


public:

	Tree() : root(nullptr)) {}

	Tree(const T& key) : root(new Node<T>(key)) {}

};

