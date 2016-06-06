/*****************************************************************************
 *
 * file IntList.cpp
 * the implementation file for the IntList class
 *
 * Shawn Quinn
 * quinnms1
 * 11/08/2014
 *
 ****************************************************************************/

#include "IntList.h"

/*****************************************************************************
 * constructor
 *
 * initialize head, tail and numItems
 *
 ****************************************************************************/
IntList::IntList() : head(nullptr), tail(nullptr), numItems(0)
{
}

/*****************************************************************************
 * destructor
 *
 * call method emptyList to free all allocated memory
 *
 ****************************************************************************/
IntList::~IntList()
{
   emptyList();
}

/*****************************************************************************
 * public method add
 *
 * create a new Node
 * - initialize the data member to the argument passed in
 * - initialize the next member to nullptr
 * - if the list is empty, set head and tail to new node
 * - otherwise, set the next member of the tail to the new node
 * - and then set the tail to the new node
 *
 ****************************************************************************/
void IntList::add(int item)
{
   Node* tempNode = new Node;
   tempNode->data = item;
   tempNode->next = nullptr;
   if(numItems == 0)
   {
      head = tempNode;
      tail = head;
      head->next = tail;
   }
   else
   {
      tail->next = tempNode;
      tail = tempNode;
   }
   ++numItems;
}

/*****************************************************************************
 * public method insert
 *
 * - check whether the item number is in the list or at the end of the list
 * - create a new Node, set data member to itemVal
 * - traverse the list to the item just prior to the item number to be 
 *   inserted
 * - set the next member of the new node to the next member of the node prior
 *   to the insertion location
 * - set the next member of the node prior to the insertion point to the
 *   new node
 * - check for special cases: insert head, node after nead, or tail
 *
 ****************************************************************************/
void IntList::insert(int itemNum, int itemVal)
{
   if(((1 + getNumItems()) >= itemNum) && itemNum > 0)
   {
      Node* insNode = new Node;
      insNode->data = itemVal;
      insNode->next = nullptr;
      if(itemNum == 1)  // insert head node
      {
         if(numItems == 0)       // empty list
         {
            head = insNode;
            tail = head;
            head->next = tail;
         }
         else if(numItems == 1)
         {
            insNode->next = head;
            tail = head;         // assign tail node
            tail->next = nullptr;
            head = insNode;      // reassign head node
         }
         else
         {
            insNode->next = head;
            head = insNode;      // reassign head node
         }
      }
      else if(itemNum == 2)      // insert node after head node
      {
         if(numItems == 1)       // head node is only node
         {
            head->next = insNode;
            tail = insNode;      // assign tail
            tail->next = nullptr;
         }
         else
         {
            insNode->next = head->next;
            head->next = insNode;
         }
      }
      else
      {
         Node* iterNode = head;              // start at head node
         for(int i = 1; i < itemNum - 1; i++)
         {
            iterNode = iterNode->next;       // point to next node
          }
         // iterNode now points to node prior to insertion point
         if(itemNum == numItems + 1)   // check if end of list
         {
            iterNode->next = insNode;
            tail = insNode;            // reassign tail
         }
         else
         {
            insNode->next = iterNode->next;
            iterNode->next = insNode;
         }
      }
       ++numItems;
   }
   else
   {
      cout << "item number not in list..." << endl;
   }
}


/*****************************************************************************
 * public method remove
 *
 * - check whether the item number is in the list
 * - create a temporary local node variable to be used for traversal
 * - traverse the list to the item just prior to the item number to be deleted
 * - set the next member of the temp node to one node after the next member
 * - delete the node just after the temporary node
 * - set the deleted node to nullptr
 * - check for special cases: deleting head, node after nead, or tail
 *
 ****************************************************************************/
void IntList::remove(int itemNum)
{
   if((getNumItems() >= itemNum) && itemNum > 0)
   {
      if(itemNum == 1)  // remove head node
      {
         Node* iterNode = head;  // point to node to delete
         if(tail == head)
         {
            delete iterNode;
            iterNode = nullptr;
            head = nullptr;
            tail = nullptr;
         }
         else
         {
            head = head->next;   // reassign head node
            delete iterNode;
            iterNode = nullptr;
         }
      }
      else if(itemNum == 2) // remove node after head node
      {
         Node* iterNode = head->next; // point to node to delete
         if(iterNode == tail)
         {
            tail = head;
            head->next = nullptr;
         }
         else
         {
            head->next = iterNode->next;
            delete iterNode;
            iterNode = nullptr;
         }
      }
      else
      {
         Node* iterNode = head;              // start at head node
         for(int i = 1; i < itemNum - 1; i++)
         {
            iterNode = iterNode->next;       // point to next node
         }
         // iterNode points to the item prior to the item to delete
         if(tail == iterNode->next)
         {
            // deleting tail, move tail up one spot
            tail = iterNode;
            iterNode = iterNode->next;
            delete iterNode;
            iterNode = nullptr;
         }
         else
         {
            // iterNode->next is the item to delete
            Node* delNode = iterNode->next;
            iterNode->next = delNode->next;
            delete delNode;
            delNode = nullptr;
         }
      }
       --numItems;
   }
   else
   {
      cout << "item number not in list..." << endl;
   }
}

/*****************************************************************************
 * public method emptyList
 *
 * call the remove method on the head item until the list is empty
 *
 ****************************************************************************/
void IntList::emptyList(void)
{
   while(getNumItems() > 0)
   {
      remove(1);                 // remove the head item until list empty
   }
}

/*****************************************************************************
 * public method printList
 *
 * print the items in the list in order
 *
 ****************************************************************************/
void IntList::printList(void)
{
   cout << endl << "printing the list ..." << endl << endl;
   Node* tempNode = head;
   for(int i = 1; i <= getNumItems(); i++)
   {
      cout << "item number " << i << " = " << tempNode->data << endl;
      tempNode = tempNode->next;
   }
}

/*****************************************************************************
 * public method getNumItems
 *
 * return the number of items in the list
 *
 ****************************************************************************/
const int IntList::getNumItems(void) const
{
   return numItems;
}

/*****************************************************************************
 * public method getItemVal
 *
 * return the data value of the item at itemNum
 *
 ****************************************************************************/
int IntList::getItemVal(int itemNum) const
{
   Node* tempNode = head;
   for(int i = 1; i < itemNum; i++)
   {
      tempNode = tempNode->next;
   }
   return tempNode->data;
}

/*****************************************************************************
 * public method operator=
 *
 * - clear the list by calling emptyList
 * - add each item from the right hand list one at a time by calling add
 * - return the new list
 *
 ****************************************************************************/
IntList& IntList::operator=(IntList& rhsList)
{
   emptyList();
   for(int i = 1; i <= rhsList.getNumItems(); i++)
   {
      add(rhsList.getItemVal(i));
   }
   return *this;
}

/*****************************************************************************
 * public method mergeSort
 *
 * - create a temporary IntList to hold values during sorting
 * - create 2 temporary Node pointers to allow accessing small sublists
 *   of the larger list that is being sorted
 * - start with the smallest sublist possible, size == 1
 * - at the beginning of each pass through the list, intialize one node 
 *   pointer to the head of the list, and the other to the list immediately
 *   after the first sublist
 * - compare values in each list, adding smaller values first to the 
 *   temporary list
 * - increment number of merges for each sublist merged
 * - after each pass through the list, doble the size of the sublist
 *   and repeat the sublist merge step
 * - continue looping until the number of merges after a merge loop is 1
 *
 ****************************************************************************/
void IntList::mergeSort(void)
{
   Node* p;                // create temporary nodes
   Node* q;                // for use in sorting
   IntList T;              // create a empty temporary list
   int k = 1;              // initial size of sublist
   int psize = 0;
   int qsize = 0;
   int numMerges = 0;      // initialize number of merges to zero
   while(numMerges != 1)   // repeat until number of merges equals 1
   {
      p = head;
      numMerges = 0;
      while(p != nullptr)  // while p != NULL do
      {
         ++numMerges;   // keep track of number of merges
         q = p;
         int i = 0;
         // Step q along the list k items (or until end of list)
         while(i < k && q != tail)
         {
            q = q->next;
            i++;
         }
         psize = i;  // Set psize to actual number of items skipped
         qsize = k;  // qsize = k {Merge a list of length psize, starting 
         // merge step, loop through sublists, adding values to T in order
         while(psize > 0 || (qsize > 0 && q != nullptr))
         {
            if(qsize == 0 || q == nullptr) //if q is empty, add p
            {
               T.add(p->data);
               p = p->next;
               --psize;                   // keep track of added items
            }
            else if(psize == 0)           // if p is empty, add q
            {
               T.add(q->data);
               q = q->next;
               --qsize;
            }
            else                 // otherwise, compare and add smaller value
            {
               if(p->data < q->data)
               {
                  T.add(p->data);
                  p = p->next;
                  --psize;
               }
               else
               {
                  T.add(q->data);
                  q = q->next;
                  --qsize;
               }
            }   
         }
         p = q;   // point to next list
      }// end while
      *this = T;
      T.emptyList();
      k = k * 2;
   }// until number of merges equals 1
}