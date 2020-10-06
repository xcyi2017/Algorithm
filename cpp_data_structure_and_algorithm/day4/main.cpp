<<<<<<< HEAD
#include "utils.h"
#include "Student.h"

//int main() {
//    int n = 100000;
//    int *a = sortTestHelper::generateRandomArray(n, 0, n);
//    Sort::selectionSort(a, n);
//    sortTestHelper::printArray(a, n);
//    delete[] a;
//    return 0;
//}

//int main() {
//    Student d[4] = {{"A",12},{"B", 9},{"C", 100},{"D", 45}};
//    Sort::selectionSort(d, 4);
//    sortTestHelper::printArray(d, 4);
//    return 0;
//}

int main() {
    int n = 50000;
    int *a1 = sortTestHelper::generateRandomArray(n, 0, n);
    int *a2 = sortTestHelper::copyIntarray(a1, n);
    sortTestHelper::testSort("归并排序", Sort::mergeSort, a1, n);
    std::cout << "归并排序是否排序成功：" << sortTestHelper::isSorted(a1, n) << std::endl;
    sortTestHelper::testSort("选择排序", Sort::selectionSort, a2, n);
    std::cout << "选择排序是否排序成功：" << sortTestHelper::isSorted(a2, n) << std::endl;
    delete[] a1;
    delete [] a2;
    return 0;
}

=======
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
>>>>>>> a04c13b... day4练习--选择排序与归并排序
