#include <stdio.h>
#include <stdlib.h>

int findKthLargest_(int arr[], int n, int k);
void heapfiy(int arr[], int n);
void shiftUp(int arr[], int idx);
void shiftDown(int arr[], int idx, int n);
void swap(int *a, int *b);
extern int *generateRandomArray(int n, int L, int R); // 在 utils.c 文件中
int compr( const void *a, const void *b) {return *(int*)a - *(int*)b;}

int main(int argc, char** argv)
{
    int n = atoi(argv[1]);
    int *arr = generateRandomArray(n, 0, n);
    int k = atoi(argv[2]);
    int ret = findKthLargest_(arr, n-1, k);
    printf("第%d大的数为：%d\n", k, ret);
    qsort(arr, n, sizeof(int), compr);
    free(arr);
    arr = NULL;
    return 0;
}

int  findKthLargest_(int arr[], int n, int k) {
    int ret = 0;
    heapfiy(arr, n);
    for (int i = 0; i < k; ++ i) {
        ret = arr[0];
        swap(&arr[0], &arr[n]);
        shiftDown(arr, 0, n-1);
    }
    return ret;
}

void heapfiy(int arr[], int n) {
    // 找到最后一个不是叶子节点的节点
    int idx = (n-1) / 2;
    while (idx >= 0) {
        shiftUp(arr, idx);
        shiftDown(arr, idx, n);
        idx--;
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void shiftUp(int arr[], int idx) {
    while(idx > 0 && arr[(idx - 1) / 2] < arr[idx]) {
        swap(&arr[(idx-1)/2], &arr[idx]); 
        idx = (idx-1)/2;
    }
}

void shiftDown(int arr[], int idx, int n) {
    while( 2*idx+1 <= n) {
        int temp = 2*idx+1;
        if (2*idx+2 <= n && arr[2*idx+2] > arr[temp])
            temp++;
        if (arr[idx] >= arr[temp]) break;
        swap(&arr[idx], &arr[temp]);
        idx = temp;
    }
}


