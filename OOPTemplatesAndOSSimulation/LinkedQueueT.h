/*****************************************************************************
 *
 * file LinkedQueueT.h
 * class LinkedQueueT contains the interface of a simple 
 * linked queue template class
 *
 * Shawn Quinn
 * quinnms1
 * 11/26/2014
 *
 ****************************************************************************/

#ifndef LINKEDQUEUET_H
#define LINKEDQUEUET_H

#include <iostream>

using namespace std;

/*****************************************************************************
 *
 * class LinkedQueueT interface declaration
 *
 ****************************************************************************/
template <typename T>
class LinkedQueueT
{
public:
   // constructor
   // - initialize head, tail and numItems
   LinkedQueueT();

   // destructor
   // - call method emptyList to free all allocated memory
   ~LinkedQueueT();

   // method enqueue
   // --------> add an item to the back of the queue
   // - create a new Node
   // - set the data member of the new node to the argument passed in
   // - set the next member of the new node to NULL
   // - if the queue is empty, set front and back to new node
   // - otherwise, set the next member of the back to the new node
   // - and then set the back to the new node
   void enqueue(T item);

   // method dequeue
   // --------> remove and return the item from the front of the queue
   // - if queue is empty, do nothing and return NULL
   // - otherwise, create a temporary local node variable
   // - set the temp node to the front node
   // - set the next member of the temp node to NULL
   // - set the front node to the node after the front node
   T dequeue(void);

   // method emptyQueue
   // - call the dequeue method until the queue is empty
   // - delete each item as it is dequeue to free the memory
   void emptyQueue(void);

   // method printList
   // - print the items in the queue in order to cout
   void printQueue(void);

   // method getNumItems
   // - return the number of items in the queue
   const int getNumItems(void) const;

   // method peek
   // - return the data value of the item at the front of the queue
   T peek(void) const;

   // method operator=
   // - clear the queue by calling emptyQueue
   // - enqueue each item from the right hand queue one at a time
   // - return the new queue
   LinkedQueueT<T>& operator=(LinkedQueueT<T>& rhsQueue);
   
private:
   // a data structure to hold the information for each link in the queue
   struct Node
   {
      T data;
      Node* next;
   };
   Node* front;    // points to first item in the queue
   Node* back;    // points to the last item in the queue
   int numItems;  // total number of items in the queue
};

#include "LinkedQueueT.cpp"

#endif