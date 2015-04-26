#include <iostream>
#include <ctime>
#include "holderStruct.h"
#include "RB.h"



RB::RB()
{

	nil = new RBNode(0);
	root = nil;
	nil->isRed = false;
	nil->leftChild = nil;
	nil->rightChild = nil;
	searchTime = 99999999;


}


virtual RB::~RB()
{
	if (root != nil)
		DeleteAll(root);
	delete nil;
}

/*
Prototype:
void DeleteAll(RBNode*)

Description:
Deletes all of the nodes in the tree.

Example:
RBNode* n;
void DeleteAll(n);

Pre Condition: Must have a valid node with valid children
Post Condition: Node and children will be deleted from tree and the memory will be released.
*/
void DeleteAll(RBNode* node)
{

	if (node->leftChild != nil)
		DeleteAll(node->leftChild);
	if (node->rightChild != nil)
		DeleteAll(node->rightChild);
	delete node;
}

/*
Prototype:
void RB::addNode(int)

Description:
The method adds a node into the RBTree

Example:
RB r;
r.addNode(5);

Pre Condition: Must be a valid integer and the tree's empty nodes will be set to NULL.
Post Condition: The integer will be added as a new node to the tree.
*/
void RB::addNode(int info)
{

	RBNode* newNode = new RBNode(info);

	newNode->leftChild = nil;
	newNode->rightChild = nil;

	RBNode* x = root;
	RBNode* y = NULL;

	if (root == nil)
	{

		root = newNode;
		newNode->parent = nil;
	}


	else{

		while (x != nil)
		{
			y = x;

			if (newNode->data < x->data)
				x = x->leftChild;
			else{

				x = x->rightChild;
			}
		}

		newNode->parent = y;


		if (newNode->data < y->data)
			y->lefChild = newNode;
		else
			y->rightChild = newNode;

	}

	rbAddFixup(newNode);

	return;

}

/*
Prototype:
void RB::rbAddFixup(RBNode* node)

Description:
This function will fix the Red Black tree after a node has been added, to ensure it is still a valid tree.

Example:
RB r;
r.rbAddFixup(node);

Pre Condition: Must be a RB tree and a valid node to fix.
Post Condition: Tree will be fixed and be a valid RB tree again.
*/
void RB::rbAddFixup(RBNode* node)
{
	RBNode* uncle = NULL;


	node->leftChild = nil;
	node->rightChild = nil;


	while ((node != root) && (node->parent->isRed))
	{

		if (node->parent == node->parent->parent->leftChild)
		{

			uncle = node->parent->parent->rightChild;

			if (uncle->isRed)
			{

				node->parent->isRed = false;
				uncle->isRed = false;
				node->parent->parent->isRed = true;

				node = node->parent->parent;
			}


			else
			{

				if (node == node->parent->rightChild)
				{

					node = node->parent;
					leftRotate(node);
				}

				node->parent->isRed = false;
				node->parent->parent->isRed = true;
				rightRotate(node->parent->parent);
			}
		}

		else
		{

			uncle = node->parent->parent->leftChild;

			if (uncle->isRed == true)
			{

				node->parent->isRed = false;
				uncle->isRed = false;
				node->parent->parent->isRed = true;

				node = node->parent->parent;
			}

			else
			{

				if (node == node->parent->leftChild)
				{

					node = node->parent;
					rightRotate(node);
				}

				node->parent->isRed = false;
				node->parent->parent->isRed = true;
				leftRotate(node->parent->parent);
			}
		}
	}

	root->isRed = false;

	return;
}

/*
Prototype:
void RB::leftRotate(RBNode*)

Description:
The method performs a left rotate to fix the RB tree in the case that it is no longer valid.

Example:
RB r;
r.leftRotate(x);

Pre Condition: Tree is not a valid RB tree due to a node being added.
Post Condition: A left rotate will be performed to try and make the tree valid again.
*/
void RB::leftRotate(RBNode* x)
{
	RBNode* y = x->rightChild;
	x->rightChild = y->leftChild;


	if (y->leftChild != nil)
		y->leftChild->parent = x;


	y->parent = x->parent;


	if (x->parent == nil)
		root = y;


	else
	{

		if (x == (x->parent)->leftChild){
			x->parent->leftChild = y;
		}


		else{
			x->parent->rightChild = y;
		}
	}

	y->leftChild = x;
	x->parent = y;
}

/*
Prototype:
void RB::leftRotate(RBNode*)

Description:
The method performs a right rotate to fix the RB tree in the case that it is no longer valid.

Example:
RB r;
r.rightRotate(x);

Pre Condition: Tree is not a valid RB tree due to a node being added.
Post Condition: A right rotate will be performed to try and make the tree valid again.
*/
void RB::rightRotate(RBNode * x)
{

	RBNode * y = x->leftChild;


	x->leftChild = y->rightChild;


	if (y->rightChild != nil)
		y->rightChild->parent = x;


	y->parent = x->parent;


	if (x->parent == nil)
		root = y;


	else
	{

		if (x == (x->parent)->leftChild)
		{
			x->parent->leftChild = y;
		}

		else
		{
			x->parent->rightChild = y;
		}
	}


	y->rightChild = x;

	x->parent = y;
}

/*
Prototype:
void RB::findNode(int)

Description:
This method times the searching of the tree.

Example:
RB r;
r.findNode(5);

Pre Condition: Must have a valid RB tree and a valid node.
Post Condition: Searches the tree and times it.
*/
void RB::findNode(int info2)
{
	clock_t begin = clock();
	seachTree(root);
	clock_t end = clock();

	searchTime = double(end - begin) / CLOCKS_PER_SEC;
}

/*
Prototype:
void RB::searchTree(RBNode*, int)

Description:
This method .earches the tree for a specific node;

Example:
RB r;
r.searchTree(node, 5);

Pre Condition: Must have a valid RB tree and a valid node.
Post Condition: Searches the tree.
*/
void RB::searchTree(RBNode* node, int info3)
{

	if (node == nil)
		return;
	else if (node->data == info3)
		return;

	else{

		if (info3 < node->data)
			searchTree(node->leftChild, info3);
		else
			searchTree(node->rightChild, info3);

	}

}

/*
Prototype:
struct dataHolder* RB::getData()

Description:
The method stores the time it takes to search the tree into the GetData function.

Example:
struct dataHolder* RB::getData();

Pre Condition: Tree must have already been searched and have a search time stored.
Post Condition: Stores the search time so it can be compared against other data structures.
*/
struct dataHolder* getData()
{
	if (searchTime == 99999999)
		return;
	else{
		dataHolder* newData = new dataHolder;
		newData->timeE = searchTime;
		newData->searchType = "RBTree";
		return newData;
	}

}
