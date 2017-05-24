/*************************************************************************
    > File Name: test.cpp
    > Author: Feng
    > Created Time: 2017年05月22日 星期一 16时05分30秒
    > Content: 
 ************************************************************************/

#include <iostream>
#include "avlTree_r.h"
using namespace std;

int main()
{
	avltree<int> tree;

	srand(52554);
	int* array = new int[1000011];
	for (int i = 0; i < 1000011; ++i)
	{
		array[i] = rand();
		tree.insert(array[i]);
	}
	cout << "------------------insert-----------------------" << endl;
	cout << "size  = " << tree.size() << endl;
	cout << "height = " << tree.height() << endl;

	for (int i = 0; i < 111117; ++i)
	{
		tree.remove(array[i * 3]);
	}
	cout << "------------------remove-----------------------" << endl;
	cout << "size  = " << tree.size() << endl;
	cout << "height = " << tree.height() << endl;

	delete[] array;

	int* array2 = new int[1078780];
	for (int i = 0; i < 1078780; ++i)
	{
		array2[i] = rand();
		tree.insert2(array2[i]);
	}
	cout << "------------------insert2-----------------------" << endl;
	cout << "size  = " << tree.size() << endl;
	cout << "height = " << tree.height() << endl;

	for (int i = 0; i < 111113; ++i)
	{
		tree.remove2(array2[i * 3]);
	}
	cout << "------------------remove2-----------------------" << endl;
	cout << "size  = " << tree.size() << endl;
	cout << "height = " << tree.height() << endl;

	delete[] array2;
	
	return 0;
}
