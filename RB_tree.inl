#include "RB_tree.h"





template<class T>
void RB_tree<T>::clear(Node<T>* root)
{

	if (root == null_leaf)
	{
		return;
	}

	clear(root->left);

	clear(root->right);

	delete root;

}



template<class T>
RB_tree<T>::Node<T>* RB_tree<T>::searching(Node<T>* root, const T& key)
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



template<class T>
void RB_tree<T>::preorder_travesal(Node<T>* root)
{

	if (root == null_leaf)
	{
		return;
	}

	std::cout << root->key << " ";

	preorder_travesal(root->left);

	preorder_travesal(root->right);

}

template<class T>
void RB_tree<T>::postorder_travesal(Node<T>* root)
{

	if (root == null_leaf)
	{
		return;
	}

	postorder_travesal(root->left);

	postorder_travesal(root->right);

	std::cout << root->key << ' ';

}

template<class T>
void RB_tree<T>::inorder_travesal(Node<T>* root)
{

	if (root == null_leaf)
	{
		return;
	}

	inorder_travesal(root->left);

	std::cout << root->key << ' ';

	inorder_travesal(root->right);

}

template<class T>
void RB_tree<T>::tree_printing(Node<T>* root, int space_count, int spacing)
{

	if (root == null_leaf)
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



template<class T>
RB_tree<T>::Node<T>* RB_tree<T>::rotate_right(Node<T>* root)
{

	Node<T>* new_root = root->left;
	Node<T>* subtree = new_root->right;

	new_root->right = root;
	root->left = subtree;

	return new_root;

}

template<class T>
RB_tree<T>::Node<T>* RB_tree<T>::rotate_left(Node<T>* root)
{

	Node<T>* new_root = root->right;
	Node<T>* subtree = new_root->left;

	new_root->left = root;
	root->right = subtree;

	return new_root;

}





template<class T>
T* RB_tree<T>::min()
{

	if (root == null_leaf)
	{
		return null_leaf;
	}

	Node<T>* current = root;

	while (current->left != null_leaf)
	{
		current = current->left;
	}

	return current;

}

template<class T>
T* RB_tree<T>::max()
{

	if (root == null_leaf)
	{
		return null_leaf;
	}

	Node<T>* current = root;

	while (current->right != null_leaf)
	{
		current = current->right;
	}

	return current;

}



template<class T>
T* RB_tree<T>::search(const T& key)
{

	Node<T>* result = searching(root, key);

	if (result == null_leaf)
	{
		return null_leaf;
	}
	else
	{
		return &result->key;
	}

}


