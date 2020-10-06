//
// Created by xcy on 2020/10/6.
//

#ifndef DAY10_BINARYSEARCH_H
#define DAY10_BINARYSEARCH_H

#include "utils.h"
#include <iostream>

// 在数组中查找target，找到返回target对应于数组中的index
// 找不到返回-1

// 迭代实现
template<typename T>
int binarySearch(T arr[], int n, T target) {
    if (!isSorted(arr, n))
        quickSort(arr, n);
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] > target) r = mid - 1;
        else if (arr[mid] < target) l = mid + 1;
        else return mid;
    }
    return -1;
}

// 递归实现
template<typename T>
int _binarySearch_rec(T arr[], int l, int r, int target) {
    if (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] > target)
            return _binarySearch_rec(arr, l, mid - 1, target);
        else
            return _binarySearch_rec(arr, mid + 1, r, target);
    }
    return -1;

}

template<typename T>
int binarySearch_rec(T arr[], int n, int target) {
    return _binarySearch_rec(arr, 0, n - 1, target);
}

#endif //DAY10_BINARYSEARCH_H
