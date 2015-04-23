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
	clock_t begin = clock();
    deleteAll(root);
	clock_t end = clock();

	searhTime = double(end - begin) / CLOCKS_PER_SEC;

}

void BST::searchNode(TreeNode* node, int info4)
{
	

	if (node == NULL)
	{
		return;
	}
	else if (node->data == info4)
	{
		return;
	}
	else{
		if (info4 < node->data)
		{
			searchNode(node->leftChild, info4);
		}
		else{

			searchNode(node->rightChild, info4);
		}

	}

}

void BST::find(int info3)
{

	searchNode(root, info3)

}

struct dataHolder* BST::getData()
{
	if (searchTime == 99999999)
	{
		return NULL;
	}
	else
	{
		dataHolder* newData = new dataHolder;
		newData->timeE = searchTime;
		newData->searchType = "BinaryTree";
		return newData;
	}


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





