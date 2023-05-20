// Source : https://leetcode.cn/problems/minimum-path-sum/
// Author : Yanan Wang
// Date   : 2023-05-20

/**
 * 动态规划类题目的一般步骤：
 *   1. 状态表示
 *        假设dp[i][j]表示：从左上角到grid[i][j]的路径最小数字总和
 *   2. 状态转移方程
 *        dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1])
 *   3. 初始化
 *        采用多开辟一行一列的方式初始化，那么状态转移方程就改为：
 *        dp[i][j] = grid[i - 1][j - 1] + min(dp[i-1][j], dp[i][j-1])
 *        dp全部填充INT_MAX，dp[0][1]或者dp[1][0]填0
 *   4. 填表顺序
 *        列从左向右，行从上向下
 *   5. 返回值
 *        返回dp[m][n]
 */

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        dp[0][1] = 0;
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
                dp[i][j] = grid[i - 1][j - 1] + min(dp[i-1][j], dp[i][j-1]);
        return dp[m][n];
    }
};