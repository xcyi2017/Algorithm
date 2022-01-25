#include <stdio.h>
#include <stdlib.h>

int numberOfMathches(int n)
{
    int count = 0;
    while (n != 1)
    {
        count += n / 2;
        if (n % 2 == 1)
            n = n / 2 + 1;
        else
            n /= 2;
    }
    return count;
}

// 直接 return n-1；

int main(int argc, char *argv[])
{

    printf("队伍数：%s, 总配对数：%d\n", argv[1], numberOfMathches(atoi(argv[1])));
    return 0;
}