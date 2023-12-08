#include "RB_tree.h"





template<class T>
void RB_tree<T>::clear(Node<T>* root)
{

	if (root == nullptr)
	{
		return;
	}

	clear(root->left);

	clear(root->right);

	delete root;

}



template<class T>
typename RB_tree<T>::template Node<T>* RB_tree<T>::searching(Node<T>* root, const T& key)
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
void RB_tree<T>::insertion(Node<T>*& root, Node<T>* node)
{

	Node<T>* x = root;
	Node<T>* y = nullptr;

	while (x != nullptr)
	{

		y = x;
		if (node->key > x->key)
		{
			x = x->right;
		}
		else if (node->key < x->key)
		{
			x = x->left;
		}
		else
		{
			delete node;
			return;
		}

	}

	node->parent = y;

	if (y != nullptr)
	{
		if (node->key > y->key)
		{
			y->right = node;
		}
		else
		{
			y->left = node;
		}
	}
	else
	{
		root = node;
	}
	node->is_red = true;
	insert_balancing(root, node);

}

template<class T>
void RB_tree<T>::insert_balancing(Node<T>*& root, Node<T>* node)
{

	Node<T>* parent;
	parent = node->parent;
	while (node != this->root && parent->is_red == true)
	{
		Node<T>* gparent = parent->parent;
		if (gparent->left == parent)
		{
			Node<T>* uncle = gparent->right;
			if (uncle != nullptr && uncle->is_red == true)
			{

				parent->is_red = false;
				uncle->is_red = false;
				gparent->is_red = true;
				node = gparent;
				parent = node->parent;

			}
			else
			{

				if (parent->right == node)
				{
					rotate_left(root, parent);
					std::swap(node, parent); // TODO: my own version of swap
				}
				rotate_right(root, gparent);
				gparent->is_red = true;
				parent->is_red = false;
				break;

			}
		}
		else
		{
			Node<T>* uncle = gparent->left;
			if (uncle != nullptr && uncle->is_red == true)
			{

				gparent->is_red = true;
				parent->is_red = false;
				uncle->is_red = false;

				node = gparent;
				parent = node->parent;

			}
			else
			{

				if (parent->left == node)
				{
					rotate_right(root, parent);
					std::swap(parent, node);
				}
				rotate_left(root, gparent);
				parent->is_red = false;
				gparent->is_red = true;
				break;

			}
		}
	}

	root->is_red = false;

}



template<class T>
void RB_tree<T>::rotate_left(Node<T>*& root, Node<T>* x) 
{

	Node<T>* y = x->right;
	x->right = y->left;
	if (y->left != nullptr)
	{
		y->left->parent = x;
	}

	y->parent = x->parent;
	if (x->parent == nullptr)
	{
		root = y;
	}
	else 
	{
		if (x == x->parent->left)
		{
			x->parent->left = y;
		}
		else
		{
			x->parent->right = y;
		}
	}
	y->left = x;
	x->parent = y;

}

template<class T>
void RB_tree<T>::rotate_right(Node<T>*& root, Node<T>* y)
{

	Node<T>* x = y->left;
	y->left = x->right;
	if (x->right != nullptr)
	{
		x->right->parent = y;
	}

	x->parent = y->parent;
	if (y->parent == nullptr)
	{
		root = x;
	}
	else 
	{
		if (y == y->parent->right)
		{
			y->parent->right = x;
		}
		else
		{
			y->parent->left = x;
		}
	}
	x->right = y;
	y->parent = x;

}



template<class T>
void RB_tree<T>::preorder_travesal(Node<T>* root)
{

	if (root == nullptr)
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

	if (root == nullptr)
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

	if (root == nullptr)
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

	if (root->is_red)
	{
		std::cout << "\033[1;31m";
	}
	std::cout << root->key << "\033[1;0m" << '\n';

	tree_printing(root->left, space_count);

}





template<class T>
T* RB_tree<T>::min()
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

template<class T>
T* RB_tree<T>::max()
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



template<class T>
T* RB_tree<T>::search(const T& key)
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


