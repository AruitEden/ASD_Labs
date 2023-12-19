#include "Treap.h"

void Treap::deleteSubTree(Node*& node)
{
	if (node)
	{
		deleteSubTree(node->left);
		deleteSubTree(node->right);

		delete node;
	}
}



Treap::Node* Treap::merge(Node* a, Node* b)
{
	if (!a || !b)
	{
		return a ? a : b;
	}

	if (a->priority > b->priority)
	{
		a->right = merge(a->right, b);
		return a;
	}
	else
	{
		b->left = merge(a, b->left);
		return b;
	}
}


void Treap::split(Node* n, int k, Node*& a, Node*& b)
{
	if (!n)
	{
		a = nullptr;
		b = nullptr;

		return;
	}

	if (n->key < k)
	{
		split(n->right, k, n->right, b);
		a = n;
	}
	else
	{
		split(n->left, k, a, n->left);
		b = n;
	}
}




void Treap::insert(int k, int p)
{
	Node* less, * more;
	split(root, k, less, more);


	less = merge(less, new Node(k, p));
	root = merge(less, more);
}


void Treap::remove(int k)
{
	Node* less, * equal, * more;

	split(root, k, less, more);
	split(more, k + 1, equal, more);

	root = merge(less, more);
}




void Treap::printNode_l(const Node* node, int level)
{
	if (node)
	{
		printNode_l(node->right, level + 1);
		std::cout << std::endl;

		std::cout << "    ";

		for (int i = 0; i < level; i++)
		{
			std::cout << "    ";
		}
		std::cout << node->key << " (" << node->priority << ")";

		printNode_l(node->left, level + 1);
	}
}


