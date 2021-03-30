//
//  LinkedQueue.h
//  AS09 Linked List
//
//  Created by Elle Hoarau on 4/22/20.
//  Copyright © 2020 Elle Hoarau. All rights reserved.
//

#ifndef LinkedQueue_h
#define LinkedQueue_h
#include <iostream>
#include <string>
using namespace std;

class IntLinkedQueue
{
private:
    struct Node {
        int data;
        Node *next;
    };
    Node *front;    // first item
    Node *rear;     // last item
    Node *p;        // node to traverse
    Node *pp;       // previous node in traversal
    int size;   //size of queue
    
public:
    // Default Constructor
    IntLinkedQueue() : front(nullptr), rear(nullptr), size(0) {}
    // Destructor, clear function below handles destruction
    ~IntLinkedQueue() { }
    
    bool isEmpty(); //check if queue is empty
    int getSize(); //return size of queue
    void clear(); //clear entire queue
    string toString(); //return list as string
    
    bool add(int &); //push front
    bool append(int &); //push back
    bool fremove(); //pop front
    bool rremove(); //pop back
};

//Check if list is empty
bool IntLinkedQueue :: isEmpty()
{
    return front == nullptr;
}

//Return size of list
int IntLinkedQueue :: getSize()
{
    return size;
}

//Clear all nodes in list
void IntLinkedQueue :: clear()
{
    Node *dNode;    // points to deleted node
    
    if(isEmpty())   // return if queue already empty
        cout << "Queue is already clear." <<endl;
    else
    {
        p = front;  // begin at front of list
    
        while(p->next)  // traverse the list
        {
            dNode = p;
            p = p->next;
            delete dNode; //delete each node
        }
    
    front = rear = 0;   //reset front and rear to zero
    size = 0;   //reset size to zero
    }
}

//Return list as string, values separated by commas
string IntLinkedQueue :: toString()
{
    string output = "";
    p = front;
    
    while (p != nullptr)
    {
        output += to_string(p->data);
        output += ", ";
        p = p->next;
    }
    
    return output;
}

//Add value to front of list
bool IntLinkedQueue :: add(int &n)
{
    Node *newNode; //to point to new node
    
    //Allocate new node and store value
    newNode = new Node;
    newNode->data = n;
    newNode->next = nullptr;
    
    if(isEmpty()) //if no nodes in  list
    {
        front = newNode; //make new node front
        rear = newNode;
    }
    else
    {
        newNode->next = front; //make new node point to front node
        front = newNode; //make new node front
    }
    
    size++; //increment size of list
    return true;
}

//Append value to end of list
bool IntLinkedQueue :: append(int &n)
{
    Node *newNode; //to point to new node
    
    //Allocate new node and store value
    newNode = new Node;
    newNode->data = n;
    newNode->next = nullptr;
    
    if(isEmpty()) //if no nodes in list
           front = newNode; //make new node front
    else
    {
        p = front; //initialize nodePtr with front
        
        while(p->next) //traverse list
            p = p->next; //find last node in list
        
        p->next = newNode; //insert new node at end
        rear = newNode;
    }
    
    size++; // increment size of list
    return true;
}

//Remove value from front of list
bool IntLinkedQueue :: fremove()
{
    if(isEmpty())   // if list is empty, return
        return false;
    else
    {
        p = front;  // point to front
        front = front->next; // push front to next node
        delete p; //delete first node
        
        size--; //decrement size of list
        return true;
    }
}

bool IntLinkedQueue :: rremove()
{
    if(isEmpty())   // if list is empty, return
        return false;
    else
    {
        p = front;  // start at front of list
        pp = front;
        
        while(p->next)  // traverse the list
        {
            pp = p;
            p = p->next;
        }
        
        rear = pp;  //rear points to previous node
        rear->next = nullptr; //remove last node
        
        size--; // decrement size
        return true;
    }
}


#endif /* LinkedQueue_h */
