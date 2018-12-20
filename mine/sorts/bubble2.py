#!/usr/bin/env python3
#-*- coding: utf-8 -*-
 
# File Name: bubble2.py
# Author: Feng
# Created Time: Thursday, December 20, 2018 PM07:39:34 CST
# Content: worst case perfomance O(n^2)

def bubble(array):
    arr_len = len(array)
    change = False
    for i in range(arr_len - 1 - 1):
        change = False
        for j in range(arr_len - i - 1):
            if array[j] > array[j + 1]:
                array[j], array[j + 1] = array[j + 1], array[j]
                change = True
        if change == False:
            break
    return array


if __name__ == '__main__':
    test_array = [100, -2, -5, 1, 200, 5, 3, 201]
    print(bubble(test_array))
