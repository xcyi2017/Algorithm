#include "maxHeap.h"
#include "maxHeapSort.h"
#include "utils.h"

int main() {
    int n = 10000000;
    std::cout << "无序度很高的数组排序性能测试" << std::endl;
    int *arr1 = sortTestHelper::generateRandomArray(n, 0, n);
    int *arr2 = sortTestHelper::copyIntarray(arr1, n);
    int *arr3 = sortTestHelper::copyIntarray(arr1, n);
    int *arr4 = sortTestHelper::copyIntarray(arr1, n);
    int *arr5 = sortTestHelper::copyIntarray(arr1, n);
    sortTestHelper::testSort("归并排序", Sort::mergeSort, arr1, n);
    sortTestHelper::testSort("快速排序", Sort::quickSort_3w, arr2, n);
    sortTestHelper::testSort("堆排序1", heapSort1, arr3, n);
    sortTestHelper::testSort("堆排序2", heapSort2, arr4, n);
    sortTestHelper::testSort("堆排序", heapSort, arr5, n);
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;

    std::cout << "****************************************************" << std::endl;
    std::cout << "大量重复数字测试" << std::endl;
    int *arr11 = sortTestHelper::generateRandomArray(n, 0, 100);
    int *arr22 = sortTestHelper::copyIntarray(arr11, n);
    int *arr33 = sortTestHelper::copyIntarray(arr11, n);
    int *arr44 = sortTestHelper::copyIntarray(arr11, n);
    int *arr55 = sortTestHelper::copyIntarray(arr11, n);

    sortTestHelper::testSort("归并排序", Sort::mergeSort, arr11, n);
    sortTestHelper::testSort("快速排序", Sort::quickSort_3w, arr22, n);
    sortTestHelper::testSort("堆排序1", heapSort1, arr33, n);
    sortTestHelper::testSort("堆排序2", heapSort2, arr44, n);
    sortTestHelper::testSort("堆排序", heapSort, arr55, n);

    delete[] arr11;
    delete[] arr22;
    delete[] arr33;
    delete[] arr44;
    delete[] arr55;

    std::cout << "****************************************************" << std::endl;
    std::cout << "接近有序数组测试" << std::endl;
    int *arr111 = sortTestHelper::generateNearlyOrderArray(n, 100);
    int *arr222 = sortTestHelper::copyIntarray(arr111, n);
    int *arr333 = sortTestHelper::copyIntarray(arr111, n);
    int *arr444 = sortTestHelper::copyIntarray(arr111, n);
    int *arr555 = sortTestHelper::copyIntarray(arr111, n);
    sortTestHelper::testSort("归并排序", Sort::mergeSort, arr111, n);
    sortTestHelper::testSort("快速排序", Sort::quickSort_3w, arr222, n);
    sortTestHelper::testSort("堆排序1", heapSort1, arr333, n);
    sortTestHelper::testSort("堆排序2", heapSort2, arr444, n);
    sortTestHelper::testSort("堆排序", heapSort, arr555, n);
    delete[] arr111;
    delete[] arr222;
    delete[] arr333;
    delete[] arr444;
    delete[] arr555;

    return 0;
}
