/*****************************************************************************
 *
 * file Statement.cpp
 * the implementation file for the Statement class
 *
 * Shawn Quinn
 * quinnms1
 * 11/28/2014
 *
 ****************************************************************************/

#include "Statement.h"

/*****************************************************************************
 * default constructor
 * - initialize line, lValue, rValue, opCode, and numTokens to default
 *   values
 *
 ****************************************************************************/
Statement::Statement()
{
   inputLine = "";
   lSideValue = "";
   rSideValue = "";
   opValue = "";
   numTokens = 0;
}

/*****************************************************************************
 * constructor
 * - initialize line, lValue, rValue, opCode, and numTokens to default
 *   values
 * - then call parseLine to update values
 *
 ****************************************************************************/
Statement::Statement(string line)
{
   inputLine = line;
   lSideValue = "";
   rSideValue = "";
   opValue = "";
   numTokens = 0;
   parseLine();
}

/*****************************************************************************
 * destructor
 *
 ****************************************************************************/
Statement::~Statement()
{
}

/*****************************************************************************
 * method getLValue
 *
 * return lValue
 *
 ****************************************************************************/
string Statement::getLValue(void) const
{
   return lSideValue;
}

/*****************************************************************************
 * method getRValue
 *
 * return rValue
 *
 ****************************************************************************/
string Statement::getRValue(void) const
{
   return rSideValue;
}

/*****************************************************************************
 * method getOpCode
 *
 * return opValue
 *
 ****************************************************************************/
string Statement::getOpCode(void) const
{
   return opValue;
}

/*****************************************************************************
 * method getNumValues
 *
 * return number of values assigned to statement
 *
 ****************************************************************************/
int Statement::getNumValues(void) const
{
   return numTokens;
}

/*****************************************************************************
 * method newLine
 *
 * - assign a new value to input line
 * - parse the new input line
 *
 ****************************************************************************/
void Statement::newLine(string line)
{
   inputLine = line;
   lSideValue = "";
   rSideValue = "";
   opValue = "";
   numTokens = 0;
   parseLine();
}

/*****************************************************************************
 * friend method operator<<
 *
 * - overload the insertion operator
 * - stream the Statement data member values left to right
 *
 ****************************************************************************/
ostream&  operator<<(std::ostream& outStrm, const Statement& aStatement)
{
   outStrm << aStatement.getLValue() << " " << aStatement.getOpCode() << " " << aStatement.getRValue();
   return outStrm;
}

/*****************************************************************************
 * private method ParseLine
 *
 * - extract substring values and assign as appropriate to data fields
 * - statements consist of 1, 2 or 3 tokens
 * - assume that there is at least one token in the input string
 * - use a stringstream to parse the input string
 *
 ****************************************************************************/
void Statement::parseLine()
{
   numTokens = 0;
   string secondToken, thirdToken;
   stringstream tempSS(inputLine);
   tempSS >> lSideValue;         // stream first token
   if(lSideValue != "")
   {
      ++numTokens;               // first token has a value in it
   }
   tempSS >> secondToken;        // attempt to stream second token
   if(secondToken != "")
   {
      ++numTokens;               // second token has a value in it
      tempSS >> thirdToken;      // attempt to stream third token
      if(thirdToken != "")
      {
         ++numTokens;            // third token has a value in it
      }
   }
   if(numTokens == 2)
   {
      rSideValue = secondToken;
   }
   else if(numTokens == 3)
   {
      opValue = secondToken;
      rSideValue = thirdToken;
   }
 
}