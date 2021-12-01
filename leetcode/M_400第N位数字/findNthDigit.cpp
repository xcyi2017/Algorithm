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
        int w = 0, cur = 0;
        do {
            ++w;
            cur += static_cast<int>(pow(10, w-1)) * 9 * w;
            cout << static_cast<int>(pow(10, w-1)) * 9 * w << " ";

        } while( cur <= n );
        cout << endl;
        cout << cur << endl;

        // 查找是哪个数字
        int num = pow(10, w) - 1 - (cur - n) / w;
        cout << num << endl;

        // 确定是这个数字的第几位
        int pos = w - (cur - n) % w;
        cout << pos << endl;

        int res = 0;
        while (pos) {    
            res = num / pow(10, --w);
            num = num % (int)pow(10, pos);
            --pos;
        }
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
