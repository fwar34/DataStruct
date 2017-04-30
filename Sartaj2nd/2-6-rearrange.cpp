/*************************************************************************
    > File Name: 2-6-rearrange.cpp
    > Author: Feng
    > Created Time: 2017年04月30日 星期日 10时04分36秒
    > Content: 按名次排序（计数排序，名次是比它小的元素个数和左边与它相等的元素个数的和）
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

template<typename T>
void rearrange(T arr[], int n, int ret[])
{
	T* tmp = new T[n];
	for (int i = 0; i < n; ++i)
	{
		tmp[ret[i]] = arr[i];
	}

	for(int i = 0; i < n; ++i)
	{
		arr[i] = tmp[i];
	}
	delete[] tmp;
}

int main()
{
	int arr[5] = {2, 1, 2, 6, 5};
	int ret[5] = {0};
	rank_f<int>(arr, 5, ret);
	rearrange<int>(arr, 5, ret);
	for (int val : arr)
	{
		cout << val << " ";
	}

	return 0;
}
