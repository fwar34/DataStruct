/*************************************************************************
    > File Name: 2-5-rank.cpp
    > Author: Feng
    > Created Time: 2017年04月29日 星期六 22时38分42秒
    > Content: 计算名次（名次是比它小的元素个数和左边和它相等的元素个数的总和）
 ************************************************************************/

#include <iostream>

using namespace std;

template <typename T>
void rank_f(T arr[], int n, int ret[])
{
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (arr[j] <= arr[i])
			{
				ret[i]++;
			}
			else
			{
				ret[j]++;
			}
		}
	}
}

int main()
{
	int arr[6] = {4, 3, 9, 3, 7, 2};
	int ret[6] = {0};

	rank_f<int>(arr, 6, ret);
	for (int val : ret)
	{
		cout << val << " ";
	}

	return 0;
}
