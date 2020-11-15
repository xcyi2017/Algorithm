#include <stdio.h>
#include <stdlib.h>


char* RemoveKDigits(char* num, int k);

int main(int argc, char* argv[]) {   
    
    int k = atoi(argv[2]);
    printf("待操作数:%s, ", argv[1]);
    char *result = RemoveKDigits(argv[1], k);
    printf("去除%d位数字得到的最小数字是%s\n", k, result);
    return 0;
}

char* RemoveKDigits(char* num, int k) {
    if (*num == '\0') {
        return num;
    }
    char* pre = num, *cur = num + 1;
    while ( k-- ) {
        int flag = 1;
        while (*cur) {
            if (*cur < *pre) {
                while (*pre) *pre++ = *cur++;
                flag = 0;
                break;
            }
            pre++;
            cur++;
        }
        if (flag) {
            flag = 1;
           *pre = '\0';
        }
        pre = num;
        cur = num + 1;
    }
    while (*num == '0') { num++; };
    return *num ? num : "0";
}