#include <iostream>
#include <ctime>
#include "holderStruct.h"
#include "BinaryTree.h"


BST::BST()
{
    root = NULL;
    searchTime = 99999999;
}

void BST::addToTree(int info)
{
    TreeNode* newNode = new TreeNode;
    newNode->data = info;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;

    TreeNode* x = root;
    TreeNode* y = NULL;

    if(root == NULL)
    {
        root = newNode;
        return;
    }
    else{

        while(x != NULL)
        {
            y = x;

            if(newNode->data < x->data)
            {
                 x = x->leftChild;
            }
            else{
                x = x->rightChild;
            }
        }

        if(newNode->data < y->data)
        {
            y->leftChild = newNode;
        }
        else{

            y->rightChild = newNode;
        }
    }

}

void BST::deleteTree()
{
    deleteAll(root);

}

void BST::deleteAll(TreeNode* node)
{
    if(node->leftChild != NULL)
        deleteAll(node->leftChild);
    if(node->rightChild != NULL)
        deleteAll(node->rightChild);

    delete node;
    return;
}





