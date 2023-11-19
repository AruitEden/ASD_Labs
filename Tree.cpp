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



bool Tree::search_prev(Node*& node, const int& data)
{
    //if (node == nullptr)
    //{
    //    return;
    //}

    //if (node->key != data)
    //{
    //    std::cout << node->key << " ";

    //    search_prev(node->son, data);

    //    search_prev(node->brother, data);
    //}
    //else
    //{
    //    std::cout << "\nTrue";
    //}

    std::stack<Node*> s;
    s.push(nullptr);
    Node* tt = node;

    do
    {
        if (tt != nullptr)
        {
            if (tt->key == data)
            {
                return true;
            }

            s.push(tt);
            std::cout << tt->key << " ";
            tt = tt->son;
        }
        else
        {
            if (s.top() == nullptr) break;
            tt = s.top();
            s.pop();
            tt = tt->brother;
        }
    } while (true);

    return false;
}


bool Tree::search_post(Node*& node, const int& data)
{
    std::stack<Node*> s;
    s.push(nullptr);
    Node* tt = node;

    do
    {
        if (tt != nullptr)
        {
            s.push(tt);
            tt = tt->son;
        }
        else
        {

            if (s.top() == nullptr) break;
            tt = s.top();
            s.pop();

            if (tt->key == data)
            {
                return true;
            }
            std::cout << tt->key << " ";

            tt = tt->brother;
        }
    } while (true);

    return false;

    //if (node)
    //{
    //    if (node->key == data)
    //    {
    //        //std::cout << "\nTrue";
    //        return true;
    //    }
    //    else
    //    {

    //        search_in(node->son, data);

    //        std::cout << node->key << " ";

    //        search_in(node->brother, data);
    //    }
    //}
    //else
    //{
    //    return false;
    //}
}

bool Tree::search_in(Node*& node, const int& data)
{
    bool t;
    //if (node)
    //{
        if (node->son)
        {
            t = search_in(node->son, data);
            if (t)
            {
                return true;
            }
        }

        if (node->key == data)
        {
            return true;
        }

        std::cout << node->key << " ";

        if (node->son && node->son->brother)
        {
            Node* temp = node->son->brother;

            while (temp)
            {
                t = search_in(temp, data);
                if (t)
                {
                    return true;
                }
                temp = temp->brother;
            }
        }
    //}

    //else
    //{
        return false;
    //}



    //std::stack<Node*> s;

    //while (node != nullptr || !s.empty())
    //{
    //    if (node)
    //    {
    //        s.push(node);
    //        node = node->son;
    //    }
    //    else
    //    {
    //        node = s.top();

    //        if (node->key == data)
    //        {
    //            return true;
    //        }

    //        std::cout << node->key << " ";
    //        node = node->brother;

    //        s.pop();
    //    }












    //std::stack<Node*> s;
    //Node* lnp = nullptr;
    //Node* peekn = nullptr;
  
    //while (node != nullptr || !s.empty())
    //{
    //    if (node)
    //    {
    //        s.push(node);
    //        node = node->son;
    //    }
    //    else
    //    {
    //        peekn = s.top();

    //        if (peekn->brother && lnp != peekn->brother)
    //        {
    //            node = peekn->brother;
    //        }
    //        else
    //        {
    //            s.pop();

    //            if (peekn->key == data)
    //            {
    //                return true;
    //            }

    //            std::cout << peekn->key << " ";
    //            lnp = peekn;
    //        }
    //    }












        //if (node->key == data)
        //{
        //    return true;
        //}
        //std::cout << node->key << " ";

        //while (node!=nullptr)
        //{
        //    s.push(node);
        //    node = node->son;


        //}

        //node = s.top()->brother;
        //s.pop();
    //}




    //if (node)
    //{
    //    //if (node->key == data)
    //    //{
    //    //    return true;
    //    //}
    //    /*else*/
    //    {

    //        search_in(node->son, data);            

    //        std::cout << node->key << " ";

    //        search_in(node->brother, data);            
    //    }
    //}
    //else
    //{
    //    return false;
    //}
}




void Tree::print_in(Node* node)
{
    if (!node)
    {
        return;
    }

    if (node->son)
    {
        print_in(node->son);
    }

    std::cout << node->key << " ";

    if (node->son && node->son->brother)
    {
        Node* temp = node->son->brother;

        while (temp)
        {
            print_in(temp);
            temp = temp->brother;
        }
    }



 /*   std::stack<Node*> s;
    std::stack<Node*> s2;


    while (node != nullptr || s.size() != 0)
    {
        if (node)
        {
            if (level(node->son, 1) > 1)
            {
                s2.push(node);
            }

            s.push(node);

            node = node->son;
        }
        else
        {
            node = s.top();
            s.pop();

            if (s.top() == s2.top())
            {
                node = s.top();

                s.pop();
                s2.pop();

                for (int i = 0; i < level(node->son, 1); i++)
                {                   

                    print_in(node->son);

                    if (i == 0)
                    {
                        std::cout << node->key << " ";
                    }

                    node = node->brother;
                }
            }

            std::cout << node->key << " ";
            node = node->brother;
        }
    }*/
}









    //if (node == nullptr)
    //{
    //    return;
    //}


    //print_in(node->son);
    //std::cout << node->key << " ";
    //print_in(node->brother);


    //std::stack<Node*> s;

    //while (node != nullptr || s.size() != 0)
    //{
    //    if (node)
    //    {
    //        s.push(node);
    //        node = node->son;
    //    }
    //    else
    //    {
    //        node = s.top();
    //        s.pop();

    //        std::cout << node->key << " ";
    //        node = node->brother;
    //    }
    //}
//}

void Tree::print()
{
    if (root == nullptr)
    {
        return;
    }


    printNode(root);

}








