// Source : https://leetcode.cn/problems/minimum-falling-path-sum/
// Author : Yanan Wang
// Date   : 2023-05-19

/**
 * 动态规划类题目的一般步骤：
 *    1. 状态表示
 *         题目要求返回matrix的下降路径的最小和，那么不妨假设dp[i][j]为下降到matrix[i][j]的下降路径最小和，
 *         当求出matrix的最后一行的所有的dp，找出一个最小的返回即可，
 *    2. 状态转移方程
 *         根据以dp[i][j]为结尾或者开头，并且根据以i、j最近的几步推导出状态转移方程，
 *         dp[i][j] = matrix[i][j] + min(dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1])
 *    3. 初始化
 *         普通的初始化需要手动的将第一行、第一列、最后一列全部初始化，那么可以选用多开一行、两列的做法，
 *         并且将第一行初始化为全0，第一列、最后一列初始化为INT_MAX（不包含一行）
 *    4. 填表顺序
 *         列从左向右，行从上向下
 *    5. 返回值
 *         dp最后一行的最小元素
 */

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 2, INT_MAX));
        for (int i = 0; i < n + 2; ++i)
            dp[0][i] = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                dp[i][j] = matrix[i - 1][j - 1] + min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i - 1][j + 1]);
        int result = INT_MAX;
        for (int i = 1; i <= n; ++i)
            result = result > dp[n][i] ? dp[n][i] : result;
        return result;
    }
};