#include <iostream>
#include <ctime>
#include "holderStruct.h"
#include "BinaryTree.h"

BST::BST()
{
    root = NULL;
    searchTime = 99999999;
}

/*
Prototype:
void BST::AddToTree(int)

Description:
The method adds a number into the Binary Tree

Example:
BST tree;
tree.addToTree(5);

Pre Condition: Input must be an integer and the tree must be valid.
Post Condition: Integer added into the Tree and sorted correctly.
*/

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

/*
Prototype:
void BST::deleteTree()

Description:
The method deletes the Binary Tree

Example:
BST tree;
tree.deleteTree();

Pre Condition: Must have a tree with at least one input in it.
Post Condition: The tree will be deleted and the memory freed.
*/
void BST::deleteTree()
{
	clock_t begin = clock();
    deleteAll(root);
	clock_t end = clock();

	searhTime = double(end - begin) / CLOCKS_PER_SEC;

}

/*
Prototype:
void BST::searchNode(struct*, int)

Description:
The method searches the tree for the inputted integer.

Example:
BST tree;
tree.searchNode(TreeNode* node, int 5);

Pre Condition: Input must be an integer and have already been added to the tree.
Post Condition: The function will search through the function until it finds the inputted integer and times how long it takes.
*/
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

/*
Prototype:
struct dataHolder* BST::getData()

Description:
The method stores the time it takes to search the tree into the GetData function.

Example:
struct dataHolder* BST::getData();

Pre Condition: Tree must have already been searched and have a search time stored.
Post Condition: Stores the search time so it can be compared against other data structures.
*/
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

//Used in delete tree function.
void BST::deleteAll(TreeNode* node)
{
    if(node->leftChild != NULL)
        deleteAll(node->leftChild);
    if(node->rightChild != NULL)
        deleteAll(node->rightChild);

    delete node;
    return;
}





