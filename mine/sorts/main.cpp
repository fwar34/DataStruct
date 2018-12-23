/*************************************************************************
    > File Name: main.cpp
    > Author: Feng
    > Created Time: 2018/12/23 13:10:36
    > Content: 
 ************************************************************************/

#include <iostream>
#include "heap.h"

using namespace std;

int main()
{
    int32_t arr[10] = {-100, 3, 88, 67, -8, 0, 99, 299, 9, -111};
    MaxHeap<int32_t> heap(20);
    heap.BuildHeap(arr, 10);
    heap.Dump();

    return 0;
}
