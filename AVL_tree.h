#pragma once





template <class T>
class AVL_tree
{

protected:

	template <typename T>
	struct Node
	{

		T key;
		Node<T>* left;
		Node<T>* right;
		int height;

		Node(const T& key)
			: key(key), left(nullptr), right(nullptr), height(1) {}

	};



	Node<T>* root;



	Node<T>* insertion(Node<T>*& root, const T& key)
	{

		if (root == nullptr)
		{
			return root = new Node<T>(key);
		}

		if (key < root->key)
		{
			root->left = insertion(root->left, key);
		}
		else if (key > root->key) 
		{
			root->right = insertion(root->right, key);
		}
		else 
		{
			return root;
		}

		root->height = 1 + max(height(root->left), height(root->right));

		int balance = balance_factor(root);
 

		// Left-left  
		if (balance > 1 && key < root->left->key) 
		{
			return root = rotate_right(root);
		}

		// Left-right  
		if (balance > 1 && key > root->left->key)
		{
			root->left = rotate_left(root->left);
			return root = rotate_right(root);
		}

		// Right-right  
		if (balance < -1 && key > root->right->key) 
		{
			return root = rotate_left(root);
		}

		// Right-left 
		if (balance < -1 && key < root->right->key)
		{
			root->right = rotate_right(root->right);
			return root = rotate_left(root);
		}

		return root;

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

	Node<T>* removal(Node<T>*& root, const T& key)
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

		if (root == nullptr)
		{
			return root;
		}

		root->height = max(height(root->left), height(root->right)) + 1;

		int balance = balance_factor(root);

		// Left-left
		if (balance > 1 && balance_factor(root->left) >= 0)
		{
			return root = rotate_right(root);
		}
		
		// Left-right
		if (balance > 1 && balance_factor(root->left) < 0)
		{
			root->left = rotate_left(root->left);
			return root = rotate_right(root);
		}

		// Right-right
		if (balance < -1 && balance_factor(root->right) <= 0)
		{
			return root = rotate_left(root);
		}

		// Right-left
		if (balance < -1 && balance_factor(root->right) > 0)
		{
			root->right = rotate_right(root->right);
			return root = rotate_left(root);
		}

		return root;

	}

	void clear(Node<T>* root)
	{

		if (root == nullptr)
		{
			return;
		}

		clear(root->left);

		clear(root->right);

		delete root;

	}





	int max(int a, int b)
	{
		return (a > b) ? a : b;
	}

	int balance_factor(Node<T>* root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		return height(root->left) - height(root->right);
	}

	int height(Node<T>* root) 
	{

		if (root == nullptr)
		{
			return 0;
		}

		return root->height;

	}

	Node<T>* rotate_right(Node<T>* root)
	{

		Node<T>* new_root = root->left;
		Node<T>* subtree = new_root->right;

		new_root->right = root;
		root->left = subtree;

		root->height = max(height(root->left), height(root->right)) + 1;
		new_root->height = max(height(new_root->left), height(new_root->right)) + 1;

		return new_root;

	}

	Node<T>* rotate_left(Node<T>* root)
	{

		Node<T>* new_root = root->right;
		Node<T>* subtree = new_root->left;

		new_root->left = root;
		root->right = subtree;

		root->height = max(height(root->left), height(root->right)) + 1;
		new_root->height = max(height(new_root->left), height(new_root->right)) + 1;

		return new_root;

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

	void tree_printing(Node<T>* root, int space_count, int spacing = 5)
	{

		if (root == nullptr)
		{
			return;
		}

		space_count += spacing;

		tree_printing(root->right, space_count);

		for (int i = 0; i < space_count; i++)
		{
			std::cout << ' ';
		}
		std::cout << root->key << '\n';

		tree_printing(root->left, space_count);

	}


public:

	AVL_tree() : root(nullptr) {}

	AVL_tree(const T& key) : root(new Node<T>(key)) {}

	~AVL_tree()
	{
		clear(root);
	}



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

	int tree_height()
	{
		return height(root);
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

	void print_tree() 
	{
		tree_printing(root, 0);
	}

};