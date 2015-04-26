#ifndef RB_H
#define RB_H

#include <iostream>
#include "holderStruct.h"


struct RBNode{

	bool isRed;
	int data;

	RBNode* parent;
	RBNode* leftChild;
	RBNode* rightChild;

	RBNode(){ };

	RBNode(int info){

		data = info;
		leftChild = NULL;
		rightChild = NULL;
		parent = NULL;
		isRed = true;
			
	}

};

class RB{

public:
	
	RB();
	void addNode(int info);
	bool isValid();
	void findNode(int info2);
	struct dataHolder* getData();
	virtual ~RB();

private: 
		
	void searchTree(RBNode*  node, int info3);
	void DeleteAll(RBNode* node);
	void rbAddFixup(RBNode* node);
	void leftRotate(RBNode* node);
	void rightRotate(RBNode* node);

	double searchTime;

	RBNode* root;
	RBNode* nil;

};



#endif //RB_H