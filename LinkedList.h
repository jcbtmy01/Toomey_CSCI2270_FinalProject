#ifndef LINKEDLIST_H
#define LINKDLIST_H

#include <iostream>
#include "holderStruct.h"


class LinkedList{


public:

    LinkedList();
    void addNode(int info);
    struct dataHolder* getData();
    void traverse(int info2);
    void deleteAllNodes();
    virtual ~LinkedList();

private:

    struct Node{

        int data;
        Node* next;
    };
    Node* head;
    double searchTime;

};

#endif //LINKEDLIST_H
