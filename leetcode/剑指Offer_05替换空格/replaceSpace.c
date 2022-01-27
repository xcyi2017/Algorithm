#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* replaceSpace(char* s){
    int count_backspace = 0;
    char *tmp = s;
    while (*tmp != '\0')
    {
        if (*(tmp++) == ' ')
            count_backspace++;
    }
    char *src = (char *)malloc((strlen(s) + count_backspace * // 把 * 写成 % 卡了一晚上):
    2 + 1) * sizeof(char)); 
    char *dest = src;
    while (*s != '\0')
    {
        if (*s == ' ')
        {
            *(src++) = '\%';
            *(src++) = '2';
            *(src++) = '0';
            s++; 
        } 
        else {
          *(src++) = *(s++);  
        }

        
    }
    *src = '\0';
    return dest;
}

int main(int argc, char *argv[])
{
    printf("输入：%s\n", argv[1]);
   // printf("输出：%s\n", replaceSpace(argv[1]));
    char *res = replaceSpace("We are happy.");
    printf("输出：%s\n", res);
    free(res);
    return 0;
}