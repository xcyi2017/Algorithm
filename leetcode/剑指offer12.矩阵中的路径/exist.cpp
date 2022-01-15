#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (dfs(board, word, i, j, 0)) return true;
        return false;    
    }

    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int idx) 
    {
        if (board[i][j] != word[idx] || i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return false;
        if (idx == word.size() - 1) return true;
        char temp = board[i][j];
        board[i][j] = '/';
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
        for (int t = 0; t < 4; t++)
        {
            int  m = i + dx[t], n = j + dy[t];
            if (dfs(board, word, m, n, idx+1)) return true;
        }
        board[i][j] = temp;
        return false;
    }

};


int main() 
{
    Solution sol;
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string  word = "ABCCED";
    bool result = sol.exist(board, word);
    cout << result << endl;
    return 0;
}
