#include "Tree.h"


void Tree::deleteSubTree(Node* node)
{
    if (node)
    {
        deleteSubTree(node->son);
        deleteSubTree(node->brother);

        delete node;
    }
}


int Tree::height(Node* node)
{
    if (node == nullptr)
    {
        return 0;
    }

    int max = 0;

    for (Node* current = node->son; current; current->brother)
    {
        int currentHeight = height(current);

        if (currentHeight > max)
        {
            max = currentHeight;
        }
    }

    return max + 1;
}


int Tree::level(Node* node, int l)
{
    if (node == nullptr) return 0;
    if (l <= 0) return 0;

    return level(node->son, l - 1) + (l == 1) + level(node->brother, l);
}




void Tree::printNode(Node* node)
{
    if (node == nullptr)
    {
        return;
    }

    std::cout << node->key << " ";


    printNode(node->son);

    printNode(node->brother);

}




void Tree::addNode(Node*& node, const int& data)
{
    if (node == nullptr)
    {
        node = new Node(data);
    }

    else if (data < node->key)
    {
        addNode(node->son, data);
    }

    else if(data > node->key)
    {
        addNode(node->brother, data);
    }

    else
    {
        return;
    }
}


void Tree::deleteNode(Node*& node, const int& data)
{
    if (node == nullptr)
    {
        return;
    }

	if (data < node->key)
	{
		deleteNode(node->son, data);
	}
	else if (data > node->key)
	{
        deleteNode(node->brother, data);
	}
	else if (node->son != nullptr && node->brother != nullptr)
	{
        Node* temp = node->brother;

        while (temp->son != nullptr)
        {
            temp = temp->son;
        }

		node->key = temp->key;
        deleteNode(node->brother, node->key);
	}
	else
	{
		Node* current = nullptr;
		if (node->son != nullptr)
		{
			current = node;
			node = current->son;
			delete current;
		}
		else if (node->brother != nullptr)
		{
			current = node;
			node = current->brother;
			delete current;
		}
		else
		{
			delete node;
			node = nullptr;
		}
	}

    return;
}


bool Tree::searchNode(Node*& node, const int& data)
{
    if (node == nullptr)
    {
        return false;
    }

    if (data < node->key)
    {
        searchNode(node->son, data);
    }
    else if (data > node->key)
    {
        searchNode(node->brother, data);
    }
    else if (node->key == data)
    {
        return true;
    }
}




void Tree::print()
{
    if (root == nullptr)
    {
        return;
    }


    printNode(root);
}








