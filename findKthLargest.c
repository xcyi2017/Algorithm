#include <stdio.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a  = *b;
    *b = tmp;
}

int partition(int *arr, int l, int r) {
    int i = l;
    for (int k = l + 1; k <= r; ++k)
        if (arr[k] < arr[l]) swap(&arr[k], &arr[++i]);
    swap(&arr[i], &arr[l]);
    return i;
}

int helper(int *arr, int l, int r, int k) {
    if (l == r) return arr[l];
    int p = partition(arr, l, r);
    if (p == k) return arr[p];
    else if (p > k) return helper(arr, l, p - 1, k);
    else return helper(arr, p + 1, r, k);
}


int findKthLargest(int* nums, int numsSize, int k){
        int target = numsSize - k + 1;
        return helper(nums, 0,  numsSize-1, target-1);
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8};
    int k = 2;
    int result = findKthLargest(arr, 8, k);
    printf("%d\n", result);
    return 0;
}

