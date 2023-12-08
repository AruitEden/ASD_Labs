#pragma once





template <class T>
class RB_tree
{

private:

	template <class T>
	class Node
	{

		T key;
		Node<T>* left;
		Node<T>* right;
		Node<T>* parent;
		bool is_red;



		Node(const T& key, Node<T>* parent = nullptr)
			: key(key), left(nullptr), right(nullptr), parent(parent), is_red(true) {}

	};



	Node<T>* root;





	void clear(Node<T>* root);



	Node<T>* searching(Node<T>* root, const T& key);

	void insertion(Node<T>*& root, Node<T>* node);

	void insert_balancing(Node<T>*& root, Node<T>* node);

	

	void rotate_left(Node<T>*& root, Node<T>* x);

	void rotate_right(Node<T>*& root, Node<T>* y);



	void preorder_travesal(Node<T>* root);

	void postorder_travesal(Node<T>* root);

	void inorder_travesal(Node<T>* root);

	void tree_printing(Node<T>* root, int space_count, int spacing = 5);


public:

	RB_tree() : root(nullptr) {}

	RB_tree(const T& key) : root(new Node<T>(key)) {}

	~RB_tree()
	{
		clear(root);
	}



	T* min();

	T* max();



	T* search(const T& key);

	void insert(T key)
	{
		Node<T>* z = new Node<T>(key);
		insertion(root, z);
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