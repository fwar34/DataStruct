/*************************************************************************
    > File Name: test.cpp
    > Author: Feng
    > Created Time: 2017年05月28日 星期日 09时24分15秒
    > Content: 
 ************************************************************************/

#include <sys/time.h>
#include <iostream>
#include "rbTree.h"

using namespace std;

int main()
{
	rbtree<int> tree;
	srand(time(NULL));

	int* array = new int[13];
	for (int i = 0; i < 13; ++i)
	{
		array[i] = rand();
	}

	//int array[16] = {10, 7, 3, 18, 3, 9, -1, 98, 0, 83, 1, 100, -87, 33, 21, 12};
	
	cout << "-------------------begin1-----------------" << endl;
	struct timeval tv1, tv2;
	gettimeofday(&tv1, NULL);
	for (int i = 0; i < 13; ++i)
	{
		tree.insert(array[i]);
		//tree.printtree();
		//cout << "----------------------------------------" << endl;
		//tree.levelout();
		//cout << "-----------------endl-------------------" << endl;
	}
	gettimeofday(&tv2, NULL);
	cout << "------------------insert complete, time----------------------- " 
		<< tv2.tv_sec * 1000000 + tv2.tv_usec - tv1.tv_sec * 1000000 - tv1.tv_usec << endl;
	cout << "size  = " << tree.size() << " height = " << tree.height() << endl;	

	//tree.levelout();
	tree.PrintBinaryTree();

	cout << "-------------------begin2-----------------" << endl;
	struct timeval tv3, tv4;
	gettimeofday(&tv3, NULL);
	for (int i = 0; i < 13; ++i)
	{
		cout << "remove " << array[i] << endl;
		tree.remove(array[i]);
		tree.PrintBinaryTree();
		//cout << "----------------------------------------" << endl;
		//tree.levelout();
		//cout << "-----------------endl-------------------" << endl;
	}
	gettimeofday(&tv4, NULL);
	cout << "------------------remove complete, time----------------------- " 
		<< tv4.tv_sec * 1000000 + tv4.tv_usec - tv3.tv_sec * 1000000 - tv3.tv_usec << endl;
	cout << "size  = " << tree.size() << " height = " << tree.height() << endl;	

	tree.PrintBinaryTree();

	return 0;
}
