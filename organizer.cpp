#include <iostream>
#include <vector>
#include "holderStruct.h"
#include "RB.h"
#include "BinaryTree.h"
#include "LinkedList.h"
#include "HashTable.h"




organizer::organizer()
{
	dataSearchTimes = new vector < dataholder* > ;

}

organizer::~organizer()
{
	delete dataSearchTimes;
}