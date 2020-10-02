#include "utils.h"

int main() {
    int n = 10000000;
    int * arr1 = sortTestHelper::generateRandomArray(n, 0, n);
    int * arr2 = sortTestHelper::copyIntarray(arr1, n);
    int * arr3 = sortTestHelper::copyIntarray(arr1, n);
    sortTestHelper::testSort("自顶向下的归并排序：", Sort::mergeSort, arr1, n);
    sortTestHelper::testSort("自底向上的归并排序：", Sort::mergeSortBU, arr2, n);
    sortTestHelper::testSort("快速排序：", Sort::quickSort, arr3, n);
    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    return 0;
}
