#pragma once



template <class K, class P>
class Treap 
{

private:

	template <typename K, typename P>
	struct Node
	{

		K key;
		P priority;
		Node<K, P>* left;
		Node<K, P>* right;

		Node(K key = K(), P priority = P(), Node<K, P>* left = nullptr, Node<K, P>* right = nullptr)
			: key(key), priority(priority), left(left), right(right) {}

	};



	Node<K, P>* root;

	P(*random_generator)();


	static Node<K, P>* merge(Node<K, P>* left, Node<K, P>* right)
	{

		if (left == nullptr)
		{
			return right;
		}
		if (right == nullptr)
		{
			return left;
		}

		if (left->priority > right->priority)
		{
			left->right = merge(left->right, right);
			return left;
		}
		else
		{
			right->left = merge(left, right->left);
			return right;
		}

	}
	
	static void split(Node<K, P>* root, const K& key, Node<K, P>*& r1, Node<K, P>*& r2)
	{

		if (root == nullptr)
		{
			r1 = r2 = nullptr;
			return;
		}

		if (root->key < key)
		{
			split(root->right, key, root->right, r2);
			r1 = root;
		}
		else
		{
			split(root->left, key, r1, root->left);
			r2 = root;
		}

	}

	void deletion(Node<K, P>* root)
	{
		if (root == nullptr)
		{
			return;
		}

		deletion(root->left);
		deletion(root->right);

		delete root;
	}



	void treap_printing(Node<K, P>* root, int space_count, int spacing = 10)
	{

		if (root == nullptr)
		{
			return;
		}

		space_count += spacing;

		treap_printing(root->right, space_count);

		for (int i = 0; i < space_count; i++)
		{
			std::cout << ' ';
		}

		std::cout << root->key << '/' << root->priority << '\n';

		treap_printing(root->left, space_count);

	}


public:

	Treap(P(*generator)()) : root(nullptr), random_generator(generator) {}



	void insert(const K& key)
	{
		Node<K, P>* left, *right;
		split(root, key, left, right);
		left = merge(left, new Node<K, P>(key, random_generator()));
		root = merge(left, right);
	}

	void erase(const K& key)
	{
		Node<K, P>* left, * mid, * right;
		split(root, key, left, right);
		split(right, key + 1, mid, right);
		root = merge(left, right);
		deletion(mid);
	}



	void print_tree()
	{
		treap_printing(root, 0);
	}


};