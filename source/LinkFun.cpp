#ifndef LINKFUN
#define LINKFUN

#include <iostream>
#include "link.h"
using namespace std;
    
    
    
    node* LinkedList::createNode(){
        /*  creates new node from user input and uses insertNode to put it into the list
        */
        node* newNode = new node; 
        cout << "First Name: " << endl;
        cin >> newNode->firstName;
        cout << "Last Name: " << endl;
        cin >> newNode->lastName;
        cout << "Student ID: " << endl;
        cin >> newNode->idNumber;
        //cout<< *this;
        insertNode(this, newNode);
    }
    node* LinkedList::insertNode(LinkedList* list, node* newNode)
    /*  SORTS node into the list by the idNumber
    */
    {
        cout<<"here";
        node* current = list->head;
        if(head == NULL)//if there is nothing in the list add the node to the front
        {
            cout<<"front";
            head->next = newNode;
        }
        else
        {
            
            bool found = false; //boolean to track if the right place has been found
            while(!found)
            {
                if(current->next == NULL) //if the current node is the last in the list add newNode to the end (I do this first so I don't get seg faults when cheking current->next members)
                {
                    cout<<"last";
                    current->next == newNode;
                    found = true;
                }
                else // there is another node next in the list
                {
                    if(newNode->idNumber == current->next->idNumber) //if the newNode has the same idNumber as another node we don't need to add it
                    {   
                        cout << "Student is already in the list" << endl;
                        found = true;
                    }   
                    if(newNode->idNumber < current->next->idNumber)//if the newNode's id number is less that the next one in the list, that's the right spot
                    {
                        cout<<"middle";
                        newNode->next = current->next;
                        current->next = newNode;
                        found = true;
                    }
                    
                    cout<<"next";
                    current = current->next;
                }
                
                
            }//end while           
        }
        printList(this);
    }
    node* LinkedList::searchNode(LinkedList*, int){
        
    }
    LinkedList* LinkedList::deleteNode(LinkedList*, int){
        
    }
    void LinkedList::printList(LinkedList*){
        node* current = this->head;
        if(current == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
            while(current != NULL)
            {
                cout << "Name: " << current->firstName << " " << current->lastName << ", ID: " << current->idNumber << endl;
                current = current->next;
            }
    }
    
#endif