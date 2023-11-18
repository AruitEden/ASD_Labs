#pragma once



// TODO:
// 
// 1) operations:
// insert
// erase
// search
// 
// 2) traversals:
// inorder
// postorder
// preorder
// 
// 
//




template <class T>
class General_tree
{

private:

	template <typename T>
	struct Node
	{

		T data;
		Node<T>* parent;
		Node<T>* sibling;
		Node<T>* child;

		Node(const T& data)
			: data(data), parent(nullptr), sibling(nullptr), child(nullptr) {}

	};



	Node<T>* root;


public:

	General_tree() : root(nullptr) {}

	General_tree(const T& root) : root(new Node<T>(root)) {}


	void insert(const T& value)
	{

		Node<T>* current = root;

		while(current != nullptr)
		{

		}



	}


};



#include "General_tree.inl"

