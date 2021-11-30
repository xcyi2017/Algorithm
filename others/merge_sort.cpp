#include <iostream>
// 输入：整数数组A[]，下标p,q,r,A[p]~A[q]及A[q+1]~A[r]已按递增顺序排序
// 输出：按照递增顺序排序的子数组

void merge(int A[], int p, int q, int r)
{
    int *bp = new int[r-p+1]; /* 分配缓冲区，存放被排序的元素 */
    int i, j, k;  
    i = p;
    j = q + 1;
    k = 0;
    while (i <= q && j <= r)
    {
        if (A[i] <= A[j])
        {
            bp[k++] = A[i++];
        } else {
            bp[k++] = A[j++];
        }
    }
    if (i == q+1)
    {
        for (;j<=r;)
        {
            bp[k++] = A[j++];
        }

    } else  {
        for (;i<=q;)
        {
            bp[k++] = A[i++];
        }
    }
    k = 0;
    for (i = p; i <= r; i++)
    {
        A[i++] = bp[k++];
    }
    delete bp;
}


template<class Type>
void merge_sort(Type A[], int n) 
{
    int i, s, t = 1;
    while (t < n)
    {
        s = t;
        t = 2 * s;
        i = 0; 
        while (i + t < n)
        {
            merge_sort(A, i, i+s-1, i+t-1);
            i += t;
        }
        if (i+s < n) 
        {
            merge(A, i, i+s-1, n-1);
        }
    }
}

int main()
{

    int arr[] = {4,1,2,4,5,6,7,1,3,5};
    merge_sort(arr, sizeof(arr)/sizeof(int));
    for (int it: arr)
        std::cout << it << " ";
    std::cout << std::endl;
    return 0;
}