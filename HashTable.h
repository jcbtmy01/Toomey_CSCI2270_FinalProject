#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
#include "holderStruct.h"
#define MAX_LEN 10

struct hashNode{
    public:
        int key;
		int data;
        int value;
};

class HashTable
{
    public:
        HashTable();
        ~HashTable();
        void Insert(int key, int value);
		struct dataHolder* getData();
        int Search(int key);
		double searchTime;
    protected:
    private:
        hashNode **table, **top;
};

#endif // HASHTABLE_H
