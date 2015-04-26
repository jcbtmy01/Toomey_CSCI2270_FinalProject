#ifndef ORGANIZER_H
#define ORGANIZER_H

#include <iostream>
#include <vector>
#include "holderStruct.h"


class organizer
{

public:

	organizer();
	void addAll(int info1);
	void callSearch(int info);
	void getSearches();
	void sort();
	vector<dataHolder*>* getSorted();
	~organizer();

private:

	RB* Rbtree;
	LinkedList* linkednodes;
	HashTable* newHash;
	BST* binaryTree;
	vector<dataHolder*>* dataSearchTimes;



};



#endif //ORGANIZER_H