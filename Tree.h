#pragma once
#include <iostream>

class Tree
{
private:
	struct Node
	{
		int key;
		Node* son;
		Node* brother;

		Node(int v, Node *s = nullptr, Node*b = nullptr): key(v), son(s), brother(b){}
	};

	Node* root;




	void deleteSubTree(Node* node);

	int height(Node* node);

	int level(Node* node, int l);

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
		if (!root)
		{
			root = new Node(data);
		}
		else if (root->key == data)
		{
			return;
		}
		else
		{
			addNode(root->son, data);
		}
	}

	void remove(const int& data) 
	{ 
		if (root->key == data)
		{
			deleteNode(root, data);
		}
		else
		{
			deleteNode(root->son, data);
		}
	}

	bool search(const int& data) { return searchNode(root, data); }


	int getHeight() { height(root); }

	int getLevel(int l) { level(root, l); }


	void print();


};

