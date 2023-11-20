#include "Tree.h"


void Tree::deleteSubTree(Node* node)
{
    if (node)
    {
        deleteSubTree(node->left);
        deleteSubTree(node->right);

        delete node;
    }
}


void Tree::printNode(Node* node)
{
    if (node == nullptr)
    {
        return;
    }

    std::cout << node->key << " ";


    printNode(node->left);

    printNode(node->right);

}




void Tree::addNode(Node*& node, const int& data)
{
    if (node == nullptr)
    {
        node = new Node(data);
    }

    if (root->key == data)
    {
        return;
    }

    else if (data < node->key)
    {
        addNode(node->left, data);
    }

    else if(data > node->key)
    {
        addNode(node->right, data);
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
		deleteNode(node->left, data);
	}
	else if (data > node->key)
	{
        deleteNode(node->right, data);
	}
	else if (node->left != nullptr && node->right != nullptr)
	{
        Node* temp = node->right;

        while (temp->left != nullptr)
        {
            temp = temp->left;
        }

		node->key = temp->key;
        deleteNode(node->right, node->key);
	}
	else
	{
		Node* current = nullptr;
		if (node->left != nullptr)
		{
			current = node;
			node = current->left;
			delete current;
		}
		else if (node->right != nullptr)
		{
			current = node;
			node = current->right;
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
        searchNode(node->left, data);
    }
    else if (data > node->key)
    {
        searchNode(node->right, data);
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








