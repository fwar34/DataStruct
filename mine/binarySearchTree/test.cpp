/*************************************************************************
    > File Name: test.cpp
    > Author: Feng
    > Created Time: 2017年05月17日 星期三 21时44分46秒
    > Content: 测试bstree
 ************************************************************************/

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "binarySearchTree.h"

int main()
{
	int array[112233];
	bstree<int> tree;
	
	srand(time(NULL));
	for (int i = 0; i < 112233; ++i)
	{
		array[i] = rand();
		//array[i] = i;
		tree.insert(array[i]);
		//cout << "insert " << array[i] << endl;
	}
	//tree.ptree();
	cout << "min = " << tree.min() << endl;
	cout << "max = " << tree.max() << endl;
	cout << "count = " << tree.count() << endl;

	for (int i = 0; i < 25685; ++i)
	{
		tree.remove(array[3 * i]);
		//cout << "remove " << array[1 + i] << ", after remove index " << 1 + i << ", now count = " << tree.count() << endl;
		//tree.ptree();
	}

	cout << "contains " << array[1123] << (tree.contains(array[1123]) ? " : true" : " : false") << endl;
	cout << "contains " << 99234231 << (tree.contains(99234231) ? " : true" : " : false") << endl;

	int array2[342344];
	for (int i = 0; i < 342344; ++i)
	{
		array2[i] = rand();
		tree.insert_r(array2[i]);
	}

	for (int i = 0; i < 25689; ++i)
	{
		tree.remove(array2[3 * i]);
		//cout << "remove " << array[1 + i] << ", after remove index " << 1 + i << ", now count = " << tree.count() << endl;
		//tree.ptree();
	}

	cout << "contains " << array2[1133] << (tree.contains(array2[1123]) ? " : true" : " : false") << endl;
	cout << "contains " << 99234231 << (tree.contains(99234231) ? " : true" : " : false") << endl;

	cout << "begin print, now count = " << tree.count() << endl;
	//tree.ptree();
	
	return 0;
}
