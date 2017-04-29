/*************************************************************************
    > File Name: 2-2.cpp
    > Author: Feng
    > Created Time: 2017年04月29日 星期六 22时12分20秒
    > Content: 顺序查找x的递归实现
 ************************************************************************/

#include <iostream>

using namespace std;

template <typename T>
int findx(T arr[], int n, T x)
{
	if (n < 0) 
	{
		return -1;
	}

	if (arr[n - 1] == x)
	{
		return n - 1;
	}
	return findx(arr, n - 1, x);
}

int main()
{
	int arr[4] = {1, 3, 4, 2};
	cout <<	findx<int>(arr, 4, 4) << endl;

	return 0;
}
