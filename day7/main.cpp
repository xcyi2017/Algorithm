#include "utils.h"
#include "set"

//int main() {
//    int n = 50000;
//    int *arr1 = sortTestHelper::generateNearlyOrderArray(n, 1);
//    int *arr2 = sortTestHelper::copyIntarray(arr1, n);
//    int *arr3 = sortTestHelper::copyIntarray(arr1, n);
//    int *arr4 = sortTestHelper::copyIntarray(arr1, n);
//    int *arr5 = sortTestHelper::copyIntarray(arr1, n);
//
//    sortTestHelper::testSort("原生快速排序：", Sort::quickSort, arr1, n);
//    sortTestHelper::testSort("优化后的快速排序：", Sort::quickSort_im, arr2, n);
//    sortTestHelper::testSort("归并排序：", Sort::mergeSort, arr3, n);
//    sortTestHelper::testSort("快速排序在优化：", Sort::quickSort_n, arr4, n);
//    sortTestHelper::testSort("三路快排：", Sort::quickSort_3w, arr5, n);
//
//    delete[] arr1;
//    delete[] arr2;
//    delete[] arr3;
//    delete[] arr4;
//    return 0;
//}


// 实现求解逆序数对
// 关键在于merge的过程中判断左右的大小，如果左端的元素大于右端的元素，逆序数对数字累加一次

template<typename T>
void count(T arr[], int l, int mid, int r, size_t &result) {
    T *temp = new T[r - l + 1];
    for (int i = l; i <= r; ++i) temp[i - l] = arr[i];
    int i = l, j = mid + 1;
    for (int k = l; k <= r; ++k) {
        if (i > mid) {
            arr[k] = temp[j - l];
            ++j;
        } else if (j > r) {
            arr[k] = temp[i - l];
            ++i;
        } else if (temp[i - l] <= temp[j - l]) {
            arr[k] = temp[i - l];
            ++i;
        } else if (temp[i - l] > temp[j - l]) {
            // 此时, 因为右半部分k所指的元素小
            // 这个元素和左半部分的所有未处理的元素都构成了逆序数对
            // 左半部分此时未处理的元素个数为 mid - j + 1
            arr[k] = temp[j - l];
            ++j;
            result += mid - i + 1;
        }
    }

    delete[] temp;
}

template<typename T>
void countReverseOrder(T arr[], int l, int r, size_t &result) {
    if (l < r) {
        int mid = l + (r - l) / 2;
        countReverseOrder(arr, l, mid, result);
        countReverseOrder(arr, mid + 1, r, result);
        count(arr, l, mid, r, result);
    }
}

// 利用快速排序的思想实现求第k大的元素
// 三路快排partition思想
//template<typename T>
//T __findKNumber(T arr[], int l, int r, int k) {
//    if (l == r) return arr[l];
//    // 三路快排partition
//    T v = arr[l];
//    int lt = l, gt = r + 1;
//    int i = l + 1;
//    while (i < gt) {
//        if (arr[i] < v) {
//            std::swap(arr[i], arr[lt + 1]);
//            ++lt;
//            ++i;
//        } else if (arr[i] > v) {
//            std::swap(arr[i], arr[gt - 1]); // 交换过来到i下标的元素也不一定<=v，所以不对i进行操作
//            --gt;
//        } else {
//            ++i;
//        }
//        std::swap(arr[l], arr[lt]);
//    }
//    if ( k == lt) return arr[lt]; // 说明元素在中间部分(==v)
//    else if (lt > k)  // 说明想要查找的元素在左半部分(<v)
//        return __findKNumber(arr, l, lt-1, k);
//    else // 说明要查找的部分在右半部分(>v)
//        return __findKNumber(arr, gt, r, gt+k-lt-1);
//}
// 以上思路没解决

// partition 过程, 和快排的partition一样
// 思考: 双路快排和三路快排的思想能不能用在selection算法中? :)
template <typename T>
int __partition( T arr[], int l, int r ){

    int p = std::rand()%(r-l+1) + l;
    std::swap( arr[l] , arr[p] );

    int j = l; //[l+1...j] < p ; [lt+1..i) > p
    for( int i = l + 1 ; i <= r ; i ++ )
        if( arr[i] < arr[l] )
            std::swap(arr[i], arr[++j]);

    std::swap(arr[l], arr[j]);

    return j;
}

template<typename T>
T __findKNumber(T arr[], int l, int r, int k) { // 普通思路
    if (l == r) return arr[l];
    int i = __partition(arr, l, r);

    if (i == k) return arr[i+1];
    else if (i > k)
        return __findKNumber(arr, l, i - 1, k);
    else
        return __findKNumber(arr, i + 1, r, k);
}

template<typename T>
T findKNumber(T arr[], int n, int k) {
    std::srand((unsigned int) time(nullptr));
    return __findKNumber(arr, 0, n - 1, k - 1);
}


//int main() {
//    int n = 4;
//    size_t result = 0;
//    int *arr = sortTestHelper::generateRandomArray(n, 0, n);
//    sortTestHelper::printArray(arr, n);
//    countReverseOrder(arr, 0, n - 1, result);
//    sortTestHelper::printArray(arr, n);
//    std::cout << "result = " << result << std::endl;
//    delete[] arr;
//    return 0;
//}

int main() {
    int n = 100;
    int k = 3;
    int *arr = sortTestHelper::generateRandomArray(n, 0, n);
    sortTestHelper::printArray(arr, n);
    int result = findKNumber(arr, n, k);
    Sort::mergeSort(arr, n);
    sortTestHelper::printArray(arr, n);
    std::cout << "result = " << result << std::endl;
    std::set<int> s;
    for (int i = 0; i < n; ++i) {
        s.insert(arr[i]);
        if (s.size() == k) break;
    }
    int actual;
    for (int i : s)
        actual = i;
    std::cout << "actual = " << actual << std::endl;
    delete[] arr;
    return 0;
}