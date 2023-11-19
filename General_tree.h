#pragma once



// TODO:
// 
// 1) operations:
// insert	DONE
// remove	DONE
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
		else if (value < root->data)
		{
			insertion(root->sibling, value);
		}
		else
		{
			return;
		}
		
	}

	void removal(Node<T>* root, Node<T>*& prev, const T& value)
	{

		if (root == nullptr)
		{
			return;
		}

		if (root->data == value)
		{

			bool sibling = prev->sibling == root;

			if (sibling) 
			{

				if (root->child != nullptr)
				{

					Node<T>* next = root->sibling;

					prev->sibling = root->child;

					Node<T>* i;
					for (i = root->child; i->sibling != nullptr; i = i->sibling);
					i->sibling = next;
					delete root;

					return;

				}
				else
				{
					prev->sibling = root->sibling;
					delete root;
					return;
				}

			}
			else
			{

				if (root->sibling != nullptr)
				{

					Node<T>* next = root->child;

					prev->child = root->sibling;

					Node<T>* i;
					for (i = root->sibling; i->child != nullptr; i = i->child);
					i->child = next;
					delete root;

					return;

				}
				else
				{
					prev->child = root->child;
					delete root;
					return;
				}

			}

		}

		if (value > root->data)
		{
			removal(root->child, root, value);
		}
		else
		{
			removal(root->sibling, root, value);
		}

	}

	bool search(Node<T>*& root, const T& value) const
	{

		if (root == nullptr)
		{
			return false;
		}

		if (value > root->data)
		{
			search(root->child, value);
		}
		else if (value < root->data)
		{
			search(root->sibling, value);
		}
		else
		{
			return true;
		}

	}



	bool preorder(Node<T>* root, const T& value) const
	{

		if (root == nullptr) 
		{
			return false;
		}

		std::cout << root->data << ' ';

		if (root->data == value)
		{
			return true;
		}

		if(!preorder(root->child, value))
		{
			return preorder(root->sibling, value);
		}
		else
		{
			return true;
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

	void remove(const T& value)
	{

		if (root->data == value)
		{
			root->data = root->child->data;
			removal(root->child, root, root->data);
			return;
		}

		removal(root->child, root, value);

	}

	bool contains(const T& value) const
	{

		if (root == nullptr)
		{
			return false;
		}
		if (root->data == value)
		{
			return true;
		}

		return search(root->child, value);

	}

	bool preorder_search(const T& value) const // Прямий обхід
	{

		if (root == nullptr)
		{
			return false;
		}

		std::cout << root->data << ' ';

		if (root->data == value)
		{
			return true;
		}

		return preorder(root->child, value);

	}


};



#include "General_tree.inl"

