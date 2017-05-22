/*************************************************************************
    > File Name: test.cpp
    > Author: Feng
    > Created Time: 2017年05月22日 星期一 16时05分30秒
    > Content: 
 ************************************************************************/

#include <iostream>
#include <time.h>
#include "avlTree.h"
using namespace std;

int main()
{
	avltree<int> tree;

	srand(time(NULL));
	int array[55555];
	for (int i = 0; i < 55555; ++i)
	{
		array[i] = rand();
		tree.insert2(array[i]);
	}

	cout << "size  = " << tree.size() << endl;
	cout << "height = " << tree.height() << endl;

	int array2[100];
	for (int i = 0; i < 100; ++i)
	{
		array2[i] = rand();
		tree.insert2(array2[i]);
	}

	cout << "size  = " << tree.size() << endl;
	cout << "height = " << tree.height() << endl;
	
	return 0;
}
