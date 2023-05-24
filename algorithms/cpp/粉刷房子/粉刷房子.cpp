// Source : https://leetcode.cn/problems/JEj789/
// Author : Yanan Wang
// Date   : 2023-05-24

/**
 * 动态规划类题目的一般步骤：
 *   1. 状态表示
 *        设dp[i]表示粉刷完costs[i]的最低花费，但并不清楚costs[i]粉刷的什么颜色，即要更清晰的状态表示
 *        所以，设r[i]表示粉刷完costs[i]为红色的最低花费
 *        所以，设b[i]表示粉刷完costs[i]为蓝色的最低花费
 *        所以，设g[i]表示粉刷完costs[i]为绿色的最低花费
 *   2. 状态转移方程
 *        r[i] = min(b[i - 1], g[i - 1]) + costs[i][0];
 *        b[i] = min(r[i - 1], g[i - 1]) + costs[i][1];
 *        g[i] = min(r[i - 1], b[i - 1]) + costs[i][2];
 *   3. 初始化
 *        r[0] = costs[0][0];
 *        b[0] = costs[0][1];
 *        g[0] = costs[0][2];
 *   4. 填表顺序
 *        从左向右
 *   5. 返回值
 *        r[n - 1], b[n - 1], g[n - 1] 的最小值
 */

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<int> r(n), b(n), g(n);
        r[0] = costs[0][0];
        b[0] = costs[0][1];
        g[0] = costs[0][2];
        for (int i = 1; i < n; ++i)
        {
            r[i] = min(b[i - 1], g[i - 1]) + costs[i][0];
            b[i] = min(r[i - 1], g[i - 1]) + costs[i][1];
            g[i] = min(r[i - 1], b[i - 1]) + costs[i][2];
        }
        return min(min(r[n - 1], b[n - 1]), g[n - 1]);
    }
};