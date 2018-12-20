#!/usr/bin/env python3
#-*- coding: utf-8 -*-
 
# File Name: bubble.py
# Author: Feng
# Created Time: Sunday, December 02, 2018 PM09:26:22 CST
# Content: 

def bubble(array):
    length = len(array)
    for i in range(length - 1 - 1):
        for j in range(length - 1 - i):
            if array[j] > array[j + 1]:
                array[j], array[j + 1] = array[j + 1], array[j]
    return array

if __name__ == '__main__':
    test_array = [100, -2, -5, 1, 200, 5, 3, 201]
    print(bubble(test_array))

