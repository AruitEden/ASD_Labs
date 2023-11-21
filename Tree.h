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

	Node<T>* removal(Node<T>* root, const T& key)
	{

		if (root == nullptr)
		{
			return nullptr;
		}

		if (root->key > key)
		{
			root->left = removal(root->left, key);
		}
		else if (root->key < key)
		{
			root->right = removal(root->right, key);
		}
		else
		{

			if (root->left == nullptr)
			{
				Node<T>* temp = root->right;
				delete root;
				return temp;
			}
			else if (root->right == nullptr)
			{
				Node<T>* temp = root->left;
				delete root;
				return temp;
			}
			else
			{

				Node<T>* temp = root->right;

				while (temp->left != nullptr)
				{
					temp = temp->left;
				}

				root->key = temp->key;
				root->right = removal(root->right, temp->key);

			}

		}

		return root;

	}



	void preorder_travesal(Node<T>* root)
	{

		if (root == nullptr)
		{
			return;
		}

		std::cout << root->key << " ";

		preorder_travesal(root->left);

		preorder_travesal(root->right);

	}

	void postorder_travesal(Node<T>* root)
	{

		if (root == nullptr)
		{
			return;
		}

		postorder_travesal(root->left);

		postorder_travesal(root->right);

		std::cout << root->key << ' ';

	}

	void inorder_travesal(Node<T>* root)
	{

		if (root == nullptr)
		{
			return;
		}

		inorder_travesal(root->left);

		std::cout << root->key << ' ';

		inorder_travesal(root->right);

	}


public:

	Tree() : root(nullptr) {}

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
			return &result->key;
		}

	}

	void insert(const T& key)
	{
		insertion(root, key);
	}

	void remove(const T& key)
	{
		removal(root, key);
	}



	void print_preorder()
	{
		preorder_travesal(root);
	}

	void print_postorder()
	{
		postorder_travesal(root);
	}

	void print_inorder()
	{
		inorder_travesal(root);
	}

};