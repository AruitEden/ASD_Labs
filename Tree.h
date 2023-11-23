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


	Node* rot_r(Node* node);

	Node* rot_l(Node* node);



	Node* balance(Node* node);



	void deleteSubTree(Node* node);

	void printNode(Node* node);



	void addNode(Node*& node, const int& data);

	void deleteNode(Node*& node, const int& data);

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
		deleteNode(root, data);
	}



	bool search(const int& data) { return searchNode(root, data); }


	void print();


};

