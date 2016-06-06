// Functional test program for IntSet class

#include "IntSet.h"

int main (void)
{
   IntSet A(3, 2, 9);
   cout << "size A = " << A.getSize() << endl;
   cout << "A = " << A << endl;
   IntSet B = IntSet(A);
   cout << "size B = " << B.getSize() << endl;
   B.insert(5);
   cout << "B = " << B << endl;
   IntSet C;
   cout << "size C = " << C.getSize() << endl;
   A.insert(13);
   cout << "size A = " << A.getSize() << endl;
   cout << "A = " << A << endl;
   B.insert(10);
   cout << "size B = " << B.getSize() << endl;
   cout << "B = " << B << endl;
   B.remove(3);
   cout << "size B = " << B.getSize() << endl;
   cout << "B = " << B << endl;
   IntSet D;
   cout << "enter a value" << endl;
   cin >> D;
   cout << "size D = " << D.getSize() << endl;
   cout << "D = " << D << endl;

   return 0;
}