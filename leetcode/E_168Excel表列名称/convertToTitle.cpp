#include <iostream>
#include <string>
#include <cstring>


class Solution {
public:
    std::string convertToTitle(int columnNumber) {
        if (columnNumber < 27) return std::string{static_cast<char>('A'+columnNumber-1)};
        int l = (columnNumber - 1) / 26;
        int c = (columnNumber - 1) % 26 + 1;
        return convertToTitle(l) + convertToTitle(c);
    }
};

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    Solution sol;
    std::cout << sol.convertToTitle(n) << std::endl;
    return 0;
}

