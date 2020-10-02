//
// Created by xcy on 2020/9/30.
//

#ifndef DAY4_UTILS_H
#define DAY4_UTILS_H


#include <algorithm>
#include <iostream>
#include <ctime>
#include <cassert>
#include <string>

namespace Sort {

    // 冒泡排序
    template<typename T>
    void bubbleSort(T arr[], int n) {
        for (int i = 0; i < n - 1; ++i) {
            // 扫n-1遍
            for (int j = 0; j < n - 1 - i; ++j) {
                if (arr[j] > arr[j + 1]) std::swap(arr[j], arr[j + 1]);
            }
        }
    }

    // 改进冒泡排序
    template<typename T>
    void bubbleSort_im(T arr[], int n) {
        for (int i = 0; i < n - 1; ++i) {
            // 扫n-1遍
            bool flag = true;
            for (int j = 0; j < n - 1 - i; ++j) {
                if (arr[j] > arr[j + 1]) {
                    std::swap(arr[j], arr[j + 1]);
                    flag = false;
                }
            }
            if (flag) break;
        }
    }

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

    // 插入排序
    template<typename T>
    void insertionSort(T arr[], int n) {
        for (int i = 1; i < n; ++i) {
            // 从第一个元素开始
            for (int j = i; j > 0 && arr[j] < arr[j - 1]; --j) {
                std::swap(arr[j], arr[j - 1]);
            }
        }
    }

    //  希尔排序
    template<typename T>
    void shellSort(T arr[], int n) {
        for (int gap = n / 2; gap > 0; gap /= 2) { // 步长
            for (int i = gap; i < n; i += gap) { // 直接插入排序
                T temp = arr[i];
                for (int j = i; j > 0; j -= gap) {
                    if (arr[j] < arr[j - gap])
                        std::swap(arr[j], arr[j - gap]);
                    else {
                        arr[j] = temp;
                        break;
                    }
                }
            }
        }
    }

    // 改进版插入排序
    template<typename T>
    void insertionSort_im(T arr[], int n) {
        for (int i = 1; i < n; ++i) {
            T tmp = arr[i];
            for (int j = i; j > 0; --j) {
                if (arr[j - 1] > tmp) {
                    arr[j] = arr[j - 1];
                } else {
                    arr[j] = tmp;
                    break;
                }
            }
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

    // 改进归并排序
    template<typename T>
    void _mergeSort_im(T arr[], int left, int right) {
//        if (left >= right) return;
        if (right - left <= 15) // 一处优化，对小数祖进行插入排序
        {
            insertionSort_im(arr, left, right);
            return;
        }
        int mid = left + (right - left) / 2;
        _mergeSort(arr, left, mid);
        _mergeSort(arr, mid + 1, right);
        if (arr[mid] > arr[mid + 1]) // 一处优化，当arr[mid] < arr[mid+1]说明已经有序了
            _merge(arr, left, mid, right);
    }

    // 对arr[l,r]范围内的数据进行插入排序
    template<class T>
    void insertionSort_r(T arr[], int l, int r) {
        for (int i = l + 1; i <= r; ++i) {
            T temp = arr[i];
            for (int j = i; j > l; --j) {
                if (arr[j] < arr[j - 1])
                    arr[j] = arr[j - 1];
                else {
                    arr[j] = temp;
                    break;
                }
            }
        }
    }

    template<typename T>
    void mergeSort(T arr[], int n) {
        _mergeSort(arr, 0, n - 1);
    }

    // 实现自底向上的归并排序
    template<typename T>
    void mergeSortBU(T arr[], int n) { // 没有使用数组，直接通过索引，可以对链表进行排序
        // 对进行merge的元素个数
        for (int sz = 1; sz <= n; sz += sz) { // 第一层逐渐增加 size 的大小
            for (int i = 0; i + sz < n; i += sz + sz) { // 每一轮归并起始元素的位置，对2*sz的空间进行归并排序
                // 对arr[i...i+sz-1] 和 arr[i+sz....i+sz+sz-1] 进行归并
                // i + sz 保证 i + sz + sz - 1 有可能取到
                // min(i + sz + sz - 1, n - 1) 因为末尾有可能不足sz的大小，保证不越界
                _merge(arr, i, i + sz - 1, std::min(i + sz + sz - 1, n - 1));
            }
        }
    }


    // 实现快速排序，对arr[left,right]进行部分快速排序
    template<typename T>
    int _partition(T arr[], int left, int right) {
        int i = left;
        for (int k = left + 1; k <= right; ++k)
            if (arr[k] < arr[left])
                std::swap(arr[k], arr[++i]);
        std::swap(arr[i], arr[left]);
        return i;
    }

    template<typename T>
    void _quickSort(T arr[], int left, int right) {
        if (left < right) {
            int mid = _partition(arr, left, right);
            _quickSort(arr, left, mid);
            _quickSort(arr, mid + 1, right);
        }
    }

    template<typename T>
    void quickSort(T arr[], int n) {
        _quickSort(arr, 0, n - 1);
    }

}


namespace sortTestHelper {
    int *generateRandomArray(int n, int rangeL, int rangeR);

    // 生成一个随机数组
    // 首先生成一个完全有序的数组，之后对数组进行随机的swapTimes次交换
    int *generateNearlyOrderArray(int n, int swapTimes);

    //  拷贝一个数组到一个新数组中区
    int *copyIntarray(const int arr[], int n);

    // 判断数组是否有序
    bool isSorted(const int arr[], int n);

    // 测试排序算法的效率
    template<typename T>
    void testSort(const std::string &sortName, void(*sort)(T[], int), T arr[], int n) {
        std::clock_t startTime = std::clock();
        sort(arr, n);
        std::clock_t endTime = std::clock();
        assert(isSorted(arr, n));
        std::cout << sortName << ":" << (double) (endTime - startTime) / CLOCKS_PER_SEC << "s" << std::endl;
    }

    template<class T>
    void printArray(const T arr[], int n) {
        for (int i = 0; i < n; ++i) std::cout << arr[i] << " ";
        std::cout << std::endl;
    }

}
#endif //DAY4_UTILS_H
