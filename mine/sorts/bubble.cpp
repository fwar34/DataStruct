/*************************************************************************
    > File Name: bubble.cpp
    > Author: Feng
    > Created Time: Wednesday, December 05, 2018 PM04:53:12 CST
    > Content: 
 ************************************************************************/

#include <iostream>

using namespace std;

void bubble(int32_t array[], uint32_t array_len)
{
    for (uint32_t i = 0; i < array_len - 1; ++i) {
        for (uint32_t j = 0; j < array_len - 1 - i; ++j) {
            if (array[j] > array[j + 1]) {
                int32_t tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}

int main()
{
    int32_t array[11] = {105, -5, -89, 1, 9, 100, 3, -8, 99, 1, 89};
    bubble(array, 11);
    for (uint32_t i = 0; i < 11; ++i) {
        cout << array[i] << " "; 
    }
    cout << endl;

    return 0;
}
