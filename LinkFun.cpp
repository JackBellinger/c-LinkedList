#ifndef LINKFUN
#define LINKFUN

#include <iostream>
#include "link.h"
using namespace std;
    
    
    
    node* createNode(){
        /*  creates new node from user input and uses insertNode to put it into the list
        */
        node* newNode = new node(); 
        cout << "First Name: " << endl;
        cin >> newNode->firstName;
        cout << "Last Name: " << endl;
        cin >> newNode->lastName;
        cout << "Student ID: " << endl;
        cin >> newNode->idNumber;
        //cout << "made node" << endl;
        return newNode;
    }
    node* insertNode(node* list, node* newNode)
    /*  SORTS node into the list by the idNumber
    */
    {
        node* current = list;
        if(list == NULL)//if there is nothing in the list add the node to the front
        {
            list = newNode;
            cout << "Student inserted" << endl << endl;
        }
        else
        {
            bool found = false; //boolean to track if the right place has been found
            if(newNode->idNumber < current->idNumber)//check to see if newNode is less than the first list element (couldn't be checked by current->next->id if it's the first 
            {
                newNode->next = current;
                list = newNode;
                cout << "Student inserted" << endl << endl;
                found = true;
                //cout << "before first";
            }
            if(newNode->idNumber == current->idNumber) //if the newNode has the same idNumber as another node we don't need to add it
            {   
                cout << "Student is already in the list" << endl << endl;
                found = true;
            }
            while(!found)
            {
                
                if(current->next == NULL) //if the current node is the last in the list add newNode to the end (I do this first so I don't get seg faults when cheking current->next members)
                {
                    //cout<<"last";
                    current->next = newNode;
                    cout << "Student inserted" << endl << endl;
                    found = true;
                }
                else // there is another node next in the list
                {
                    if(newNode->idNumber == current->next->idNumber) //if the newNode has the same idNumber as another node we don't need to add it
                    {   
                        cout << "Student is already in the list" << endl << endl;
                        found = true;
                    }   
                    if(newNode->idNumber < current->next->idNumber)//if the newNode's id number is less that the next one in the list, that's the right spot
                    {
                        //cout<<"middle";
                        newNode->next = current->next;
                        current->next = newNode;
                        cout << "Student inserted" << endl << endl;
                        found = true;
                    }
                    
                    //cout<<"***next***";
                    current = current->next;
                }
            }//end while           
        }
        //cout << "end insert" << endl;
        //printList(list);
        return list;
    }
    node* searchNode(node* current, int searchId)
    {
        if(current == NULL)
            cout << "List is empty" << endl << endl;
        else
        {
            bool found = false;
            while(!found)
            {
                if(current == NULL)
                {
                    cout << "Student not found" << endl << endl;
                    found = true;//hmm seems contradictory ¯\_(ツ)_/¯
                }
                else 
                {
                    if(current->idNumber == searchId)
                    {
                        cout << "Found student\nName: " << current->firstName << " " << current->lastName << ", ID: " << current->idNumber << endl << endl;
                        found = true;
                    }
                    else
                        current = current->next;
                }
            }//end while
        }
        return current;
    }
    node* deleteNode(node* list, int deleteId)
    {
        node* current = list;
        if(list == NULL)
            cout << "List is empty" << endl << endl;
        else
        {
            node* del = NULL;
            bool found = false;
            if(current->idNumber == deleteId)//if the first one is the right one
            {
             del = current;
             list = current->next;//if we're deleting the only element this is still ok
             delete del;
             cout << "Student deleted" << endl << endl;
             found = true;
            }
            while(!found)
            {
                if(current->next == NULL)
                {
                    cout << "Student not found" << endl << endl;
                    found = true;//hmm seems contradictory ¯\_(ツ)_/¯
                }
                else 
                {
                    if(current->next->idNumber == deleteId)
                    {
                        del = current->next;
                        current->next = current->next->next;
                        del->next = NULL;
                        delete del;
                        cout << "Student deleted" << endl << endl;
                        found = true;
                    }
                    else
                        current = current->next;
                }
            }//end while  
        }
        return list;
    }
    void printList(node* current){
        if(current == NULL)
        {
            cout << "List is empty" << endl << endl;
        }
        else
        {
            cout << "List: " <<endl;
            while(current != NULL)
            {
                cout << "Name: " << current->firstName << " " << current->lastName << ", ID: " << current->idNumber << endl;
                current = current->next;
            }//end while
            cout << endl;
        }
    }
    
#endif
