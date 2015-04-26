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

void DeleteAll(RBNode* node)
{

	if (node->leftChild != nil)
		DeleteAll(node->leftChild);
	if (node->rightChild != nil)
		DeleteAll(node->rightChild);
	delete node;
}

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

void RB::rbAddFixup(RBNode*  node)
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

void RB::findNode(int info2)
{
	clock_t begin = clock();
	seachTree(root);
	clock_t end = clock();

	searchTime = double(end - begin) / CLOCKS_PER_SEC;
}

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
