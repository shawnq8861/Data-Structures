/*****************************************************************************
 *
 * file Program.h
 * class Program contains the interface of the Program class, used in 
 * conjuction with the Statement class, Simulator class, and LinkedListT and 
 * LinkedQueueT template classes to implement a simple pre-emptive, 
 * multi-tasking operating system kernel with binary semaphore signalling 
 * mutual exclusion
 *
 * Shawn Quinn
 * quinnms1
 * 11/28/2014
 *
 ****************************************************************************/

#ifndef PROGRAM_H
#define PROGRAM_H

#include <iostream>
#include "LinkedListT.h"
#include "Statement.h"

using namespace std;

/*****************************************************************************
 *
 * class Program interface declaration
 *
 ****************************************************************************/
class Program
{
public:
   // default constructor
   // - initialize programCounter, programID, lowVar, highVar, minValue, 
   //   and maxValue to default values
   Program();

   // destructor
   ~Program();

   // method addStatement
   // - add a Statement to the end of the statementList
   void addStatement(Statement& statement);

   // method executeStatement
   // - create a temporary local Statement
   // - look at value of numTokens
   // - if numTokens == 3, excute assignment statement
   // - else if numtokens == 2, execute print statement
   // - else, either execute lock, unlock or end depending on value of token
   void executeStatement(int& semaphore);

   // method updatePC
   void updatePC(int lineNumber);

   // method requestLock
   bool requestLock(int& semaphore);

   // method printListing
   // - print the statementList from top to bottom
   void printListing(void);

private:
   // list of Statements that comprise the Program object
   LinkedListT<Statement> statementList;

   // point to the next statement to execute
   int programCounter;

   // a unique identifier assigned to the Program object
   int programID;

   // lowest value alphanumeric variable name
   const char lowVar;

   // highest value alphanumeric variable name
   const char highVar;

   // minimum allowable value for assignment
   const unsigned int minValue;

   // maximum allowable value for assignment
   const unsigned int maxValue;

   // pre-allocated, common storage for program variables
   static int variables[26];

};

#endif