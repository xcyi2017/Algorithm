### [1137\. 第 N 个泰波那契数](https://leetcode-cn.com/problems/n-th-tribonacci-number/)



泰波那契序列 T<sub style="display: inline;">n</sub> 定义如下： 

T<sub style="display: inline;">0</sub> = 0, T<sub style="display: inline;">1</sub> = 1, T<sub style="display: inline;">2</sub> = 1, 且在 n >= 0 的条件下 T<sub style="display: inline;">n+3</sub> = T<sub style="display: inline;">n</sub> + T<sub style="display: inline;">n+1</sub> + T<sub style="display: inline;">n+2</sub>

给你整数 `n`，请返回第 n 个泰波那契数 T<sub style="display: inline;">n</sub> 的值。

**示例 1：**

```
输入：n = 4
输出：4
解释：
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4
```

**示例 2：**

```
输入：n = 25
输出：1389537
```

**提示：**

*   `0 <= n <= 37`
*   答案保证是一个 32 位整数，即 `answer <= 2^31 - 1`。

