/*****************************************************************************
 *
 * file LinkedListT.h
 * class LinkedListT contains the interface of a simple 
 * linked list template class
 *
 * Shawn Quinn
 * quinnms1
 * 11/25/2014
 *
 ****************************************************************************/

#ifndef LINKEDLISTT_H
#define LINKEDLISTT_H

#include <iostream>

using namespace std;

/*****************************************************************************
 *
 * class LinkedListT interface declaration
 *
 ****************************************************************************/
template <typename T>
class LinkedListT
{
public:
   // constructor
   // - initialize head, tail and numItems
   LinkedListT();

   // destructor
   // - call method emptyList to free all allocated memory
   ~LinkedListT();

   // method add
   // - create a new Node
   // - initialize the data member to the argument passed in
   // - initialize the next member to nullptr
   // - if the list is empty, set head and tail to new node
   // - otherwise, set the next member of the tail to the new node
   // - and then set the tail to the new node
   void add(T item);

   // method insert
   // - check whether the item number is in the list or at the end of the list
   // - create a new Node, set data member to itemVal
   // - traverse the list to the item just prior to the item number to be 
   //   inserted
   // - set the next member of the new node to the next member of the node prior
   //   to the insertion location
   // - set the next member of the node prior to the insertion point to the
   //   new node
   // - check for special cases: insert head, node after nead, or tail
   void insert(int itemNum, T itemVal);

   // method remove
   // - check whether the item number is in the list or at end of list
   // - create a temporary local node variable to be used for traversal
   // - traverse the list to the item just prior to the item number to insert
   // - set the next member of the temp node to one node after the next member
   // - delete the node just after the temporary node
   // - set the deleted node to nullptr
   // - check for special cases: deleting head, node after nead, or tail
   void remove(int itemNum);

   // method emptyList
   // - call the remove method on the head item until the list is empty
   void emptyList(void);

   // method printList
   // - print the items in the list in order to cout
   void printList(void);

   // method getNumItems
   // - return the number of items in the list
   const int getNumItems(void) const;

   // method getItemVal
   // - return the data value of the item at itemNum
   T getItemVal(int itemNum) const;

   // method operator=
   // - clear the list by calling emptyList
   // - add each item from the right hand list one at a time by calling add
   // - return the new list
   LinkedListT<T>& operator=(LinkedListT<T>& rhsList);

   // method mergeSort
   // - check for special cases, list size 0, 1, or 2, handle separately
   // - otherwise, for lists of size > 2
   // - create a temporary IntList to hold values during sorting
   // - create 2 temporary Node pointers to allow accessing small sublists
   //   of the larger list that is being sorted
   // - start with the smallest sublist possible, size == 1
   // - at the beginning of each pass through the list, intialize one node 
   //   pointer to the head of the list, and the other to the list immediately
   //   after the first sublist
   // - compare values in each list, adding smaller values first to the 
   //   temporary list
   // - increment number of merges for each sublist merged
   // - after each pass through the list, doble the size of the sublist
   //   and repeat the sublist merge step
   // - continue looping until the number of merges after a merge loop is 1
   void mergeSort(void);
   
private:
   // a data structure to hold the information for each link in the list
   struct Node
   {
      T data;
      Node* next;
   };
   Node* head;    // points to first item in the list
   Node* tail;    // points to the last item in the list
   int numItems;  // total number of items in the list
};

#include "LinkedListT.cpp"

#endif