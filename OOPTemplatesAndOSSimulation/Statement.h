/*****************************************************************************
 *
 * file Statement.h
 * class Program contains the interface of the Program class, used in 
 * conjuction with the Program class, Simulator class, and LinkedListT and 
 * LinkedQueueT template classes to implement a simple pre-emptive, 
 * multi-tasking operating system kernel with binary semaphore signalling 
 * mutual exclusion
 *
 * Shawn Quinn
 * quinnms1
 * 11/28/2014
 *
 ****************************************************************************/

#ifndef STATEMENT_H
#define STATEMENT_H

#include <iostream>
#include <sstream>

using namespace std;

/*****************************************************************************
 *
 * class Statement interface declaration
 *
 ****************************************************************************/
class Statement
{
public:
   // default constructor
   // - initialize line, lValue, rValue, opCode, and numTokens to default
   //   values
   Statement();

   // constructor
   // - initialize line, lValue, rValue, opCode, and numTokens to default
   // - values
   // - then call parseLine to update the values
   Statement(string line);

   // destructor
   ~Statement();

   // method getLValue
   // return lValue
   string getLValue(void) const;

   // method getRValue
   // return rValue
   string getRValue(void) const;

   // method getOpCode
   // return opValue
   string getOpCode(void) const;

   // method getNumValues
   // return number of values assigned to statement
   int getNumValues(void) const;

   // method newLine
   // - assign a new value to input line
   // - parse the new input line
   void newLine(string line);

   // friend method operator<<
   // - overload the insertion operator
   // - stream the Statement data member values left to right
   friend ostream&  operator<<(std::ostream& outStrm, const Statement& aStatement);

private:
   // method ParseLine
   // extract substring values and assign as appropriate to data fields
   void parseLine();

   // the input string
   string inputLine;

   // a string that represents a left-side value in a statement
   string lSideValue;

   // a string that represents a right-side value in a statement
   string rSideValue;

   // a string that represents operator value in a statement
   string opValue;

   // the total number of non-empty data members
   int numTokens;
};

#endif