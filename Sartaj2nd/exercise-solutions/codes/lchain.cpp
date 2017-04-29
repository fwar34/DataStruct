
// split a list into two

#include <iostream.h>
#include "echain.h"
#include "citer.h"


template <class T>
void Split(Chain<T>& A, Chain<T>& B, Chain<T>& C)
{// Split A into two chains B and C.
 // When done, A is unchanged.
   // first free all nodes in B and C
   B.Erase();
   C.Erase();

   // assign elements alternately to B and C
   ChainIterator<T> a;  // iterator for A
   T *e = a.Initialize(A);
   while (e) {
      // first give B an element
      B.Append(*e);
      e = a.Next();
      if (!e) break;
      // now give C an element
      C.Append(*e);
      e = a.Next();
      }
}

void main(void)
{
   int n = 15;
   Chain<int> X, Y, Z;
   
   // initialize list to be split
   for (int i = 0; i < n; i++)
      X.Insert(0,i);
   cout << "The list is" << endl;
   cout << X << endl;
   
   Split(X,Y,Z);
   
   cout << "The first split list is" << endl;
   cout << Y << endl;
   
   cout << "The second split list is" << endl;
   cout << Z << endl;
}
