#include <stdio.h>

void maxmin(int arr[], int *e_max, int *e_min, int l, int r);
extern int* generateRandomArray(int, int, int);
int main()
{
    int n = 100;
    int e_max, e_min;
    int *arr = generateRandomArray(n, 0, n);
    maxmin(arr, &e_max, &e_min, 0, n-1);
    printf("e_max=%d, e_min=%d\n", e_max, e_min);
    return 0;
}


void maxmin(int arr[], int *e_max, int *e_min, int l, int r) {
    if ( r-l <= 1 ) { 
        if (arr[r] > arr[l]) {
            *e_max = arr[r];
            *e_min = arr[l];
        } else {
            *e_max = arr[l];
            *e_min = arr[r];
        }
        
    } else {
        int mid = l + ( r - l ) / 2;
        int x1, x2, y1, y2;
        maxmin(arr, &x1, &x2, l, mid);
        maxmin(arr, &y1, &y2, mid + 1, r);
        *e_max = x1 > y1 ? x1 : y1;
        *e_min = x2 < y2 ? x2 : y2;
    }
}
