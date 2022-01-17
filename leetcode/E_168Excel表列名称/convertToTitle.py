#!/usr/bin/env python
# coding=utf-8
class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        if columnNumber < 27:
            return chr(ord('A') + columnNumber - 1)
        l = (columnNumber - 1) // 26
        c = (columnNumber - 1) % 26 + 1
        return self.convertToTitle(l) + self.convertToTitle(c)


if __name__ == '__main__':
    import sys 

    sol = Solution()
    print(f'{(n:=int(sys.argv[1]))}->{sol.convertToTitle(n)}')
