#pragma once
#include <iostream>
#include <stack>

class Tree
{
private:
	struct Node
	{
		int key;

		int height;

		Node* left;
		Node* right;

		Node(int v, Node *s = nullptr, Node*b = nullptr): key(v), height(1), left(s), right(b){}
	};

	Node* root;

	int height(Node* node);

	int bfac(Node* node);

	void count_height(Node* node);


	void rot_r(Node*(& node));

	void rot_l(Node*(& node));



	Node* find_min(Node* node);

	Node* remove_min(Node* node);



	void deleteSubTree(Node* node);

	void printNode(Node* node);

	void printNode_l(const Node* node, int n, int level, int prob);



	void addNode(Node*& node, const int& data);

	Node* deleteNode(Node* node, const int& data);

	bool searchNode(Node*& node, const int& data);




public:

	Tree(): root(nullptr){}

	~Tree()
	{
		deleteSubTree(root);
	}



	void add(const int& data) 
	{ 
		addNode(root, data);
	}

	void remove(const int& data) 
	{ 
		root = deleteNode(root, data);
	}



	bool search(const int& data) { return searchNode(root, data); }


	void print();
	void print_l();

};

