#include <iostream>
#include <ctime>
#include "LinkedList.h"
#include "holderStruct.h"



LinkedList::LinkedList()
{
    head = NULL;
    searchTime = 99999999;
}


void LinkedList::addNode(int info)
{

    Node* newNode = new Node;
    newNode->data = info;
    newNode->next = NULL;
    if(head == NULL)
    {
        head = newNode;
        return;
    }
    else{

        Node* temp = head;
        while(temp)
        {
            if(temp->next == NULL)
            {
                temp->next = newNode;
                return;
            }
            else{
                temp = temp->next;
            }
        }
    }

}

void LinkedList::traverse(int info2)
{
    Node* temp = head;

    clock_t begin = clock();

    while(temp)
    {
       if(temp->data == info2)
       {
            break;
       }
       else{
            temp = temp->next;
       }
    }

    clock_t end = clock();

    double timeElapsed = double(end-begin)/CLOCKS_PER_SEC;
    searchTime = timeElapsed;
}


void LinkedList::deleteAllNodes()
{
    Node* temp = head;

    if(temp == NULL)
    {
        return;
    }

    while(temp)
    {
        Node* deleted = temp;
        temp = temp->next;
        delete deleted;
    }
}

dataHolder* LinkedList::getData()
{
    if(searchTime == 99999999)
    {
        return NULL;
    }
    else
    {
        dataHolder* point = new dataHolder;
        point->searchType = "LinkedList";
        point->timeE = searchTime;
        return point;
    }
}

LinkedList::~LinkedList()
{
    deleteAllNodes();
}


