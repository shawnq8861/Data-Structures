// file IntSet.h
// Simple class IntSet uses a dynamically allocated array to keep track of
// a set of integer values

#ifndef INTSET_H
#define INTSET_H

#include <iostream>
using namespace std;

//---------------------------------------------------------------------------
// IntSet class:  interface for a dynamic bool array that keeps a tally
// of integer values
//   also includes additional features:
//   -- allows input and output of the whole IntSet
//   -- allows for comparison of 2 IntSets, element by element
//   -- allows for assignment of 2 IntSets
//   -- size is part of the class (so no longer needs to be passed)
//   -- includes range checking
//
// Implementation and assumptions:
//   -- up to 5 initial values may be passed to the constructor
//   -- IntSet elements are initialized to zero
//   -- user must enter valid integers when using >>
//   -- in <<, integers are displayed 10 per line
//---------------------------------------------------------------------------

class IntSet
{
   friend ostream& operator<<(ostream&, const IntSet&);
   friend istream& operator>>(istream&, IntSet&);

public:
   //IntSet();                              // default constructor
   IntSet(int a = -1, int b = -1, int c = -1, int d = -1, int e = -1);
   IntSet(const IntSet&);                 // copy constructor
   ~IntSet();                             // destructor

   IntSet& operator+(const IntSet&);      // union of 2 IntSet objects
   IntSet& operator*(const IntSet&);      // intersection of 2 IntSet objects
   IntSet& operator-(const IntSet&);      // difference of 2 IntSet objects
   IntSet& operator=(const IntSet&);      // assign on IntSet to another
   IntSet& operator+=(const IntSet&);     // union assignment
   IntSet& operator*=(const IntSet&);     // intersection assignment
   IntSet& operator-=(const IntSet&);     // difference assignment
   bool operator==(const IntSet&) const;  // compare for equal of 2 IntSets
   bool operator!=(const IntSet&) const;  // compare not equal of 2 IntSets
   bool insert(int);                      // insert an element into an IntSet
   bool remove(int);                      // remove an element from an IntSet
   bool isEmpty(void);                    // determine if IntSet is empty
   bool isInSet(int);                     // check for an int in IntSet
   int getSize(void) const;               // fetch size of IntSet

private:
   void reSize(int newElem);              // increase array capacity
   bool* intSetPtr;                       // pointer to IntSet data array
   int size;                              // size of the IntSet
};

#endif