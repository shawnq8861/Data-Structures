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

// ----------------------------------------------------------------------------
// functions go here

bool sortInput(ifstream& inFile, StudentType* students, int& size)
{
   //assume name and grade are in a temporary location
   //loop from the end of the filled part of the array down to beginning
   StudentType tempStud;
   // insert first line of data into the array
   inFile >> students[size].last >> students[size].first >> students[size].grade;
   size++;
   if(!inFile.eof())
   {
      while(!inFile.eof())
      {
         inFile >> tempStud.last >> tempStud.first >> tempStud.grade;
         if(tempStud.grade < 0 || tempStud.grade > 100)
             continue;
         int i;
         for(i = size; i > 0; i--)
         {
            if(strcmp(tempStud.last, students[i - 1].last) < 0)
            {
               strcpy(students[i].last, students[i - 1].last);
			   strcpy(students[i].first, students[i - 1].first);
			   students[i].grade = students[i - 1].grade;
            }
            else if(strcmp(tempStud.last, students[i - 1].last) == 0 && 
                    strcmp(tempStud.first, students[i - 1].first) < 0)
            {
               strcpy(students[i].last, students[i - 1].last);
			   strcpy(students[i].first, students[i - 1].first);
			   students[i].grade = students[i - 1].grade;
            }
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
         cout << "*";
      }
      cout << endl;
      low += GROUP;
      if(i == 9)
         high = low;
      else
         high += GROUP;
   }
   cout << endl;
}

int findAverage(StudentType* students, int& size)
{
   int sum = 0;
   for(int i = 0; i < size; i++)
   {
      sum += students[i].grade;
   }
   return sum / size;
}

// You must put a separator line between every function
// Then comes the name of the function on a separate comment line
// Then comes the function comment. Clearly comment every function.
// Use bubble.cpp as a guide.