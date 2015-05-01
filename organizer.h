#ifndef ORGANIZER_H
#define ORGANIZER_H

#include <iostream>
#include <vector>
#include "holderStruct.h"
#include "RB.h"
#include "LinkedList.h"
#include "BinaryTree.h"
#include "HashTable.h"

class organizer
{

public:

	organizer();
	void addAll(int info1);
	void callSearch(int info);
	void getSearches();
	void sort();
	std::vector<dataHolder*>* getSorted();
	~organizer();

private:

	RB* Rbtree;
	LinkedList* linkednodes;
	HashTable* newHash;
	BST* binaryTree;
	std::vector<dataHolder*>* dataSearchTimes;



};



#endif //ORGANIZER_H
