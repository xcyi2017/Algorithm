#include <stdio.h>
#include <stdlib.h>

int tribonacci(int n)
{
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;
    int i = 0, j = 1, k = 1;
    int r = 3;
    int t1, t2;
    while (r++ <= n)
    {
        t1 = i;
        i = j;
        t2 = j;
        j = k;
        k = t1 + t2 + k;
    }
    return k;
    

}

int main(int argc, char *argv[])
{
    printf("输入：%s,输出：%d\n", argv[1], tribonacci(atoi(argv[1])));

    return 0;
}