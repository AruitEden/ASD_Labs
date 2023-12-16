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

template<typename T>
void swap(T& left, T& right)
{
	T temp = left;
	left = right;
	right = temp;
}



template<class T>
void RB_tree<T>::insertion(Node<T>* node)
{

	Node<T>* current = root;
	Node<T>* prev = nullptr;

	while (current != nullptr)
	{

		prev = current;
		if (node->key > current->key)
		{
			current = current->right;
		}
		else if (node->key < current->key)
		{
			current = current->left;
		}
		else
		{
			delete node;
			return;
		}

	}

	node->parent = prev;

	if (prev != nullptr)
	{

		if (node->key > prev->key)
		{
			prev->right = node;
		}
		else
		{
			prev->left = node;
		}

	}
	else
	{
		root = node;
	}

	node->is_red = true;

	insert_balancing(node);

}

template<class T>
void RB_tree<T>::insert_balancing(Node<T>* node)
{

	Node<T>* parent = node->parent;

	while (node != root && parent->is_red == true)
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
					swap(node, parent);
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
					swap(node, parent);
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
void RB_tree<T>::removal(Node<T>* node)
{

	Node<T>* child, *parent;
	bool color;
	
	if (node->left != nullptr && node->right != nullptr)
	{

		Node<T>* replace = node->right;

		while (replace->left != nullptr)
		{
			replace = replace->left;
		}
		
		if (node->parent != nullptr)
		{

			if (node->parent->left == node)
			{
				node->parent->left = replace;
			}
			else
			{
				node->parent->right = replace;
			}

		}
		else
		{
			root = replace;
		}
		
		child = replace->right;
		parent = replace->parent;
		color = replace->is_red;

		if (parent == node)
		{
			parent = replace;
		}
		else
		{
			
			if (child != nullptr)
			{
				child->parent = parent;
			}

			parent->left = child;
			replace->right = node->right;
			node->right->parent = replace;

		}

		replace->parent = node->parent;
		replace->is_red = node->is_red;
		replace->left = node->left;
		node->left->parent = replace;

		if (color == false)
		{
			remove_balancing(child, parent);
		}

		delete node;
		return;

	}
	
	if (node->left != nullptr)
	{
		child = node->left;
	}
	else
	{
		child = node->right;
	}

	parent = node->parent;
	color = node->is_red;

	if (child)
	{
		child->parent = parent;
	}
	
	if (parent)
	{

		if (node == parent->left)
		{
			parent->left = child;
		}
		else
		{
			parent->right = child;
		}

	}
	else
	{
		root = child;
	}

	if (color == false)
	{
		remove_balancing(child, parent);
	}

	delete node;

}

template<class T>
void RB_tree<T>::remove_balancing(Node<T>* node, Node<T>* parent)
{

	Node<T>* other;

	while ((node == nullptr || node->is_red == false) && node != root)
	{

		if (parent->left == node)
		{

			other = parent->right;

			if (other->is_red == true)
			{

				other->is_red = false;
				parent->is_red = true;

				rotate_left(root, parent);
				other = parent->right;

			}
			else
			{

				if (other->right == nullptr || other->right->is_red == false)
				{

					other->left->is_red = false;
					other->is_red = true;

					rotate_right(root, other);
					other = parent->right;

				}

				other->is_red = parent->is_red;
				parent->is_red = false;
				other->right->is_red = false;

				rotate_left(root, parent);
				node = root;
				break;

			}

		}
		else
		{

			other = parent->left;

			if (other->is_red == true)
			{

				other->is_red = false;
				parent->is_red = true;

				rotate_right(root, parent);
				other = parent->left;

			}

			if ((other->left == nullptr || other->left->is_red == false) && (other->right == nullptr || other->right->is_red == false))
			{
				other->is_red = true;
				node = parent;
				parent = node->parent;
			}
			else
			{

				if (other->left == nullptr || other->left->is_red == false)
				{

					other->right->is_red = false;
					other->is_red = true;

					rotate_left(root, other);
					other = parent->left;

				}

				other->is_red = parent->is_red;
				parent->is_red = false;
				other->left->is_red = false;

				rotate_right(root, parent);
				node = root;
				break;

			}

		}

	}

	if (node)
	{
		node->is_red = false;
	}

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


