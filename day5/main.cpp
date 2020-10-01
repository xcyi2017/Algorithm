#include "utils.h"

int main() {
    int n = 100000;
    int *a1 = sortTestHelper::generateNearlyOrderArray(n, 100);
    int *a2 = sortTestHelper::copyIntarray(a1, n);
    int *a3 = sortTestHelper::copyIntarray(a1, n);
    int *a4 = sortTestHelper::copyIntarray(a1, n);
    int *a5 = sortTestHelper::copyIntarray(a1, n);
    int *a6 = sortTestHelper::copyIntarray(a1, n);
    sortTestHelper::testSort("插入排序：", Sort::insertionSort, a1, n);
    sortTestHelper::testSort("改进插入排序：", Sort::insertionSort_im, a3, n);
    sortTestHelper::testSort("选择排序：", Sort::selectionSort, a2, n);
    sortTestHelper::testSort("冒泡排序：", Sort::bubbleSort, a4, n);
    sortTestHelper::testSort("改进冒泡排序：", Sort::bubbleSort_im, a5, n);
    sortTestHelper::testSort("希尔排序：", Sort::shellSort, a5, n);
    delete [] a1;
    delete [] a2;
    delete [] a3;
    delete [] a4;
    delete [] a5;
    delete [] a6;
    return 0;
}
