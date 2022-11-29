
#include <iostream>
#include "AVLtree.h"

int AVLTree::Menu(){

    int choice=0;
    int item=0;


    while (true)
    {
        std::cout<<"\n---------------------"<<std::endl;
        std::cout<<"AVL Tree Implementation"<<std::endl;
        std::cout<<"\n---------------------"<<std::endl;
        std::cout<<"1.Insert Element into the tree"<<std::endl;
        std::cout<<"2.Show Balanced AVL Tree"<<std::endl;
        std::cout<<"3.Delete element from the tree"<<std::endl;
        std::cout<<"4.PreOrder "<<std::endl;
        std::cout<<"5.PostOrder "<<std::endl;
        std::cout<<"6.InOrder "<<std::endl;
        std::cout<<"7.Close the program"<<std::endl;
        std::cout<<"Enter your Choice: ";
        std::cin>>choice;
        switch(choice)
        {
            case 1: {
                std::cout << " Enter the number : ";
                std::cin >> item;
                this->root = this->InsertNode(this->root, item);
            }
                break;
            case 2:
                if (this->root == nullptr) {
                    std::cout << "Tree is Empty" << std::endl;
                    continue;
                }
                std::cout << "Balanced AVL Tree:" << std::endl;
                this->Show(this->root, 1);
                break;

            case 3:
                std::cout << "Enter the number to delete: ";
                std::cin >> item;
                this->root = this->DeleteNode(this->root, item);
                break;

            case 4:
                std::cout << "Preorder Traversal:" << std::endl;
                this->preorder(this->root);
                std::cout << std::endl;
                break;

            case 5:
                std::cout << "Postorder Traversal:" << std::endl;
                this->postorder(this->root);
                std::cout << std::endl;
                break;

            case 6:
                std::cout << "Inorder Traversal:" << std::endl;
                this->inorder(root);
                std::cout << std::endl;
                break;

            case 7:
                return 0;

            default:
                std::cout << "Wrong Choice" << std::endl;
                break;
        }
    }
    return 0;
}