/*****************************************************************************
 *
 * file Program.cpp
 * the implementation file for the Program class
 *
 * Shawn Quinn
 * quinnms1
 * 11/28/2014
 *
 ****************************************************************************/

#include "Program.h"

int Program::variables[] = { 0 };      // initialize the static array

/*****************************************************************************
 * default constructor
 * - initialize programCounter, lowVar, highVar, minValue, and maxValue 
 *   to default values
 *
 ****************************************************************************/
Program::Program() : programCounter(0), programID(0), lowVar('a'), 
   highVar('z'), minValue(0), maxValue(100)
{
}

/*****************************************************************************
 * destructor
 *
 ****************************************************************************/
Program::~Program()
{
}

/*****************************************************************************
 * public method addStatement
 * - add a Statement to the end of the statementList
 *
 ****************************************************************************/
void Program::addStatement(Statement& statement)
{
   statementList.add(statement);
   ++programCounter;
}

/*****************************************************************************
 * public method executeStatement
 * - create a temporary local Statement
 * - look at value of numTokens
 * - if numTokens == 3, excute assignment statement
 * - else if numtokens == 2, execute print statement
 * - else, either execute lock, unlock or end depending on value of token
 *
 ****************************************************************************/
void Program::executeStatement(int& semaphore)
{
   Statement tempStatement = statementList.getItemVal(programCounter);
   cout << "statement retrieved: " << tempStatement << endl;
   if(tempStatement.getNumValues() == 3)
   {
      stringstream lValSS, rValSS;
      char lValChar;
      int lValInt, rValInt;
      cout << "lValString = " << tempStatement.getLValue() << endl;
      lValSS << tempStatement.getLValue(); // get left side of assignment
      lValSS >> lValChar;                   // convert to int for array index
      cout << "lValChar = " << lValChar << endl;
      lValChar -= 'a';
      lValInt = (int)lValChar;
      cout << "lValInt = " << lValInt << endl;
      rValSS << tempStatement.getRValue(); // get right side of assignment
      rValSS >> rValInt;                   // convert to int for value
      variables[lValInt] = rValInt;        // assign the new value
      cout << "new value = " << rValInt << endl;
   }
   else if(tempStatement.getNumValues() == 2)
   {
      stringstream rValSS;
      char rValChar;
      int rValInt;
      rValSS << tempStatement.getRValue(); // get right side of assignment
      rValSS >> rValChar;                   // convert to int for index
      rValChar -= 'a';
      rValInt = (int)rValChar;
      cout << programID << " : " << variables[rValInt] << endl;
   }
   else
   {

   }
}

// method updatePC
void Program::updatePC(int lineNumber)
{
   programCounter = lineNumber;
}

// method requestLock
bool Program::requestLock(int& semaphore)
{
   return true;
}

/*****************************************************************************
 * public method printListing
 * - print the statementList from top to bottom
 *
 ****************************************************************************/
void Program::printListing(void)
{
   statementList.printList();
}
