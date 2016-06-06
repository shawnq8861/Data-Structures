/*****************************************************************************
 *
 * file prog5.cpp
 * the test driver file for the LinkedListT class, LinkQueueT class,
 * Program class, 
 *
 * Shawn Quinn
 * quinnms1
 * 11/09/2014
 *
 ****************************************************************************/

#include <string>
#include "LinkedListT.h"
#include "LinkedQueueT.h"
#include "Statement.h"
#include "Program.h"

int main(void)
{
   LinkedListT<int> yourList;
   yourList.add(87);
   yourList.add(5);
   yourList.insert(3, 14);
   cout << "\nprinting template list of " << yourList.getNumItems() << " ints...\n" << endl;
   yourList.printList();
   cout << "\nvalue of item 2 = " << yourList.getItemVal(2) << endl;
   cout << "\nprinting sorted template list of ints...\n" << endl;
   yourList.mergeSort();
   yourList.printList();
   yourList.remove(1);
   cout << "\nprinting modified template list of ints...\n" << endl;
   yourList.printList();

   LinkedListT<char> charList;
   charList.add('k');
   charList.add('l');
   charList.insert(3, 'b');
   cout << "\nprinting template list of " << charList.getNumItems() << " chars...\n" << endl;
   charList.printList();
   cout << "\nprinting sorted template list of chars...\n" << endl;
   charList.mergeSort();
   charList.printList();
   charList.remove(1);
   cout << "\nprinting modified template list of chars...\n" << endl;
   charList.printList();

   LinkedListT<string> strList;
   strList.add("Lion");
   strList.add("King");
   strList.insert(3, "Behavior");
   cout << "\nprinting template list of " << strList.getNumItems() << " strings...\n" << endl;
   strList.printList();
   cout << "\nprinting sorted template list of strings...\n" << endl;
   strList.mergeSort();
   strList.printList();
   strList.remove(1);
   cout << "\nprinting modified template list of chars...\n" << endl;
   strList.printList();

   LinkedQueueT<int> intQueue;
   intQueue.enqueue(7);
   intQueue.enqueue(59);
   intQueue.enqueue(24);
   cout << "\nprinting queue of ints...\n" << endl;
   intQueue.printQueue();
   int myInt = intQueue.dequeue();
   cout << endl << "dequeued:  " << myInt << endl;
   cout << "\nprinting queue of ints after dequeue...\n" << endl;
   intQueue.printQueue();
   cout << "\nenqueue value 103" << endl;
   intQueue.enqueue(103);
   myInt = intQueue.peek();
   cout << endl << "peek at front of queue:  " << myInt << endl;
   cout << "\nprinting queue of ints after enqueue and peek..." << endl;
   intQueue.printQueue();
   intQueue.emptyQueue();
   cout << "\nprinting queue of ints after calling empty()..." << endl;
   intQueue.emptyQueue();
   intQueue.printQueue();

   LinkedQueueT<string> strQueue;
   strQueue.enqueue("Lion");
   strQueue.enqueue("King");
   strQueue.enqueue("behavior");
   cout << "\nprinting queue of strings...\n" << endl;
   strQueue.printQueue();
   string myString = strQueue.dequeue();
   cout << endl << "dequeued:  " << myString << endl;
   cout << "\nprinting queue of strings after dequeue..." << endl;
   strQueue.printQueue();
   cout << "\nenqueue value ""thanksgiving""" << endl;
   strQueue.enqueue("thanksgiving");
   myString = strQueue.peek();
   cout << endl << "peek at front of queue:  " << myString << endl;
   cout << "\nprinting queue of strings after enqueue and peek..." << endl;
   strQueue.printQueue();
   strQueue.emptyQueue();
   cout << "\nprinting queue of strings after calling empty()..." << endl;
   strQueue.emptyQueue();
   strQueue.printQueue();

   Statement printStatement("print d");
   cout << "left side value = " << printStatement.getLValue() << endl;
   cout << "op code value = " << printStatement.getOpCode()<< endl;
   cout << "right side value = " << printStatement.getRValue()<< endl;
   cout << "number of values assigned = " << printStatement.getNumValues() << endl;

   Statement endStatement("end");
   cout << endl << "left side value = " << endStatement.getLValue() << endl;
   cout << "op code value = " << endStatement.getOpCode()<< endl;
   cout << "right side value = " << endStatement.getRValue()<< endl;
   cout << "number of values assigned = " << endStatement.getNumValues() << endl;

   Statement assignStatement("d = 47");
   cout << endl << "left side value = " << assignStatement.getLValue() << endl;
   cout << "op code value = " << assignStatement.getOpCode()<< endl;
   cout << "right side value = " << assignStatement.getRValue()<< endl;
   cout << "number of values assigned = " << assignStatement.getNumValues() << endl;

   char firstChar = 'a';
   int intVal = (int)firstChar;
   for(int i = 0; i < 26; ++i)
   {
      cout << "char[" << i << "] = " << firstChar << " int value = " << intVal << endl;
      firstChar++;
      intVal = (int)firstChar;
   }

   LinkedListT<Statement> statementList;
   statementList.add(assignStatement);
   statementList.add(printStatement);
   statementList.add(endStatement);
   cout << "\nprinting template list of " << statementList.getNumItems() << " statements...\n" << endl;
   statementList.printList();
   cout << "\nprinting second item in list: " << statementList.getItemVal(2) << endl;

   Program testProgram;
   testProgram.addStatement(assignStatement);
   testProgram.addStatement(printStatement);
   testProgram.addStatement(endStatement);
   cout << "\nprinting listing of test Program" << endl;
   testProgram.printListing();
   int semaphore = 0;
   testProgram.updatePC(1);
   testProgram.executeStatement(semaphore);
   testProgram.updatePC(2);
   testProgram.executeStatement(semaphore);

   return 0;
}