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
	int array[998477];
	bstree<int> tree;
	
	srand(time(NULL));
	for (int i = 0; i < 998477; ++i)
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

	for (int i = 0; i < 100; ++i)
	{
		tree.remove(array[3 * i]);
		//cout << "remove " << array[1 + i] << ", after remove index " << 1 + i << ", now count = " << tree.count() << endl;
		//tree.ptree();
	}

	cout << "contains " << array[11] << (tree.contains(array[11]) ? " : true" : " : false") << endl;
	cout << "contains " << 99234231 << (tree.contains(99234231) ? " : true" : " : false") << endl;

	int array2[76765];
	for (int i = 0; i < 76765; ++i)
	{
		array2[i] = rand();
		tree.insert_r(array2[i]);
	}

	for (int i = 0; i < 3997; ++i)
	{
		tree.remove(array2[3 * i]);
		//cout << "remove " << array[1 + i] << ", after remove index " << 1 + i << ", now count = " << tree.count() << endl;
		//tree.ptree();
	}

	for (int i = 0; i < 33473; ++i)
	{
		tree.remove2(array[3 * i]);
		//cout << "remove " << array[1 + i] << ", after remove index " << 1 + i << ", now count = " << tree.count() << endl;
		//tree.ptree();
	}

	cout << "contains " << array2[33] << (tree.contains(array2[33]) ? " : true" : " : false") << endl;
	cout << "contains " << 99234231 << (tree.contains(99234231) ? " : true" : " : false") << endl;

	cout << "begin print, now count = " << tree.count() << endl;
	//tree.ptree();
	
	return 0;
}
