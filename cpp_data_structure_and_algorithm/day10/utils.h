//
// Created by xcy on 2020/10/6.
//

#ifndef DAY10_UTILS_H
#define DAY10_UTILS_H

#include <ctime>
#include <iostream>

// 实现插入排序
template<typename T>
void insertionSort(T arr[], int l, int r) {
    for (int i = l + 1; i <= r; ++i) {
        T v = arr[i];
        int j;
        for (j = i; j > l; --j) {
            if (arr[j - 1] > v) {
                arr[j] = arr[j - 1];
            } else {
                break;
            }
        }
        arr[j] = v;
    }
}

// 实现quicksort
template<typename T>
void _quickSort(T arr[], int l, int r) {
    if (r - l <= 15) {
        insertionSort(arr, l, r);
        return;
    }
    // partition操作
    int lt = l, gt = r + 1;
    int i = l + 1;
    std::swap(arr[l], arr[std::rand() % (r - l + 1) + l]);
    T v = arr[l];
    while (i < gt) {
        if (arr[i] < v) {
            std::swap(arr[i], arr[lt + 1]);
            ++lt;
            ++i;
        } else if (arr[i] > v) {
            std::swap(arr[i], arr[gt - 1]);
            --gt;
        } else {
            ++i;
        }
    }
    std::swap(arr[l], arr[lt]);

    _quickSort(arr, l, lt - 1);
    _quickSort(arr, gt, r);
}

template<typename T>
void quickSort(T arr[], int n) {
    std::srand((unsigned int) time(nullptr));
    _quickSort(arr, 0, n - 1);
}

template<typename T>
bool isSorted(const T arr[], int n) {
    for (int i = 0; i < n - 1; ++i)
        if (arr[i] > arr[i + 1])
            return false;
    return true;
}

template<typename T>
bool printArray(const T arr[], int n) {
    for (int i = 0; i < n; ++i) std::cout << arr[i] << " ";
    std::cout << std::endl;
}

#endif //DAY10_UTILS_H
