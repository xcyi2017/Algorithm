#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void max_min(int arr[], int *e_max, int *e_min, int n);
int* generateRandomArray(int n, int L, int R);

int main()
{   
    int n = 100;
    int e_max, e_min;
    int *arr = generateRandomArray(n, 0, n);
    max_min(arr, &e_max, &e_min, n);
    printf("max=%d, min=%d\n", e_max, e_min);
    free(arr);
    arr = NULL;
    return 0;
}


void max_min(int arr[], int *e_max, int *e_min, int n) {
    int i;
    *e_max = arr[0];
    *e_min = arr[0];
    for (i = 1; i < n; ++ i) {
        if (arr[i] > *e_max) *e_max = arr[i];
        if (arr[i] < *e_min) *e_min = arr[i];
    }
}


int* generateRandomArray(int n, int L, int R) {
    int *arr = (int*)malloc( n*sizeof(n) ); 
    srand((unsigned int) time(NULL) );
    for (int i = 0; i < n; i ++) {
        arr[i] = rand()%(R-L+1) + L;
    }
    return arr;
}
