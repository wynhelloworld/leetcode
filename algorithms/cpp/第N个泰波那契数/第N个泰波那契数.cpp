// Source : https://leetcode.cn/problems/n-th-tribonacci-number/
// Author : Yanan Wang
// Date   : 2023-05-17

/**
 * 动态规划类题目的一般步骤：
 *   1. 状态表示
 *        dp[n]表示第n个泰波那契数的值
 *   2. 状态转移方程
 *        dp[n] = dp[n - 3] + dp[n - 2] + dp[n - 1]
 *   3. 初始化
 *        根据状态转移方程可以得出，当n<3时，是无法满足该方程的
 *        并且题目已给出dp[0] = 0, dp[1] = dp[2] = 1
 *   4. 填表顺序
 *        从左向右，因为需要数组的前3个数去求第四个数
 *   5. 返回值
 *        根据题目要求“返回第n个泰波那契数的值”，
 *        根据状态表示“dp[n]表示第n个泰波那契数的值”
 *        所以，返回dp[n]
 */

class Solution
{
public:
    int tribonacci(int n)
    {
        if (0 == n)
            return 0;
        if (1 == n || 2 == n)
            return 1;
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = dp[2] = 1;
        for (int i = 3; i <= n; ++i)
            dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
        return dp[n];
    }
};

/**
 * 空间优化
 * 由于求dp[n]只需要dp[n - 3], dp[n - 2], d[n - 1]，之前的数dp[0]...dp[n - 4]已不再需要
 * 所以仅需四个变量以滚动数组的形式就能够解答本题目
 * For example：
 *     a + b + c = d
 *         ⬇  ⬇  ⬇
 *         a + b + c = d
 *             ⬇  ⬇  ⬇
 *             a + b + c = d
 */

class Solution
{
public:
    int tribonacci(int n)
    {
        if (0 == n)
            return 0;
        if (1 == n || 2 == n)
            return 1;
        int a = 0, b = 1, c = 1, d = 0;
        for (int i = 3; i <= n; ++i)
        {
            d = a + b + c;
            a = b; b = c; c = d;
        }
        return d;
    }
};