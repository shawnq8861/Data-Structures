// ----------------------------------------------------------------------------
// You write meaningful overview comments and assumptions here

#include <string.h>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int const MAXSIZE = 100;            // maximum number of records in total
int const MAXLENGTH = 31;           // maximum string length 
int const MAXGRADE = 100;           // highest possible grade
int const LOWGRADE = 0;             // lowest possible grade
int const GROUP = 10;               // group amount
int const HISTOGRAMSIZE = (MAXGRADE-LOWGRADE)/GROUP + 1;    // grouped by GROUP

struct StudentType                  // information of one student
{
   int grade;                       // the grade of the student
   char last[MAXLENGTH];            // last name (MAXLENGTH-1 at most)
   char first[MAXLENGTH];           // first name (MAXLENGTH-1 at most)
};

// prototypes go here
bool sortInput(ifstream& inFile, StudentType* students, int& size);
void displayList(StudentType* students, int& size);
void setHistogram(StudentType* students, int& size, int* histogram);
void displayHistogram(int* histogram);
int findAverage(StudentType* students, int& size);

//-----------------------------------------------------------------------------
int main()
{
   StudentType students[MAXSIZE];   // list of MAXSIZE number of students
   int size = 0;                    // total number of students
   int histogram[HISTOGRAMSIZE];    // grades grouped by GROUP
   int average = 0;                 // average exam score, truncated

   // creates file object and opens the data file
   ifstream infile("data1.txt");
   if (!infile)
   { 
      cout << "File could not be opened." << endl; 
      return 1;  
   }

   // read and sort input by last then first name
   bool successfulRead = sortInput(infile, students, size);              

   // display list, histogram, and class average 
   if (successfulRead)
   {
      displayList(students, size);
      setHistogram(students, size, histogram);
      displayHistogram(histogram);
      average = findAverage(students, size);
      cout << "Average grade: " << average << endl << endl;
   }
   return 0;
}



//-----------------------------------------------------------------------------
// sortInput
// read the data from a file stream (the first parameter) and place into
// array of struct StudentType(second parameter) ; the third parameter, size, 
// is the number of items in the array, always less than the maximum size, 
// MAXSIZE

bool sortInput(ifstream& inFile, StudentType* students, int& size)
{
   StudentType tempStud;
   // insert first line of data into the array
   inFile >> students[size].last 
          >> students[size].first 
          >> students[size].grade;
   size++;
   if(!inFile.eof())
   {
      // continue reading data until end of file is reached
      while(!inFile.eof())
      {
         // read current student into temporary location
         inFile >> tempStud.last >> tempStud.first >> tempStud.grade;
         if(tempStud.grade < 0 || tempStud.grade > 100)
             continue;
         int i;
         // loop from end of filled part of array, compare first and last
         // names until correct location in array is found
         for(i = size; i > 0; i--)
         {
            // temp last lower the current last, copy current down array
            if(strcmp(tempStud.last, students[i - 1].last) < 0)
            {
               strcpy(students[i].last, students[i - 1].last);
               strcpy(students[i].first, students[i - 1].first);
               students[i].grade = students[i - 1].grade;
            }
            // temp last equals current last, temp first lower than current
            // first, copy current down array
            else if(strcmp(tempStud.last, students[i - 1].last) == 0 && 
                    strcmp(tempStud.first, students[i - 1].first) < 0)
            {
               strcpy(students[i].last, students[i - 1].last);
               strcpy(students[i].first, students[i - 1].first);
               students[i].grade = students[i - 1].grade;
            }
            // correct location, break out of loop
            else
            {
               break;
            }
         }
         //insert (copy) new data into correct sorted position
         strcpy(students[i].last, tempStud.last);
         strcpy(students[i].first, tempStud.first);
         students[i].grade = tempStud.grade;
         size++;
      }
   }
   
   return true;
}

//-----------------------------------------------------------------------------
// displayList
// display the data from the sorted array of StudentType structs 
// (first parameter), of length equal to size (second param); display 
// the members of one StudentType struct per line. 

void displayList(StudentType* students, int& size)
{
   cout << "List of names sorted:" << endl;
   for(int i = 0; i < size; i++)
   {
      cout << setw(3) << students[i].grade 
           << " " << students[i].last 
           << " " << students[i].first 
           << endl;
    }
}

//-----------------------------------------------------------------------------
// setHistogram
// for each element of the histogram array (third parameter), which 
// represents a grade range of GROUP, scan through the array of StudentType
// structs (first parameter) of length size (second parameter) and if the
// struct member grade falls within the grade range increment the value of
// histogram array element

void setHistogram(StudentType* students, int& size, int* histogram)
{
   int low = 0;
   for(int i = 0; i < HISTOGRAMSIZE; i++)
   {
      histogram[i] = 0;
      for(int j = 0; j < size; j++)
      {
         if((low <= students[j].grade) && (students[j].grade) < (low + GROUP))
            histogram[i] += 1;
      }
      low += GROUP;
   }
}

//-----------------------------------------------------------------------------
// displayHistogram
// display the data in the array of ints histogram (first parameter), 
// the array is of length equal to HISTOGRAMSIZE; for each element of the 
// array, display a corresponding number of asterix characters '*'.


void displayHistogram(int* histogram)
{
   int low = 0;
   int high = low + GROUP - 1;
   cout << endl;
   for(int i = 0; i < HISTOGRAMSIZE; i++)
   {
      cout << setw(3) << low << "-->" << setw(4) << high << ": ";
      for(int j = 0; j < histogram[i]; j++)
      {
         cout << '*';
      }
      cout << endl;
      low += GROUP;
      if(i == GROUP - 1) // last line in the display
         high = low;
      else
         high += GROUP; // every other line in the display
   }
   cout << endl;
}

//-----------------------------------------------------------------------------
// findAverage
// using the data from the sorted array of StudentType structs 
// (first parameter), of length equal to size (second param), calculate
// the mean grade value by summing together the grade members of each 
// struct and divide by the number of elements in the array

int findAverage(StudentType* students, int& size)
{
   int sum = 0;
   for(int i = 0; i < size; i++)
   {
      sum += students[i].grade;
   }
   return sum / size;
}
