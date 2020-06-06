#include <stdio.h>

void swap(int* a, int* b) 
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

int pick(int arr[], int left, int right)
{
    int x, k;
    x = left;
    for (k = left + 1; k < right; ++ k)
    {
        if (arr[k] < arr[left])
        {
            ++x;
            if (x != k)
                swap(arr + k, arr + x);
        }
    }
    swap(arr + x, arr + left);
    return x;
}


void quickSort(int* arr, int left, int right)
{
    if (left < right)
    {
        int mid = pick(arr, left, right);
        quickSort(arr, left, mid);
        quickSort(arr, mid, right);
    }
}


int main()
{
    int arr[] = { 10,9,8,7,6,5,4,3,2,1 };
    quickSort(arr, 0, sizeof(arr));
    for (int i = 0; i < sizeof(arr); ++ i) printf("%d ", arr[i]);
    return 0;
}
