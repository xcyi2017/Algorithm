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
            } else if (temp[i - left] < temp[j - left]) {
                arr[k] = temp[i - left];
                ++i;
            } else if (temp[i - left] >= temp[j - left]) {
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


    // 对arr[l,r]范围内的数据进行插入排序
    template<class T>
    void insertionSort_r(T arr[], int l, int r) {
        for (int i = l + 1; i <= r; ++i) {
            T temp = arr[i];
            for (int j = i; j > l; --j) {
                if (arr[j - 1] > temp)
                    arr[j] = arr[j - 1];
                else {
                    arr[j] = temp;
                    break;
                }
            }
        }
    }

    // 改进归并排序
    template<typename T>
    void _mergeSort_im(T arr[], int left, int right) {
//        if (left >= right) return;
        if (right - left <= 15) // 一处优化，对小数祖进行插入排序
        {
            insertionSort_r(arr, left, right);
            return;
        }
        int mid = left + (right - left) / 2;
        _mergeSort(arr, left, mid);
        _mergeSort(arr, mid + 1, right);
        if (arr[mid] > arr[mid + 1]) // 一处优化，当arr[mid] < arr[mid+1]说明已经有序了
            _merge(arr, left, mid, right);
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

    // 对快速排序进行优化2，在partition过程随机选择参考点
    template<typename T>
    int _partition_im(T arr[], int left, int right) {
        std::swap(arr[left], arr[std::rand() % (right - left + 1) + left]); //随机选取两个元素先交换
        int i = left;
        for (int k = left + 1; k <= right; ++k)
            if (arr[k] < arr[left])
                std::swap(arr[k], arr[++i]);
        std::swap(arr[i], arr[left]);
        return i;
    }


    // 合并快排的两处优化
    // 对快速排序进行优化
    template<typename T>
    void _quickSort_im(T arr[], int l, int r) {
        if (r - l <= 15) // 优化1
        {
            insertionSort_r(arr, l, r); // 对小数祖进行插入排序
            return;
        }
        // 递归数不平衡，（近乎有序的数组）退化成O(n^2)级别
        int mid = _partition_im(arr, l, r); // 优化2
        _quickSort_im(arr, l, mid);
        _quickSort_im(arr, mid + 1, r);
    }

    template<typename T>
    void quickSort_im(T arr[], int n) {
        srand((unsigned int) time(nullptr));
        _quickSort_im(arr, 0, n - 1);
    }
    // 以上的快速排序依然存在问题，就是当数组中存在大量的重复元素时，partition定位的点没有向前 向后平移，从而避免重复的操作

    // 重新设计partition
    template<typename T>
    int _partition_n(T arr[], int l, int r) {
        std::swap(arr[l], arr[std::rand() % (r - l + 1) + l]);
        T e = arr[l];
        // arr[l+1...i) <= e 和 arr(j...r] >= e
        int i = l + 1, j = r;
        while (true) {
            while (i <= r && arr[i] < e) ++i;
            while (j >= l + 1 && arr[j] > e) --j;
            if (i > j) break;
            std::swap(arr[i], arr[j]);
            ++i;
            j--;
        }
        std::swap(arr[l], arr[j]);
        return j;
    }

    template<typename T>
    void _quickSort_n(T arr[], int l, int r) {
        if (r - l <= 15) // 优化1
        {
            insertionSort_r(arr, l, r); // 对小数祖进行插入排序
            return;
        }
        // 递归数不平衡，（近乎有序的数组）退化成O(n^2)级别
        int mid = _partition_n(arr, l, r); // 优化2
        _quickSort_n(arr, l, mid);
        _quickSort_n(arr, mid + 1, r);
    }

    template<typename T>
    void quickSort_n(T arr[], int n) {
        srand((unsigned int) time(nullptr));
        _quickSort_n(arr, 0, n - 1);
    }

    // 三路快排优化
    // 三路快排处理arr[l...r]
    // 将arr分成 < v; == v; > v三部分
    // 之后将 < e; > e继续进行三路快速排序
    template<typename T>
    void _quickSort_3w(T arr[], int l, int r) {
        if (r - l <= 15) // 优化1
        {
            insertionSort_r(arr, l, r); // 对小数祖进行插入排序
            return;
        }
        // 递归数不平衡，（近乎有序的数组）退化成O(n^2)级别
        // 进行partition操作

        std::swap(arr[l], arr[std::rand() % (r - l + 1) + l]);
        T v = arr[l];
        int lt = l; // arr[l+1...lt] < v
        int gt = r + 1; // arr[gt...r] > v
        int i = l + 1; // arr[lt+1...i) == v
        while (i < gt) {
            if (arr[i] < v) {
                std::swap(arr[i], arr[lt + 1]);
                ++i;
                ++lt;
            } else if (arr[i] > v) {
                std::swap(arr[i], arr[gt - 1]);
                --gt;
            } else {
                ++i;
            }
        }
        std::swap(arr[l], arr[lt]);
        _quickSort_3w(arr, l, lt - 1);
        _quickSort_3w(arr, gt, r);
    }

    template<typename T>
    void quickSort_3w(T arr[], int n) {
        srand((unsigned int) time(nullptr));
        _quickSort_3w(arr, 0, n - 1);
    }


    // 归并排序可以求解数组的逆序对的个数
    // 快排可以实现第n大的数据
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
