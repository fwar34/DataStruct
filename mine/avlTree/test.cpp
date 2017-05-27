/*************************************************************************
    > File Name: test.cpp
    > Author: Feng
    > Created Time: 2017年05月23日 星期二 10时56分01秒
    > Content: 非递归
 ************************************************************************/

#include <sys/time.h>
#include <iostream>
#include <set>
#include "avlTree.h"
using namespace std;

int main()
{
	avltree<int> tree;
	set<int> set1;

	srand(52554);
	int* array = new int[1000011];
	for (int i = 0; i < 1000011; ++i)
	{
		array[i] = rand();
	}

	cout << "-------------------begin1-----------------" << endl;
	struct timeval tv1, tv2;
	gettimeofday(&tv1, NULL);
	for (int i = 0; i < 1000011; ++i)
	{
		tree.insert(array[i]);
	}
	gettimeofday(&tv2, NULL);
	cout << "------------------insert complete, time----------------------- " 
		<< tv2.tv_sec * 1000000 + tv2.tv_usec - tv1.tv_sec * 1000000 - tv1.tv_usec << endl;
	cout << "size  = " << tree.size() << endl;	

	struct timeval tv5, tv6;
	gettimeofday(&tv5, NULL);
	for (int i = 0; i < 111117; ++i)
	{
		tree.remove(array[i * 3]);
	}
	gettimeofday(&tv6, NULL);
	cout << "------------------remove complete, time----------------------- " 
		<< tv6.tv_sec * 1000000 + tv6.tv_usec - tv5.tv_sec * 1000000 - tv5.tv_usec << endl;
	cout << "size  = " << tree.size() << endl;

	/*int array[10] = {10, 6, 15, 3, 8, 3, 20, 5, 90, -1};
	for (int i = 0; i < 10; ++i)
	{
		tree.insert(array[i]);
	}

	struct timeval tv5, tv6;
	gettimeofday(&tv5, NULL);
	for (int i = 0; i < 6; ++i)
	{
		tree.remove(array[i]);
	}
	gettimeofday(&tv6, NULL);
	cout << "------------------remove complete, time----------------------- " 
		<< tv6.tv_sec * 1000000 + tv6.tv_usec - tv5.tv_sec * 1000000 - tv5.tv_usec << endl;
	cout << "size  = " << tree.size() << endl;*/

	avltree<int> tree2;
	int array2[10] = {1, 3, -8, 9, 7, 6, 9, 10, 90, 4};
	for (int i = 0; i < 10; ++i)
	{
		tree2.insert(array2[i]);
		tree2.levelout();
		cout << "---------------------------------------" << endl;
	}

	for (int i = 0; i < 6; ++i)
	{
		tree2.remove(array2[i]);
		tree2.levelout();
		cout << "---------------------------------------" << endl;
	}
	

	return 0;
}

