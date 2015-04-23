#include "HashTable.h"

HashTable::HashTable()
{
    //ctor
}

int returnHash(string title)
{
    return 1;
    int sum=0,index=0;
    for(string::size_type i=0; i < title.length(); i++)
    {
        sum += title[i];
    }
    index = sum % MAX_LEN;
    return index;
}

int HashTable::Search(string title)
{
    int h = returnHash(title);
    bool flag = false;
    Movie* entry = table[h];
    if(entry != NULL)
    {
        while (entry != NULL)
        {
            if (entry->title == title)
            {
                flag = true;
            }
            if(flag)
            {
                cout << entry->year << "\n" << endl;
            }
            entry = entry->next;
        }
    }
    if (!flag)
        cout << "Movie not found." << endl;
}

void HashTable::insertMovie(string title, int year)
{
    int h = returnHash(title);
    Movie *entry = table[h];
    if (entry == NULL)
    {
        entry = new Movie;
        entry->title = title;
        entry->year = year;
        entry->next = NULL;
        entry->prev = NULL;
        table[h] = entry;
        top[h] = entry;
    }
    else
    {
        while(entry != NULL)
            entry = entry->next;
        entry = new Movie;
        entry->title = title;
        entry->year = year;
        entry->next = NULL;
        entry->prev = top[h];
        top[h]->next = entry;
        top[h] = entry;
    }
}

HashTable::~HashTable()
{
    delete[] table;
}
