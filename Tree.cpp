#include "Tree.h"


int Tree::height(Node* node)
{
    return node?node->height:0;
}

int Tree::bfac(Node* node)
{
    return height(node->right) - height(node->left);
}

void Tree::count_height(Node* node)
{
    int hl = height(node->left);
    int hr = height(node->right);

    if (hl > hr)
    {
        node->height = hl + 1;
    }
    else
    {
        node->height = hr + 1;
    }
}




Tree::Node* Tree::rot_r(Node* node)
{
    Node* temp = node->left;
    node->left = temp->right;
    temp->right = node;

    count_height(node);
    count_height(temp);

    return temp;
}

Tree::Node* Tree::rot_l(Node* node)
{
    Node* temp = node->right;
    node->right = temp->left;
    temp->left = node;

    count_height(node);
    count_height(temp);

    return temp;
}




Tree::Node* Tree::balance(Node* node)
{
    count_height(node);

    if (bfac(node) == 2)
    {
        if (bfac(node->right) < 0)
        {
            node->right = rot_r(node->right);
        }
        return rot_l(node);
    }

    if (bfac(node) == -2)
    {
        if (bfac(node->left) > 0)
        {
            node->left = rot_l(node->left);
        }
        return rot_r(node);
    }

    return node;
}




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








