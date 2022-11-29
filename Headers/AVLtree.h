
#ifndef AVLTREE_AVLTREE_H
#define AVLTREE_AVLTREE_H

struct AVLNode
{
    //int balanceFactor;
    int data;
    AVLNode *left;
    AVLNode *right;
};


class AVLTree
{
private: AVLNode *root;

public: int  Height    (AVLNode *);
public: int  Diffrence (AVLNode *);
public: void Show     (AVLNode *, int );

public: void inorder(AVLNode *);
public: void preorder(AVLNode *);
public: void postorder(AVLNode *);

public: AVLNode *rotation_RR(AVLNode *);
public: AVLNode *rotation_LL(AVLNode *);
public: AVLNode *rotation_LR(AVLNode *);
public: AVLNode *rotation_RL(AVLNode *);
public: AVLNode *Balance    (AVLNode *);

public: AVLNode* InsertNode(AVLNode *, int );
public: AVLNode* DeleteNode(AVLNode *, int);

public: AVLTree(){root=nullptr;};

public: int Menu();
};


#endif //AVLTREE_AVLTREE_H
