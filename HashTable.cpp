#include "HashTable.h"
#include <ctime>
#define MAX_LEN 10

HashTable::HashTable()
{
	searchTime = 99999999;
    table = new hashNode*[MAX_LEN];
	top = new hashNode*[MAX_LEN];
	for (int i = 0; i < MAX_LEN; i++)
	{
		table[i] = NULL;
		top[i] = NULL;
	}
}

/*
Prototype:
int returnHash(int)

Description:
The method returns the hash value for the inputted key.

Example:
returnHash(78);

Pre Condition: Must be a positive integer.
Post Condition: Will return the hash value for the key, using an array size of 10.
*/
int returnHash(int key)
{
    return key % MAX_LEN;
}

/*
Prototype:
int HAshTable::Search(int)

Description:
The method searches the Hash Table for a certain key and stores the time it takes to search and find the key

Example:
HashTable t;
t.Search(5);

Pre Condition: Must have a valid Hash Table and a positive integer to search for.
Post Condition: Stores the time it takes to search the function in the searchTime variable.
*/
int HashTable::Search(int key)
{
    int h = returnHash(key);
    bool flag = false;

	clock_t  begin = clock();

    hashNode* entry = table[h];
    if(entry != NULL)
    {
        while (entry != NULL)
        {
            if (entry->key == key)
            {
                flag = true;
				break;
            }
            entry = entry->next;
        }
    }
    clock_t end = clock();
	double timeElapsed = double(end-begin)/CLOCKS_PER_SEC;
	searchTime = timeElapsed;
}

/*
Prototype:
void HashTable::Insert(int, int)

Description:
The method Inserts a key at the given hash value.

Example:
HashTable t;
t.Insert(5, 2);

Pre Condition: Must be a valid key and has value and must have a valid Hash Table created.
Post Condition: Key is inserted into the Table at the given hash value.
*/
void HashTable::Insert(int key, int value)
{
    int h = returnHash(key);
    hashNode *entry = table[h];
    if (entry == NULL)
    {
        entry = new hashNode;
        entry->data = value;
        entry->key = key;
        entry->next = NULL;
        entry->prev = NULL;
        table[h] = entry;
        top[h] = entry;
    }
    else
    {
        while(entry != NULL)
            entry = entry->next;
        entry = new hashNode;
        entry->data = value;
        entry->key = key;
        entry->next = NULL;
        entry->prev = top[h];
        top[h]->next = entry;
        top[h] = entry;
    }
}

/*
Prototype:
struct dataHolder* BST::getData()

Description:
The method stores the time it takes to search the tree into the GetData function.

Example:
struct dataHolder* BST::getData();

Pre Condition: Table must have already been searched and have a search time stored.
Post Condition: Stores the search time so it can be compared against other data structures.
*/
struct dataHolder* HashTable::getData()
{
    if(searchTime == 99999999)
    {
        return NULL;
    }
    else
    {
        dataHolder* point = new dataHolder;
        point->searchType = "Hash Table";
        point->timeE = searchTime;
        return point;
    }
}

HashTable::~HashTable()
{
    delete[] table;
}
