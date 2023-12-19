#pragma once
#include <iostream>


class Treap
{
private:

	struct Node
	{
		int key;
		int priority;

		Node* left;
		Node* right;


		Node(int k, int p, Node*l = nullptr, Node*r = nullptr):key(k), priority(p), left(l), right(r){}
	};

	Node* root;


	static Node* merge(Node* a, Node* b);

	static void split(Node* n, int k, Node*& a, Node*& b);



	void printNode_l(const Node* node, int leve);


	void deleteSubTree(Node*& node);
public:

	Treap():root(nullptr)
	{

	}
	~Treap()
	{
		deleteSubTree(root);
	}



	void insert(int k, int p);

	void remove(int k);



	void print_l()
	{
		printNode_l(root, 0);
	}
};

