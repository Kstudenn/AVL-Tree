
#include "AVLtree.h"
#include <iostream>
#define max(a,b)(((a)>(b))?(a):(b))


AVLNode* findMin(AVLNode* root)
{
    if(root == nullptr)
        return nullptr;
    else if(root->left == nullptr)
        return root;
    else
        return findMin(root->right);
}



int AVLTree::Height(AVLNode *temp) // temp - temporary node
{
    int h = 0;
    if (temp != nullptr)
    {
        int l_height = Height (temp->left);
        int r_height = Height (temp->right);
        int max_height = max (l_height, r_height);
        h = max_height + 1;
    }
    return h;
}



int AVLTree::Diffrence(AVLNode *temp)
{
    int l_height = Height (temp->left);
    int r_height = Height (temp->right);
    int b_factor = l_height - r_height;
    return b_factor;
}



AVLNode *AVLTree::InsertNode(AVLNode *root, int value)
{
    if (root == nullptr)
    {
        root = new AVLNode;
        root->data = value;
        root->left = nullptr;
        root->right = nullptr;
        return root;
    }
    else if (value < root->data)
    {
        root->left = InsertNode(root->left, value);
        root = Balance (root);
    }
    else if (value >= root->data)
    {
        root->right = InsertNode(root->right, value);
        root = Balance (root);
    }
    return root;
}

AVLNode *AVLTree::DeleteNode(AVLNode *root, int value)
{
    AVLNode *temp;


    if(root == nullptr)                                     //pusty
    {
        return nullptr;
    }
    else if(value < root->data)
    {
        root->left = DeleteNode(root->left, value);
        root = Balance(root);
    }
    else if(value > root->data)
    {
        root->right = DeleteNode(root->right, value);
        root = Balance(root);
    }

    else if(root->left && root->right)                      // 2 synow
    {
        temp = findMin(root->right);
        root->data = temp->data;
        root->right = DeleteNode(root->right, root->data);
        root = Balance(root);
    }
    else                                                    // 0 lub jeden syn
    {
        temp = root;
        if(root->left == nullptr)
        {
            root = root->right;
        }

        else if(root->right == nullptr)
        {
            root = root->left;
        }

        delete temp;
    }
    if(root == nullptr)
    {
        return root;
    }
    root = Balance(root);


}



void AVLTree::Show(AVLNode *node, int level)
{

    if (node!= nullptr)
    {
        Show(node->right, level + 1);
        std::cout<<"\n"<<std::endl;
        if (node == this->root)
            std::cout<<"Root -> ";
        for (int i = 0; i < level && node != root; i++)
            std::cout<<"        ";
        std::cout<<node->data;
        Show(node->left, level + 1);
    }
}