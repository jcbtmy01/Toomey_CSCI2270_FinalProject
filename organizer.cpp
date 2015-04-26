#include <iostream>
#include <vector>
#include "holderStruct.h"
#include "RB.h"
#include "BinaryTree.h"
#include "HashTable.h"
#include "organizer.h"


/*

This is the organizer class which manages all of the datat structures.
As well as sorting the information this class will be used as the main component of interacting with the data structures


Constructor:
	creates new dynamic instances of all data Structures


*/

organizer::organizer()
{
	dataSearchTimes = new std::vector<dataHolder*>;

	Rbtree = new RB;
	linkednodes = new LinkedList;
	binaryTree = new BST;
	newHash = new HashTable;


}

/*

addAll functionn takes in an integer and adds them to all of the existing data structures

Ex:

	organizer.addAll(10)

	this would at 10 to all binary tree, linked list, hash table, and rb tree

*/

void organizer::addAll(int info1)
{

	Rbtree->addNode(info1);
	linkednodes->addNode(info1);
	int keyvalue = info1 % 10;
	newHash->Insert(keyvalue, info1);
	binaryTree->addToTree(info1);


}

/*
function organizer::callSearch takes in a search value integer in all of the data structures and sets
search times. This would run the searches and set a private variable in all structures

Ex:
	organizer.callSearch(10);

	would  search all data structures for number 10


*/

void organizer::callSearch(int info)
{
	Rbtree->findNode(info);
	linkednodes->traverse(info);
	int keyvalue = info % 10;
	newHash->Search(keyvalue);
	binaryTree->ft(info);
}


void organizer::getSearches()
{
	dataHolder* point = Rbtree->getData();
	dataHolder* point1 = linkednodes->getData();
	dataHolder* point2 = newHash->getData();
	dataHolder* point3 = binaryTree->getData();

	dataSearchTimes->push_back(point);
	dataSearchTimes->push_back(point1);
	dataSearchTimes->push_back(point2);
	dataSearchTimes->push_back(point3);

}


/*


*/

void organizer::sort()
{
	dataHolder* swap;

	for (int n = 0; n < dataSearchTimes->size(); n++)
	{
		for (int d = 0; d < dataSearchTimes->size() - n - 1; d++)
		{

			if (dataSearchTimes->at(d)->timeE < dataSearchTimes->at(d+1)->timeE)
			{
				swap = dataSearchTimes->at(d);
				dataSearchTimes->at(d) = dataSearchTimes->at(d+1);
				dataSearchTimes->at(d+1) = swap;

			}

		}
	}
}


std::vector<dataHolder*>* organizer::getSorted()
{
	return dataSearchTimes;
}


organizer::~organizer()
{
	delete dataSearchTimes;
}
