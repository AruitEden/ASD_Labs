#pragma once





template <class T>
class RB_tree
{

private:
	
	template <class T>
	class Node
	{

	public:

		T key;
		Node<T>* left;
		Node<T>* right;
		Node<T>* parent;
		bool is_red;


	private:

		Node() : key(T()), left(nullptr), right(nullptr), parent(nullptr), is_red(false) {}

		static const Node<T>* const null_leaf = Node<T>();


	public:

		Node(const T& key, Node<T>* parent = nullptr)
			: key(key), left(null_leaf), right(null_leaf), parent(parent), is_red(true) {}



		void operator delete(void* node) 
		{
			if (((Node*)node) != null_leaf)
			{
				delete node;
			}
		}

	};





	const Node<T>* const null_leaf = Node<T>::null_leaf;

	Node<T>* root;





	void clear(Node<T>* root);

	int max_of(int a, int b)
	{
		return (a > b) ? a : b;
	}



	Node<T>* searching(Node<T>* root, const T& key);

	Node<T>* insertion(Node<T>*& root, const T& key)
	{

		if (root == null_leaf)
		{
			root = new Node<T>(key);
		}
		else if (key < root->key)
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



		if (root == this->root)
		{
			root->is_red = false;
			return root;
		}
		if (!root->parent->is_red)
		{
			return root;
		}

		bool L = (root == root->parent->left), R = (root == root->parent->right);

		if (L)
		{

			if (root->parent->parent->right != null_leaf)
			{

				if (root->parent->parent->right->is_red)
				{

					root->parent->is_red = false;
					root->parent->parent->is_red = true;
					root->parent->parent->is_red = true;
					return root;
					/*if (root->parent->parent != this->root)
					{
						root->parent->parent->is_red = true;
					}*/

				}

			}
			else 
			{

				bool LL = (root->parent == root->parent->parent->left), LR = (root->parent == root->parent->parent->right);

				if (LL)
				{
					root->parent->is_red = false;
					root->parent->parent->is_red = true;
					rotate_right(root->parent->parent);
					return root;
				}
				if (LR)
				{
					root->is_red = false;
					root->parent->parent->is_red = true;
					rotate_left(root->parent);
					rotate_right(root->parent->parent);
					return root;
				}



			}

		}

	}



	void preorder_travesal(Node<T>* root);

	void postorder_travesal(Node<T>* root);

	void inorder_travesal(Node<T>* root);

	void tree_printing(Node<T>* root, int space_count, int spacing = 5);

	

	int height(Node<T>* root)
	{

		//TODO

	}

	Node<T>* rotate_right(Node<T>* root);

	Node<T>* rotate_left(Node<T>* root);


public:

	RB_tree() : root(null_leaf) {}

	RB_tree(const T& key) : root(new Node<T>(key)) {}

	~RB_tree()
	{
		clear(root);
	}



	T* min();

	T* max();



	T* search(const T& key);

	void insert(const T& key)
	{
		insertion(root, key);
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



#include "RB_tree.inl"