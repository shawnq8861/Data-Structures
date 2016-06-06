/*****************************************************************************
 *
 * file prog4.cpp
 * the test driver file for the IntList class and mergeSort implementation
 *
 * Shawn Quinn
 * quinnms1
 * 11/09/2014
 *
 ****************************************************************************/

#include <fstream>
#include "IntList.h"

int main(void)
{
   IntList testSortList;
   ifstream inputFile("1000.txt");
   if (!inputFile)
   {
      cout << "File could not be opened." << endl;
      return 1;
   }

   cout << "building list from file..." << endl;
   int tempInt;
   inputFile >> tempInt;
   while(!inputFile.eof())
   {
      testSortList.add(tempInt);
      inputFile >> tempInt;
   }
   testSortList.add(tempInt);
   //cout << "printing read in list..." << endl;
   //testSortList.printList();
   inputFile.close();

   cout << "sorting read in list..." << endl;
   testSortList.mergeSort();

   //cout << "printing read in list..." << endl;
   //testSortList.printList();

   cout << "writing sorted list to file..." << endl;
   ofstream unsortedOutputFile("output.txt");
   for(int i = 1; i <= testSortList.getNumItems(); i++)
   {
      unsortedOutputFile << testSortList.getItemVal(i) << endl;
   }
   unsortedOutputFile.close();

   return 0;
}
