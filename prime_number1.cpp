/*************************************************************************
    > File Name: prime_number1.cpp
    > Author: Feng
    > Content: 求x以内的素数（质数）
	//算法：筛选法，从小到大筛去一个已知素数的所有倍数。依次删除可被2整除，3整除。。。。的数字，剩下的则为素数   
    > Created Time: Thu 23 Mar 2017 07:12:38 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

void isPrime(int x)
{
	bool isPrime = true;
	if (x <= 1)
	{
		cout << x << endl;
	}

	for (int i = 2; i < x; ++i)
	{
		isPrime = true;
		for (int j = 2; j < i; ++j)
		{
			if (i % j == 0)
			{
				isPrime = false;
				break;
			}
		}
		if (isPrime)
		{
			cout << i << endl;
		}
	}
}

int main()
{
	isPrime(10);
	return 0;
}

