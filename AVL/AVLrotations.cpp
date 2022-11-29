

#include "AVLtree.h"



AVLNode *AVLTree::rotation_RR(AVLNode *parent) // right-right rotation
{
    AVLNode *temp;
    temp = parent->right; //w temp umieszczamy adres prawego syna węzła ojca
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}


AVLNode *AVLTree::rotation_LL(AVLNode *parent) // left-left rotation
{
    AVLNode *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}


AVLNode *AVLTree::rotation_LR(AVLNode *parent) // left - right rotation (podwójna)
{
    AVLNode *temp;
    temp = parent->left;
    parent->left = rotation_RR (temp);
    return rotation_LL (parent);
}

AVLNode *AVLTree::rotation_RL(AVLNode *parent) // right-left rotation (podwójna)
{
    AVLNode *temp;
    temp = parent->right;
    parent->right = rotation_LL (temp);
    return rotation_RR (parent);
}



AVLNode *AVLTree::Balance(AVLNode *temp)
{


    int balanceFactor = Diffrence (temp);


    if (balanceFactor > 1)
    {
        if (Diffrence (temp->left) > 0)
            temp = rotation_LL (temp);
        else
            temp = rotation_LR (temp);
    }
    else if (balanceFactor< -1)
    {
        if (Diffrence (temp->right) > 0)
            temp = rotation_RL (temp);
        else
            temp = rotation_RR (temp);
    }
    return temp;
}
