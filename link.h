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

node* createNode();
node* insertNode(node*, node*);
node* searchNode(node*, int);
node* deleteNode(node*, int);
void printList(node*);


#endif
