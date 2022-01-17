// 导致堆栈溢出 错误版本
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

char *helper(int columnNumber)  {

    if (columnNumber < 27)
    {
        char * res = (char*)malloc(8);
        *res = (char)('A'+columnNumber-1);  
        return res;
    }
    return strcat(helper((columnNumber-1)/26), helper((columnNumber-1)%26+1));
}

char *convertToTitle(int columnNumber)
{
    return helper(columnNumber);
}

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    
    char *res = convertToTitle(n);
    printf("%d->%s\n", n, res);
    
    return 0;
}
