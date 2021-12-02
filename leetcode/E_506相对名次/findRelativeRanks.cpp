#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;



class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int size = score.size();
        vector<string> answer(size, "");
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < size; ++i) {
            q.push(pair<int, int>{score[i], i});
        }
        vector<int> idx;
        while (!q.empty()) {
            idx.push_back(q.top().second);
            cout << q.top().first << " " << q.top().second << endl;
            q.pop();
        }
        for (int j = 0; j < size; ++j) {
            switch (j) {
            case 0: {
                        answer[idx[j]] = "Gold Medal";
                        break;
                    }
            case 1: {
                        answer[idx[j]] = "Silver Medal";
                        break;
                    }
            case 2: {
                        answer[idx[j]] = "Bronze Medal";
                        break;
                    }
            default: {
                      answer[idx[j]] = to_string(j + 1);
                      break;
                     } 
            }                
        }
        return answer;
    }
};


int main(int argc, char* argv[]) {
    vector<int> li;
    for (int i = 1; i < argc; ++i) {
        li.push_back(atoi(argv[i]));
    }
    Solution sol;
    vector<string> ans = sol.findRelativeRanks(li);
    for (auto it: ans) {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}
