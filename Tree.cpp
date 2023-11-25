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




Tree::Node* Tree::find_min(Node* node)
{
    return node->left?find_min(node->left):node;
}


Tree::Node* Tree::remove_min(Node* node)
{
    if (!node->left)
    {
        return node->right;
    }

    node->left = remove_min(node->left);

    count_height(node);

    if (bfac(node) < -1)
    {
        if (height(node->left->left) < height(node->left->right))
        {
            rot_l(node->left);
        }
        rot_r(node);
    }

    if (bfac(node) > 1)
    {
        if (height(node->right->right) < height(node->right->left))
        {
            rot_r(node->right);
        }
        rot_l(node);
    }

    count_height(node);

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


void Tree::printNode_l(const Node* node, int level)
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
        std::cout << node->key;

        printNode_l(node->left, level + 1);
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


Tree::Node* Tree::deleteNode(Node* node, const int& data)
{
    if (node == nullptr)
    {
        return nullptr;
    }

	if (data < node->key)
	{
		node->left = deleteNode(node->left, data);
	}
	else if (data > node->key)
	{
        node->right = deleteNode(node->right, data);
	}
	else
	{
        Node* r = node->right;
        Node* l = node->left;

        if (r == nullptr)
        {
            delete node;
            return l;
        }

        Node* min = find_min(r);
        min->right = remove_min(r);
        min->left = l;

        delete node;

        count_height(min);

        if (bfac(min) < -1)
        {
            if (height(min->left->left) < height(min->left->right))
            {
                rot_l(min->left);
            }
            rot_r(min);
        }

        if (bfac(min) > 1)
        {
            if (height(min->right->right) < height(min->right->left))
            {
                rot_r(min->right);
            }
            rot_l(min);
        }

        count_height(min);

        return min;
	}


    count_height(node);

    if (bfac(node) < -1)
    {
        if (height(node->left->left) < height(node->left->right))
        {
            rot_l(node->left);
        }
        rot_r(node);
    }

    if (bfac(node) > 1)
    {
        if (height(node->right->right) < height(node->right->left))
        {
            rot_r(node->right);
        }
        rot_l(node);
    }

    count_height(node);

    return node;
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
    printNode_l(root, 0);
}








