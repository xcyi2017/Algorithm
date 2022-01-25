#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *addBinary(char *a, char *b)
{

    int la = strlen(a), lb = strlen(b);
    if (la < lb)
        return addBinary(b, a);
    int tmp = la;
    int carry = 0;

    while (lb > 0)
    {

        if (a[la - 1] - '0' + b[lb - 1] - '0' + carry < 2)
        {
            a[la - 1] = a[la - 1] - '0' + b[lb - 1] + carry;
            carry = 0;
        }
        else
        {
            a[la - 1] = a[la - 1] - '0' + b[lb - 1] + carry - 2;
            carry = 1;
        }
        lb--;
        la--;
    }
    while (la > 0)
    {
        if (a[la - 1] - '0' + carry < 2)
        {
            a[la - 1] = a[la - 1] + carry;
            carry = 0;
        }
        else
        {
            a[la - 1] = a[la - 1] + carry - 2;
            carry = 1;
        }
        la--;
    }

    if (carry == 1)
    {   
        char *src = (char*)malloc(tmp+2);
        *src = carry+'0';
        *(src+1) = '\0';
        strcat(src, a);
        return src;
    }

    return a;
}

int main(int argc, char *argv[])
{

    printf("\"%s\" + \"%s\" = ", argv[1], argv[2]);
    printf("\"%s\"\n", addBinary(argv[1], argv[2]));

    return 0;
}