#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countVowelPermutation(int n){
    long long mod = 1e9 + 7;
    long dp[5] = {1,1,1,1,1};
    long ndp[5];
    int i = 0;

    for (i = 2; i <= n; i++) {
        ndp[0] = (dp[1] + dp[2] + dp[4]) % mod;
        ndp[1] = (dp[0] + dp[2]) % mod;
        ndp[2] = (dp[1] + dp[3]) % mod;
        ndp[3] = dp[2] % mod;
        ndp[4] = (dp[2] + dp[3]) % mod;
        memcpy(dp, ndp, sizeof(ndp));
    }

    for (i = 0; i < 4; i++)
        dp[i+1] = (dp[i+1] + dp[i]) % mod;


    return dp[4];
}

int main(int argc , char *argv[])
{
    int n = atoi(argv[1]);
    printf("输入：n = %d\n输出：%d\n", n, countVowelPermutation(n));

    return 0;
}

