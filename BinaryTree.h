#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include "holderStruct.h"

struct TreeNode{

        int data;
        TreeNode* leftChild;
        TreeNode* rightChild;

    };

class BST{

public:

    BST();
    void addToTree(int info);
    void searchTree(int info2);
    dataHolder* getData();
	void ft(int info3);
	void searchNode(TreeNode* node, int info4);
    void deleteTree();
    ~BST();



private:
    void deleteAll(TreeNode* node);

    TreeNode* root;
    double searchTime;
};


#endif // BINARYTREE_H
