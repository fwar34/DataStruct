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

	int array3[10] = {10, 6, 15, 3, 4, 3, 7, 8, 11, 20};
	for (int i = 0; i < 10; ++i)
	{
		tree.insert(array3[i]);
	}
	
	//cout << "height = " << tree.height() << endl;

	/*struct timeval tv3, tv4;
	gettimeofday(&tv3, NULL);
	for (int i = 0; i < 1000011; ++i)
	{
		set1.insert(array[i]);
	}
	gettimeofday(&tv4, NULL);
	cout << "------------------std set insert complete, time----------------------- " 
		<< tv4.tv_sec * 1000000 + tv4.tv_usec - tv3.tv_sec * 1000000 - tv3.tv_usec << endl;
	cout << "size  = " << set1.size() << endl;	

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
	cout << "height = " << tree.height() << endl;

	struct timeval tv7, tv8;
	gettimeofday(&tv7, NULL);
	for (int i = 0; i < 111117; ++i)
	{
		set1.erase(array[i * 3]);
	}
	gettimeofday(&tv8, NULL);
	cout << "------------------std set erase complete, time----------------------- " 
		<< tv8.tv_sec * 1000000 + tv8.tv_usec - tv7.tv_sec * 1000000 - tv7.tv_usec << endl;
	cout << "size  = " << set1.size() << endl;	

	delete[] array;

	int* array2 = new int[1078780];
	for (int i = 0; i < 1078780; ++i)
	{
		array2[i] = rand();
	}

	cout << "-------------------begin2-----------------" << endl;
	for (int i = 0; i < 1078780; ++i)
	{
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

	delete[] array2;*/

	return 0;
}

