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
	int* array = new int[1000011];
	for (int i = 0; i < 1000011; ++i)
	{
		array[i] = rand();
		tree.insert(array[i]);
	}
	delete[] array;

	cout << "size  = " << tree.size() << endl;
	cout << "height = " << tree.height() << endl;

	int* array2 = new int[1078780];
	for (int i = 0; i < 1078780; ++i)
	{
		array2[i] = rand();
		tree.insert2(array2[i]);
	}
	delete[] array2;

	cout << "size  = " << tree.size() << endl;
	cout << "height = " << tree.height() << endl;
	
	return 0;
}
