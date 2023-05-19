// Source : https://leetcode.cn/problems/three-steps-problem-lcci/
// Author : Yanan Wang
// Date   : 2023-05-17

/**
 * 动态规划类题目的一般步骤：
 *   1. 状态表示
 *        台阶阶数    方法数     一阶      两阶      三阶
 *           0       无意义
 *           1         1
 *           2     1+1=2     1阶->2阶  0阶->2阶
 *           3   2+1+1=4     2阶->3阶  1阶->3阶  0阶->3阶
 *           4   4+2+1=7     3阶->4阶  2阶->4阶  1阶->4阶
 *           5   7+4+2=13    4阶->5阶  3阶->5阶  2阶->5阶
 *         所以，dp[n]表示登上第n阶台阶的方式个数
 *   2. 状态转移方程
 *        dp[n] = dp[n - 3] + dp[n - 2] + dp[n - 1]
 *   3. 初始化
 *        根据状态转移方程可得出当n<3时是不满足该方程的，并且0阶是无意义的，
 *        所以dp[1] = 1, dp[2] = 2, dp[3] = 4
 *   4. 填表顺序
 *        由于求dp[n]需要根据dp[n - 3], dp[n - 2], dp[n - 1],
 *        所以顺序从左向右
 *   5. 返回值
 *        根据题目要求和状态表示，返回dp[n]
 *   6. 本题目还要注意一点：计算的结果可能很大，而这个结果需要模(1e9 + 7)
 */

class Solution
{
public:
    int waysToStep(int n)
    {
        if (1 == n || 2 == n)
            return n;
        if (3 == n)
            return 4;
        const int MOD = 1e9 + 7;
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        for (int i = 4; i <= n; ++i)
        {
            dp[i] = ((dp[i - 3] + dp[i - 2]) % MOD + dp[i - 1]) % MOD;
        }
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
    int waysToStep(int n)
    {
        if (1 == n || 2 == n)
            return n;
        if (3 == n)
            return 4;
        const int MOD = 1e9 + 7;
        int a = 1, b = 2, c = 4, d = 0;
        for (int i = 4; i <= n; ++i)
        {
            d = ((a + b) % MOD + c) % MOD;
            a = b; b = c; c = d;
        }
        return d;
    }
};