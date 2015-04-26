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

int returnHash(int key)
{
    return key % MAX_LEN;
}

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

dataHolder* HashTable::getData()
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
