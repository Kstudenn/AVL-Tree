
#include "AVLtree.h"
#include <iostream>


void AVLTree::inorder(AVLNode *tree)
{
    if (tree == nullptr)
        return;
    inorder (tree->left);
    std::cout<<tree->data<<"  ";
    inorder (tree->right);
}

void AVLTree::preorder(AVLNode *tree)
{
    if (tree == nullptr)
        return;
    std::cout<<tree->data<<"  ";
    preorder (tree->left);
    preorder (tree->right);

}


void AVLTree::postorder(AVLNode *tree)
{
    if (tree == nullptr)
        return;
    postorder ( tree ->left );
    postorder ( tree ->right );
    std::cout<<tree->data<<"  ";
}
