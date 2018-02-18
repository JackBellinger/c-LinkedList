#ifndef LINK_H
#define LINK_H

#include <iostream>
using namespace std;

struct node{
    
    char lastName[20];
    char firstName[20];
    int idNumber;
    node* next;
};
class LinkedList{
    node* head = 0;
    public:
    node* createNode();
    node* insertNode(LinkedList*, node*);
    node* searchNode(LinkedList*, int);
    LinkedList* deleteNode(LinkedList*, int);
    void printList(LinkedList*);
};


#endif