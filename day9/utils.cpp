//
// Created by xcy on 2020/9/30.
//
#include "utils.h"

// 生成含有n个随机元素的数组，每个元素的范围为[rangeL, rangeR]
int *sortTestHelper::generateRandomArray(int n, int rangeL, int rangeR) {
    assert(rangeL <= rangeR);
    int *arr = new int[n];
    std::srand((unsigned int) time(nullptr));
    for (int i = 0; i < n; ++i) {
        arr[i] = std::rand() % (rangeR - rangeL + 1) + rangeL;
    }
    return arr;
}

int *sortTestHelper::generateNearlyOrderArray(int n, int swapTimes) {
    int *arr = new int[n];
    for (int i = 0; i < n; ++i) arr[i] = i;
    std::srand((unsigned int) time(nullptr));
    for (int i = 0; i < swapTimes; ++i) {
        int pos_x = std::rand() % n;
        int pos_y = std::rand() % n;
        std::swap(arr[pos_x], arr[pos_y]);
    }
    return arr;

}

int *sortTestHelper::copyIntarray(const int arr[], int n) {
    int *a = new int[n];
    std::copy(arr, arr + n, a);
    return a;
}

bool sortTestHelper::isSorted(const int *arr, int n) {
    for (int i = 0; i < n - 1; ++i)
        if (arr[i] > arr[i + 1])
            return false;
    return true;
}

