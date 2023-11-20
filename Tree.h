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



	void insertion(Node<T>*& root, const T& key)
	{

		if (root == nullptr)
		{
			root = new Node<T>(key);
			return;
		}
		if (key > root->key)
		{
			insertion(root->right, key);
		}
		else if (key < root->key)
		{
			insertion(root->left, key);
		}
		else
		{
			return;
		}

	}

	Node<T>* searching(Node<T>* root, const T& key)
	{

		if (root == nullptr)
		{
			return nullptr;
		}
		if (key > root->key)
		{
			searching(root->right, key);
		}
		else if (key < root->key)
		{
			searching(root->left, key);
		}
		else
		{
			return root;
		}

	}


public:

	Tree() : root(nullptr)) {}

	Tree(const T& key) : root(new Node<T>(key)) {}



	T* min()
	{

		if (root == nullptr)
		{
			return nullptr;
		}

		Node<T>* current = root;

		while (current->left != nullptr)
		{
			current = current->left;
		}

		return current;

	}

	T* max()
	{

		if (root == nullptr)
		{
			return nullptr;
		}

		Node<T>* current = root;

		while (current->right != nullptr)
		{
			current = current->right;
		}

		return current;

	}



	T* search(const T& key)
	{

		Node<T>* result = searching(root, key);

		if (result == nullptr) 
		{
			return nullptr;
		}
		else
		{
			return result;
		}

	}

	void insert(const T& key)
	{
		insertion(root, key);
	}

	void remove(const T& key)
	{

		if (root == nullptr)
		{
			return;
		}



	}

};

