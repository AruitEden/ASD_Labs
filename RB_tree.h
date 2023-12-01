#pragma once





template <class T>
class RB_tree
{

private:
	
	template <typename T>
	struct Node
	{

		T key;
		Node<T>* left;
		Node<T>* right;
		bool is_red;


	private:

		Node() : key(T()), left(nullptr), right(nullptr), is_red(false) {}
		static const Node<T>* const null_leaf = Node<T>();


	public:

		Node(const T& key)
			: key(key), left(null_leaf), right(null_leaf), is_red(true) {}



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