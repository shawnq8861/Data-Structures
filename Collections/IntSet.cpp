// file array.cpp
// Member function definitions for class IntSet

#include "IntSet.h"

// --------------------------------------------------------------------------
// operator<< 
// Overloaded output operator for class IntSet
ostream& operator<<(ostream& output, const IntSet& in) {
   int i;
   output << "{";
   for (i = 0; i < in.size; i++)
   {
      if(in.intSetPtr[i] == true)
         output << " " << i;
   }
   output << "}";
   return output;                      // e.g., enables cout << x << y;
}

// --------------------------------------------------------------------------
// operator>> 
// Overloaded input operator for class IntSet
// inputs values for the data array
istream& operator>>(istream& input, IntSet& inSet)
{
   int val;
   while(input >> val)
   {
      inSet.insert(val);
      cout << "input value = " << val << endl;
   }
   
   return input;                        // e.g., enables cin >> x >> y;
}

// ---------------------------------------------------------------------------
// Constructor 
// Default and initializing constructor for class IntSet
IntSet::IntSet(int a, int b, int c, int d, int e)
{
   cout << "in default constructor..." << endl;
   size = a + 1;
   if(size < b + 1)
      size = b + 1;
   if(size < c + 1)
      size = c + 1;
   if(size < d + 1)
      size = d + 1;
   if(size < e + 1)
      size = e + 1;
   if(size < 1)                           // default case
      size = 1;

   intSetPtr = new bool[size];             // create space for array

   for (int i = 0; i < size; i++)         // initialize array elements
   {
      intSetPtr[i] = false;               // default initial value
      if(i == a && a > -1)
         intSetPtr[i] = true;
      if(i == b && b > -1)
         intSetPtr[i] = true;
      if(i == c && c > -1)
         intSetPtr[i] = true;
      if(i == d && d > -1)
         intSetPtr[i] = true;
      if(i == e && e > -1)
         intSetPtr[i] = true;
   }
}

// ---------------------------------------------------------------------------
// Copy 
// Copy constructor for class Array
IntSet::IntSet(const IntSet& init)
{
   cout << "in copy constructor..." << endl;
   size = init.size;                      // size this object
   intSetPtr = new bool[size];            // create space for array

   for (int i = 0; i < size; i++)
      intSetPtr[i] = init.intSetPtr[i];   // copy init into object
}

// ---------------------------------------------------------------------------
// Destructor 
// Destructor for class Array
IntSet::~IntSet()
{
   cout << "in destructor..." << endl;
   delete [] intSetPtr;                   // reclaim space for array
   intSetPtr = NULL;
}

// --------------------------------------------------------------------------
// method getSize
// returns the size of the IntSet object data array
int IntSet::getSize() const
{
   return size;
}

// --------------------------------------------------------------------------
// method reSize
// increase the capacity by allocating new memory and deallocating old
void IntSet::reSize(int newElem)
{
   bool* tempPtr = intSetPtr;             // copy pointer to temporary
   intSetPtr = new bool[newElem + 1];     // allocate new memory
   for(int i = 0; i < newElem + 1; i ++)  // copy data into new memory
   {
      if(i < size && tempPtr[i] == true)
         intSetPtr[i] = true;
      else
         intSetPtr[i] = false;
   }
   delete[] tempPtr;                      // free old memory
   size = newElem + 1;
}

// --------------------------------------------------------------------------
// method insert
// inserts an element into the IntSet object data array
bool IntSet::insert(int elem)
{
   if(-1 < elem && elem < size)           // elem is within range
   {
      intSetPtr[elem] = true;
      return true;
   }
   else if(elem >= size)                  // elem outside of range, reallocate
   {
      reSize(elem);
      intSetPtr[elem] = true;
      return true;
   }
   else                                   // invlaid element request
   {
      return false;
   }
}

// --------------------------------------------------------------------------
// method remove
// removes an element from the IntSet object data array
bool IntSet::remove(int elem)
{
   if(-1 < elem && elem < size)
   {
      intSetPtr[elem] = false;
      return true;
   }
   else
      return false;
}