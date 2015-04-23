#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>

struct {
    public:
        std::string title;
        int key;
        int value;
        Movie *next;
        Movie *prev;
};

class HashTable
{
    public:
        HashTable();
        ~HashTable();
        void Insert(std::string title, int year);
        int Search(std::string title);
    protected:
    private:
        Movie **table, **top;
};

#endif // HASHTABLE_H
