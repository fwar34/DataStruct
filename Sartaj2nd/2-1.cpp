/*************************************************************************
    > File Name: 2-1.cpp
    > Author: Feng
    > Created Time: 2017年04月29日 星期六 18时49分46秒
    > Content: 在数组中查找第一个与x相等的元素，找到了返回他的位置，否则返回-1
 ************************************************************************/

#include <iostream>

using namespace std;


template <typename T>
int findx(T arr[], int n, T x)
{
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] == x)
		{
			return i;
		}
	}

	return -1;
}

int main()
{
	int arr[3] = {1, 5, 7};
	cout <<	findx<int>(arr, 3, 5) << endl;

	return 0;
}
