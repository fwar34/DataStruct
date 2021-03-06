
// loading containers on to two ships via backtracking
// code finds best loading of first ship as well as its weight
// incremental method to save bestx is used

#include<iostream.h>

template<class T>
class Loading {
   friend MaxLoading(T [], T, int, int []);
   private:
      void maxLoading(int i);
      int n,      // number of containers
          *x,     // current solution
          *bestx; // best solution so far
      T *w,       // container weight array
        c,        // ship capacity
        cw,       // weight of current loading
        bestw,    // weight of best loading so far
        r,        // sum of remaining container weights
        iMax;     // incremental saving of
                  // bestx[1:iMax] yet to be done
};

template<class T>
void Loading<T>::maxLoading(int i)
{// Search from level i node.
   if (i > n) {// at a leaf
      // need to save all values
      iMax = n;
      bestw = cw;
      return;}

   // check subtrees
   r -= w[i];
   if (cw + w[i] <= c) {// try x[i] = 1
      x[i] = 1;
      cw += w[i];
      maxLoading(i+1);
      if (iMax == i) {// must save x[i]
         bestx[i] = 1;
         iMax--;
         }
      cw -= w[i];
      }
   if (cw + r > bestw) {// try x[i] = 0
      x[i] = 0;
      maxLoading(i+1);
      if (iMax == i) {// must save x[i]
         bestx[i] = 0;
         iMax--;
         }
      }
   r += w[i];
}

template<class T>
T MaxLoading(T w[], T c, int n, int bestx[])
{// Return best loading and its value.
   Loading<T> X;
   // initialize X
   X.x = new int [n+1];
   X.w = w;
   X.c = c;
   X.n = n;
   X.bestx = bestx;
   X.bestw = 0;
   X.cw = 0;
   X.iMax = 0;
   // initial r is sum of all weights
   X.r = 0;
   for (int i = 1; i <= n; i++) 
      X.r += w[i];
   X.maxLoading(1);
   delete [] X.x;
   return X.bestw;
}



void main(void)
{
   int w[6] = {0, 2, 2, 4, 5, 6};
   int x[6];
   int n = 5;
   int c = 10;
   cout << "Value of max loading is" << endl;
   cout << MaxLoading(w,c,n,x) << endl;
   cout << "x values are" << endl;
   for (int i=1; i<=n; i++)
      cout << x[i] << ' ';
   cout << endl;
}
