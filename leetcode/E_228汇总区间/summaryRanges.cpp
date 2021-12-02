#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (nums.empty()) return ans;
        int size = nums.size();
        int begin = 0, end = 0;

        while (end < size) {
            begin = end;
            end++;
            while ((end < size) && (nums[end-1] + 1 ==  nums[end])) {
                end++;
            }
            if (end - begin == 1) 
                ans.push_back(to_string(nums[begin]));
            else
                ans.push_back(to_string(nums[begin]) + "->" + to_string(nums[end-1]));
            begin = end - 1;
        }
        return ans;
    }
};

int main(int argc, char* argv[]) {
    vector<int> li;
    cout <<  "输入的数列是:\n";
    for (int i = 1; i < argc; ++i) {
        cout << argv[i] << " ";
        li.push_back(atoi(argv[i]));
    }
    cout << endl;
    Solution sol;
    vector<string> res = sol.summaryRanges(li);
    cout << "输出数列是:\n";
    for (string it : res) {
        cout << it << endl;
    }
    return 0;
}
