//
// Created by xcy on 2020/9/30.
//

#ifndef DAY4_UTILS_H
#define DAY4_UTILS_H

<<<<<<< HEAD
#include <algorithm>
#include <iostream>
#include <ctime>
#include <cassert>
#include <string>
namespace Sort {
    // selection sort
    template<class T>
    void selectionSort(T arr[], int n) {
        for (int i = 0; i < n; ++i) {
            //查找[0,n)区间最小值
            int minIndex = i;
            for (int j = i + 1; j < n; ++j) {
                if (arr[j] < arr[minIndex])
                    minIndex = j;
            }
            std::swap(arr[i], arr[minIndex]);
        }
    }



    //  将arr [left,mid] 和 [mid+1, right] 两部分进行归并
    template<typename T>
    void _merge(T arr[], int left, int mid, int right) {
        T *temp = new T[right - left + 1];
        for (int i = left; i <= right; ++i)
            temp[i - left] = arr[i];
        int i = left, j = mid + 1;
        for (int k = left; k <= right; ++k) {
            if (i > mid) {
                arr[k] = temp[j - left];
                ++j;
            } else if (j > right) {
                arr[k] = temp[i - left];
                ++i;
            } else if (j > right || temp[i - left] < temp[j - left]) {
                arr[k] = temp[i - left];
                ++i;
            } else if (i > mid || temp[i - left] >= temp[j - left]) {
                arr[k] = temp[j - left];
                ++j;
            }
        }

        delete[] temp;
    }

    // 使用递归递归排序对【left, right】之间的元素进行排序
    template<typename T>
    void _mergeSort(T arr[], int left, int right) {
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        _mergeSort(arr, left, mid);
        _mergeSort(arr, mid + 1, right);
        _merge(arr, left, mid, right);
    }

    template<typename T>
    void mergeSort(T arr[], int n) {
        _mergeSort(arr, 0, n - 1);
    }
}


namespace sortTestHelper {

    int *generateRandomArray(int n, int rangeL, int rangeR);
    //   生成一个随机数组
    // 首先生成一个完全有序的数组，之后对数组进行随机的swapTimes次交换
    int *generateNearlyOrderArray(int n, int swapTimes);
    //  拷贝一个数组到一个新数组中区
    int* copyIntarray(const int arr[], int n);
    // 判断数组是否有序
    bool isSorted(const int arr[], int n);
    // 测试排序算法的效率
    template <typename T>
    void testSort(const std::string &sortName, void(*sort)(T[], int), T arr[], int n)
    {
        std::clock_t startTime = std::clock();
        sort(arr, n);
        std::clock_t endTime = std::clock();
        std::cout << sortName << ":" << static_cast<double>((endTime-startTime)/CLOCKS_PER_SEC) << "s" << std::endl;
    }

    template<class T>
    void printArray(const T arr[], int n) {
        for (int i = 0; i < n; ++i) std::cout << arr[i] << " ";
        std::cout << std::endl;
    }

}

<<<<<<< HEAD
=======
// >>>>>>> day4练习--选择排序与归并排序
>>>>>>> 982b8e7... day4练习--选择排序与归并排序
=======
>>>>>>> a04c13b... day4练习--选择排序与归并排序
#endif //DAY4_UTILS_H
