

#include<iostream.h>
#include "bbinary.h"

void main(void)
{
   BinaryTree<int> a,b,x,y,z;
   y.MakeTree(1,a,a);
   z.MakeTree(2,a,a);
   x.MakeTree(3,y,z);
   y.MakeTree(4,x,a);
   cout << "The preorder sequence is ";
   y.PreOutput();
   cout << "The inorder sequence is ";
   y.InOutput();
   y.SwapChildren();
   cout << "The preorder sequence is ";
   y.PreOutput();
   cout << "The inorder sequence is ";
   y.InOutput();
}
