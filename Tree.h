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



	void insert(const T& key)
	{
		insertion(root, key);
	}

	void remove(const T& key)
	{

	}

};

