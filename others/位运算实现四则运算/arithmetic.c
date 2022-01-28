#include <stdio.h>


int add(int a, int b);
int substract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);

int main(int argc, char * argv[])
{
    int operator = 0;
    int a, b;
    do 
    {
        printf("--------------------------------------------\n");
        printf("|  四则运算位运算实现                      |\n");
        printf("--------------------------------------------\n");
        printf("|  1)加法运算               2)减法运算     |\n");
        printf("|  3)乘法运算               4)除法运算     |\n");
        printf("|  0)退出运算                              |\n");
        printf("--------------------------------------------\n");

        printf("输入要进行的操作:");
        scanf("%d", &operator);
        switch (operator)
        {
        case 1:
            printf("输入两个要相加的数:");
            scanf("%d %d", &a, &b);
            printf("结果为:%d\n", add(a, b));
            break;
        case 2:
            printf("输入两个要相减的数:");
            scanf("%d %d", &a, &b);
            printf("结果为:%d\n", substract(a, b));
            break;
        case 3:
            printf("输入两个要相乘的数:");
            scanf("%d %d", &a, &b);
            printf("结果为:%d\n", multiply(a, b));
            break;
        case 4:
            printf("输入两个要相除的数:");
            scanf("%d %d", &a, &b);
            printf("结果为:%d\n", divide(a, b));
            break;

        }
    }   while (operator);
    return 0;
}

int add(int a, int b) 
{
    if (b == 0) return a;
    int sum;
    while (b != 0) 
    {
        sum = a ^ b;
        b = (a & b) << 1;
        a = sum;
    }
    return a;
}



int substract(int a, int b)
{
    //转化为加法，将a-b看成a+(-b)
    //求b的补码
    int substractor = add(~b, 1); // 取反加一
    return add(a, substractor);
}


int multiply(int a, int b) 
{
    // 乘法转化为加法和减法
    
    // 求a和b的绝对值
    int t_a = a, t_b = b;
    if (a < 0) a = add(~a, 1);
    if (b < 0) b = add(~b, 1);
    
    int ans = 0;
    while (b != 0)
    {
        ans = add(ans, a);
        b   = add(b,-1);
    }

    // 判断a和b相乘的符号 若a、b异号a^b < 0 
    if ((t_a ^ t_b) < 0) // 注意优先级问题 t_a ^ t_b < 0 /error 改成（t_a ^ t_b）< 0
    {
        ans = add(~ans, 1);
    }
    return ans;
}


int divide(int a, int b) 
{
    // 减法实现
    int t_a = (a < 0 ? add(~a, 1) : a);
    int t_b = (b < 0 ? add(~b, 1) : b);
    
    int count = 0;

    while (t_a > t_b) 
    {
        t_a = substract(t_a, t_b);
        count++;
    }

    if ((a ^ b) < 0)
        return add(~count, 1);
    return count;
}
