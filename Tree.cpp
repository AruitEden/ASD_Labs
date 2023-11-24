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




void Tree::rot_r(Node*(&node))
{
    Node* l_sub = node->left;
    Node* l_sub_r_sub = l_sub->right;

    l_sub->right = node;
    node->left = l_sub_r_sub;
    node = l_sub;

    count_height(node->right);
    count_height(node);
}


void Tree::rot_l(Node*(&node))
{
    Node* r_sub = node->right;
    Node* r_sub_l_sub = r_sub->left;

    r_sub->left = node;
    node->right = r_sub_l_sub;
    node = r_sub;

    count_height(node->left);
    count_height(node);
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


void Tree::printNode_l(const Node* node, int n, int level, int prob)
{
    if (node)
    {
        if (level == n)
        {
            for (int i = 0; i <= prob; i++)
            {
                std::cout << " ";  
            }
            std::cout << node->key;
        }
        else
        {
            printNode_l(node->left, n, level + 1, prob);
            printNode_l(node->right, n, level + 1, prob);
        }
    }
}




void Tree::addNode(Node*& node, const int& data)
{
    if (node == nullptr)
    {
        node = new Node(data);
    }

    else
    {
        if (root->key == data)
        {
            return;
        }

        else if (data < node->key)
        {
            addNode(node->left, data);

            if (bfac(node) < -1)
            {
                if (height(node->left->left) < height(node->left->right))
                {
                    rot_l(node->left);
                }
                rot_r(node);
            }
        }

        else if (data > node->key)
        {
            addNode(node->right, data);

            if (bfac(node) > 1)
            {
                if (height(node->right->right) < height(node->right->left))
                {
                    rot_r(node->right);
                }
                rot_l(node);
            }
        }

        count_height(node);
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

void Tree::print_l()
{
    int h = height(root);
    int prob = 3;
    if (root)
    {
        for (int i = 0; i <= h; i++)
        {
            printNode_l(root, i, 0, prob * (h - i));
            std::cout << std::endl;
        }
    }
}








