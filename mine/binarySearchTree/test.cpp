/*************************************************************************
    > File Name: test.cpp
    > Author: Feng
    > Created Time: 2017年05月17日 星期三 21时44分46秒
    > Content: 
 ************************************************************************/

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "binarySearchTree.h"

int main()
{
	srand(time(NULL));
	bstree<int> tree;
	for (int i = 0; i < 100; ++i)
	{
		tree.insert(rand());
	}

	tree.ptree();
	
	return 0;
}
