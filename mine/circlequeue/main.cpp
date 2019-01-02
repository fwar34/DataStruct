/*************************************************************************
    > File Name: main.cpp
    > Author: Feng
    > Created Time: 2019/1/2 14:51:59
    > Content: 
 ************************************************************************/

#include <iostream>
#include "arrayqueue.h"

using namespace std;

int main()
{
    ArrayQueue<int> queue(5);
    cout << queue.Empty() << endl;
    cout << queue.Full() << endl;

    queue.Push(3);
    cout << queue.Empty() << endl;
    cout << queue.Full() << endl;

    queue.Push(4);
    queue.Push(5);
    queue.Push(6);
    cout << queue.Empty() << endl;
    cout << queue.Full() << endl;
    cout << queue.Front() << endl;
    cout << queue.Back() << endl;

    queue.Pop();
    cout << queue.Front() << endl;
    queue.Pop();
    queue.Pop();
    queue.Pop();
    cout << queue.Empty() << endl;
    cout << queue.Full() << endl;

    return 0;
}
