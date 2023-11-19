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
		Node<T>* sibling;
		Node<T>* child;

		Node(const T& data)
			: data(data), sibling(nullptr), child(nullptr) {}

	};



	Node<T>* root;



	void insertion(Node<T>*& root, const T& value)
	{

		if (root == nullptr)
		{
			root = new Node<T>(value);
			return;
		}

		if (value > root->data)
		{
			insertion(root->child, value);
		}
		else
		{
			insertion(root->sibling, value);
		}
		
	}


public:

	General_tree() : root(nullptr) {}

	General_tree(const T& root) : root(new Node<T>(root)) {}



	void insert(const T& value)
	{

		if (root == nullptr)
		{
			root = new Node<T>(value);
			return;
		}

		insertion(root->child, value);

	}


};



#include "General_tree.inl"

