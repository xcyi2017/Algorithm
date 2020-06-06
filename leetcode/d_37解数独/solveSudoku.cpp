#include <iostream>
#include <vector>

class Solution
{
    public:
        void solveSudoku(std::vector<std::vector<char>>& board)
        {
            std::vector<std::vector<char>> ret;
            helper(board, 1, 81);                   
        }

        void  helper(std::vector<std::vector<char>>& board, int i, int n)
        {
            if (i <= n)
            {
                // 转化为对于的盘坐标
                int row = (i - 1) / 9;
                int col = i -(row + 1) * 9 - 1;
                if (board[row][col] != '.') helper(board, i+1, n);
                else
                {
                    for (char item = '1'; item <= '9'; ++ item)
                    {
                        if (isOk(board, row, col, item))
                        {
                            board[row][col] = item;
                            helper(board, i + 1, n);
                        }
                    }
                    board[row][col] = '.';         
                }
            }
        }

        bool isOk(std::vector<std::vector<char>>& board, int row, int col, char target) 
        {
            return (find_x(board, row, col, target) &&
                    find_y(board, row, col, target) &&
                    find_x_y(board, row, col, target)
                   );
        }

        bool find_x(std::vector<std::vector<char>>& board, int row, int col, char target)
        {
            for (int i = 0; i < 9; ++i )
            {
                if (target == board[row][i]) return false;
            }
            return true;
        }


        bool find_y(std::vector<std::vector<char>>& board, int row, int col, char target)
        {
            for (int i = 0; i < 9; ++i)
            {
                if (target == board[i][col]) return false;
            }
            return true;
        }

        bool find_x_y(std::vector<std::vector<char>>& board, int row, int col, char target)
        {
            int l_row = (row / 3) * 3; // 确定九方格范围的行下边界
            int l_col = (col / 3) * 3; // 确定九方格范围的列下边界
            for (int i = l_row; i < l_row + 3; ++ i)
            {
                for (int j = l_col; j < l_col + 3; ++ j)
                {
                    if (board[i][j] == target) return false;
                }
            }

            return true;
        }

};

void printArr(const std::vector<std::vector<char>>& board)
{
    for (auto & row : board)
    {
        for (auto & col: row)
        {
            std::cout << col << " ";
        }
        std::cout << std::endl << std::endl;
    }
}

int main()
{
    std::vector<std::vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},
                                           {'6','.','.','1','9','5','.','.','.'},
                                           {'.','9','8','.','.','.','.','6','.'},
                                           {'8','.','.','.','6','.','.','.','3'},
                                           {'4','.','.','8','.','3','.','.','1'},
                                           {'7','.','.','.','2','.','.','.','6'},
                                           {'.','6','.','.','.','.','2','8','.'},
                                           {'.','.','.','4','1','9','.','.','5'},
                                           {'.','.','.','.','8','.','.','7','9'}};
    printArr(board);
    Solution sol;
    sol.solveSudoku(board);
    printArr(board);
    
    return 0;
}

