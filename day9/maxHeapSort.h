//
// Created by xcy on 2020/10/5.
//

#ifndef DAY9_MAXHEAPSORT_H
#define DAY9_MAXHEAPSORT_H

#include "maxHeap.h"

template<typename T>
void heapSort1(T arr[], int n) {
    MaxHeap<T> maxheap = MaxHeap<T>(n);
    for (int i = 0; i < n; ++i)
        maxheap.insert(arr[i]);
    for (int i = n - 1; i >= 0; --i)
        arr[i] = maxheap.extractMax();
}

template<typename T>
void heapSort2(T arr[], int n) {
    MaxHeap<T> maxheap = MaxHeap<T>(arr, n);
    for (int i = n - 1; i >= 0; --i)
        arr[i] = maxheap.extractMax();
}

// 原地堆排序
template<typename T>
void _shiftDown(T arr[], int n, int k) {
    while (2 * k + 1 < n) {
        int j = 2 * k + 1;// j为与父节点待交换的节点
        if (j + 1 < n && arr[j + 1] > arr[j]) j += 1;
        if (arr[k] >= arr[j]) break;//如果头节点大于等于叶子节点，跳出循环
        std::swap(arr[k], arr[j]);
        k = j;
    }
}

template<typename T>
void heapSort(T arr[], int n) {
    //heapify
    for (int i = (n - 1) / 2; i >= 0; --i)
        _shiftDown(arr, n, i);
    for (int i = n - 1; i > 0; --i) {
        std::swap(arr[0], arr[i]);
        _shiftDown(arr, i, 0);
    }

}

#endif //DAY9_MAXHEAPSORT_H
