#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

void helper(int n, int* idx, char *res) 
{
    if (n == 0) return;
    helper(--n / 26, idx, res);
    res[(*idx)++] = n % 26 + 'A';
}

char *convertToTitle(int columnNumber)
{
    int i = 0;
    char *res = (char*)calloc(20, sizeof(char));
    helper(columnNumber, &i, res);
    res[i] = '\0';
    return res;
}

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    
    char *res = convertToTitle(n);
    printf("%d->%s\n", n, res);
    
    return 0;
}
