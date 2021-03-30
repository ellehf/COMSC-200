//
//  Deque.h
//  AS10 Template Deque
//
//  Created by Elle Hoarau on 5/2/20.
//  Copyright © 2020 Elle Hoarau. All rights reserved.
//

#ifndef Deque_h
#define Deque_h
#include <iostream>
using namespace std;

// Node of a doubly linked list
template<class T>
class Node  {
public:
    T data;
    Node<T> *prev, *next;
    static Node<T>* getnode(int data) {
        Node<T>* n = new Node<T>;
        n->data = data;
        n->prev = n->next = nullptr;
        return n;
    }
};

// A doubly linked list deque
template<class T>
class Deque
{
private:
    Node<T> *head, *tail, *copy;
    int size;
    
    // deep copy helper, this private helper creates a local duplicated Deque pointed by *copy
    void deepCopy( const Deque<T> & rhs );
public:
    Deque():head(nullptr), tail(nullptr), size(0) { }
    Deque(const Deque<T> &rhs); // copy constructor
    Deque(Deque<T> &&rhs);        // move constructor
    
    Deque<T> & operator= (Deque<T> &rhs); // copy operator=
    Deque<T> & operator= (Deque<T> &&rhs); // move operator=
    
    // Operations on Deque
    void pushHead(T data);
    void pushTail(T data);
    void popHead();
    void popTail();

    void erase();
    T getFront();
    T getRear();
    int getSize() { return size; }
    bool isEmpty() { return !head; }
    T operator[] (const int &sub);
};

template<class T>
void Deque<T> :: deepCopy(const Deque<T> &rhs)
{
    Node<T> *newNode = new Node<T>;
    Node<T> *current = rhs.head; //current points to the list to be copied
    size = rhs.size;//copy the head node
    copy = newNode; //create the node
    copy->data = current->data; //copy the info
    copy->next = current->next; //set the link field of the node to nullptr
    copy->prev = current->prev;
    tail = head; //make tail point to the head node

    current = current->next; //make current point to the next node
    //copy the remaining list
    while (current != nullptr)
    {
        newNode = new Node<T>; //create a node
        newNode->data = current->data; //copy the info
        newNode->next = current->next;
        newNode->prev = current->prev;
        tail->next = newNode;
        tail = newNode;
        current = current->next;
    }
}

//COPY CONSTRUCTOR
template<class T>
Deque<T> :: Deque(const Deque<T> &rhs) : head(nullptr), tail(nullptr), size(0)
{
    Node<T> *nodePtr = rhs.head; //Create new node, initialize with head
    size = rhs.size; //Copy size

    //Traverse otherstack with curr
    while(nodePtr != nullptr)
    {
        if(head == nullptr) //To copy first element in new deque
        {
            head = new Node<T>; //Create new node
            head->data = nodePtr->data; //Copy elements to new node
            head->next = nullptr;
            tail = head;
        }
        else //To copy rest of elements in deque
        {
            Node<T> *newNode = new Node<T>; //Create new node
            newNode->data = nodePtr->data; //Copy elements to new node
            newNode->next = nullptr;
            tail->next = newNode; //Link nodes
            tail = newNode;
        }

        nodePtr = nodePtr->next; //Next element

    }
    
}

//MOVE CONSTRUCTOR
template<class T>
Deque<T> :: Deque(Deque<T> &&rhs) :  head(nullptr),tail(nullptr), size(0)
{
    //Copy elements to new deque
    head = rhs.head;
    tail = rhs.tail;
    copy = rhs.copy;
    size = rhs.size;
    
    //Remove elements from old deque
    rhs.head = nullptr;
    rhs.tail = nullptr;
    rhs.copy = nullptr;
    rhs.size = 0;
}

//COPY OPERATOR
template<class T>
Deque<T> &Deque<T> :: operator= (Deque<T> &rhs)
{
    //Initialize new deque
    head = nullptr;
    tail = nullptr;
    size = 0;
    
    //Copy elements
    deepCopy(rhs);
    return *this;
}

//MOVE OPERATOR
template<class T>
Deque<T> &Deque<T> :: operator= (Deque<T> &&rhs)
{
    //Initialize new deque
    head = nullptr;
    tail = nullptr;
    size = 0;
    
    //Copy elements to new deque
    head = rhs.head;
    tail = rhs.tail;
    copy = rhs.copy;
    size = rhs.size;
    
    //Reset elements of old deque
    rhs.head = nullptr;
    rhs.tail = nullptr;
    rhs.copy = nullptr;
    rhs.size = 0;
    
    return *this;
}

//CLEAR DEQUE
template<class T>
void Deque<T> :: erase()
{
    Node<T> *nodePtr;
    Node<T> *dNode;    //Points to deleted node
    
    if(isEmpty())   // return if queue already empty
        cout << "Deque is already clear." <<endl;
    else
    {
        nodePtr = head;  //Begin at front of list
    
        while(nodePtr->next)  //Traverse the list
        {
            dNode = nodePtr;
            nodePtr = nodePtr->next;
            delete dNode; //Delete each node
        }
    
    head = tail = 0;   //Reset front and rear to zero
    size = 0;   //Reset size to zero
    }
}

//RETURN FRONT
template<class T>
T Deque<T> :: getFront()
{
    if(head == nullptr) //If deque is empty return 0
    {
        return 0;
    }
    else
        return head->data; //Return data pointed to by head
}

//RETURN BACK
template<class T>
T Deque<T> :: getRear()
{
    if(head == nullptr) //If deque is empty return 0
    {
        return 0;
    }
    else
        return tail->data; //Return data pointed to by tail
}

//OVERLOADING SUBSCRIPT OPERATOR[]
template<class T>
T Deque<T> :: operator[] (const int &sub)
{
    if(sub >=0 && sub <size) //If index is within range
    {
        Node<T> *nodePtr = head; //Traversal node
        
        int pos = 0; //Begin at position 0

        while(pos < sub) //Move through list until index is found
        {
            nodePtr = nodePtr->next; //Traverse list
            pos++; //Increment position
        }

        return nodePtr->data; //Return data held at index position
    }
    
    else //If index is out of range, return 0
    {
        cout<< "ERROR: Subscript out of range, ";
        return 0;
    }
}

//ADD TO FRONT
template<class T>
void Deque<T> :: pushHead(T d)
{
    Node<T> *newNode; //Point to new node
    
    //Allocate new node and store value
    newNode = new Node<T>;
    newNode->data = d;
    newNode->next = nullptr;
    
    if(isEmpty()) //If no nodes in  list
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head; //Make new node point to front node
        head = newNode; //Make new node front
    }
    
    size++; //Increment size of list
}

//ADD TO BACK
template<class T>
void Deque<T> :: pushTail(T d)
{
    Node<T> *newNode; //Point to new node
    Node<T> *nodePtr;
    
    //Allocate new node and store value
    newNode = new Node<T>;
    newNode->data = d;
    newNode->next = nullptr;
    
    if(isEmpty()) //If no nodes in list
           head = newNode; //Make new node front
    else
    {
        nodePtr = head; //Initialize nodePtr with front
        
        while(nodePtr->next) //Traverse list
            nodePtr = nodePtr->next; //Find last node in list
        
        nodePtr->next = newNode; //Insert new node at end
        tail = newNode;
    }
    
    size++; //Increment size of list
}

//REMOVE FRONT
template<class T>
void Deque<T> :: popHead()
{
    if(isEmpty())   //If list is empty, return
        cout << "Deque is empty." <<endl;
    else
    {
        Node<T> *nodePtr = head;  //Point to front
        head = head->next; //Push front to next node
        delete nodePtr; //Delete first node
        
        size--; //Decrement size of list
    }
}

//REMOVE BACK
template<class T>
void Deque<T> :: popTail()
{
    if(isEmpty())   //If list is empty, return
        cout << "Deque is empty." <<endl;
    else
    {
        Node<T> *nodePtr = head;
        Node<T> *prevPtr = head;
        
        while(nodePtr->next)  //Traverse the list
        {
            prevPtr = nodePtr;
            nodePtr = nodePtr->next;
        }
        
        tail = prevPtr;  //Tail points to previous node
        tail->next = nullptr; //Remove last node
        
        size--; //Decrement size
    }
}

#endif /* Deque_h */
