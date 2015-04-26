#include <iostream>
#include <ctime>
#include "LinkedList.h"
#include "holderStruct.h"



LinkedList::LinkedList()
{
    head = NULL;
    searchTime = 99999999;
}

/*
Prototype:
void LinkedList::addNode(int)

Description:
The method adds the integer as a node in the linked list.

Example:
LinkedList n;
n.addNode(5);

Pre Condition: If the list is empty it is set to NULL, and must inputting an integer.
Post Condition: Node will be added into the linked list on the end.
*/
void LinkedList::addNode(int info)
{

    Node* newNode = new Node;
    newNode->data = info;
    newNode->next = NULL;
    if(head == NULL)
    {
        head = newNode;
        return
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

/*
Prototype:
void LinkedList::traverse(int)

Description:
This function traverses through the linked list until it finds the input.

Example:
LinkedList n;
n.traverse(5);

Pre Condition: Must have a valid linked list and a searchTime variable.
Post Condition: Searches the list and times how long it takes.
*/
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

/*
Prototype:
void LinkedList::deleteAllNodes()

Description:
The method deletes all of the Nodes in the linked list.
Example:
LinkedList l;
l.deleteAllNodes();

Pre Condition: Linked list must have at least one valid node.
Post Condition: The list will be deleted and the memory will be cleared.
*/
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

/*
Prototype:
struct dataHolder* LinkedList::getData()

Description:
The method stores the time it takes to search the tree into the GetData function.

Example:
struct dataHolder* LinkedList::getData();

Pre Condition: List must have already been searched and have a search time stored.
Post Condition: Stores the search time so it can be compared against other data structures.
*/
struct dataHolder* LinkedList::getData()
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

virtual LinkedList::~LinkedList()
{
    deleteAllNodes();
}


