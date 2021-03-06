
// machine scheduling using LPT rule

#include <iostream.h>
#include "hsort.h"
#include "eminheap.h"
#include "lptnode2.h"

template <class T>
void LPT(T a[], int n, int m)
{// Construct an m machine LPT schedule.
   if (n <= m) {
      cout << "Schedule one job per machine." << endl;
      return;}

   HeapSort(a,n); // in ascending order
   // initialize m machines and the min heap
   ExtendedMinHeap<MachineNode, int> H(m);
   MachineNode x;
   for (int i = 1; i <= m; i++) {
       x.avail = 0;
       x.ID = i;
       H.Insert(x);
       }

   // construct schedule
   for (i = n; i >= 1; i--) {
      H.IncreaseMinKey(a[i].time, x);
      cout << "Schedule job " << a[i].ID 
           << " on machine " << x.ID << " from "
           << x.avail << " to "
           << (x.avail + a[i].time) << endl;
      x.avail += a[i].time;  // new avail time
      }
}

void main(void)
{
   JobNode a[11];
   int n = 10;
   for (int i = 1; i <= n; i++) {
      a[i].time = 2 * i * i;
      a[i].ID = i;
      }
   LPT(a,n,3);
}
