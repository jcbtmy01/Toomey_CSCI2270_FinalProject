#ifndef BINARYTREE_H
#defin BINARYTREE_H

#include <iostream>
#include "holderStruct.h"


class BST{

public:

    BST();
    void addToTree(int info);
    void searchTree(int info2);
    struct dataHolder* getData();
	void find(int info3);
	void searchNode(TreeNode* node, int info4);
    void deleteTree();
    virtual ~BST();



private:
    void deleteAll(TreeNode* node);
    struct TreeNode{

        int data;
        TreeNode* leftChild;
        TreeNode* rightChild;

    };
    TreeNode* root;
    double searchTime;
};


#endif // BINARYTREE_H
