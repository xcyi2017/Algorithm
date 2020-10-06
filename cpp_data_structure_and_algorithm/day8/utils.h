//
// Created by xcy on 2020/10/4.
//

#ifndef DAY8_UTILS_H
#define DAY8_UTILS_H

#include "maxHeap.h"

namespace Sort {
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
}

#endif //DAY8_UTILS_H
