#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        // 1 9*1
        // 2 90*2
        // 3 900*3
        // 4 900*4
        
        // 确定是几位数
        int w = 1, co = 9;
        while (n > (long)w*co) {
            n -= w * co;
            w++;
            co *= 10;

        }

        // 查找是哪个数字
        int num = (int)pow(10, w-1) + (n - 1) / w;
        cout << num << endl;

        // 确定是这个数字的第几位
        int pos = (n - 1) % w;
        cout << pos << endl;

        int res = (num / (int)pow(10, w - pos - 1)) % 10;
        return res;
    };

};

int main(int argc, char* argv[]) {
    int n = atoi(argv[1]);
    Solution sol;
    int res = sol.findNthDigit(n);
    cout << "该数字是" << res << endl;
    return 0;
}
