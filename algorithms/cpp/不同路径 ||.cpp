// Source : https://leetcode.cn/problems/unique-paths-ii/
// Author : Yanan Wang
// Date   : 2023-05-19

/**
 * 该题目与《不同路径》非常相似，不同的地方就是在网格中添加了障碍物
 * 有障碍物的地方不能通过，即dp=0
 * 无障碍物的地方能通过，即dp[i][j] = dp[i-1][j] + dp[i][j-1], 
 * (不用担心左和上有障碍物还+？，因为有障碍物的dp=0，不影响上面的dp相加)
 */

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        dp[0][1] = 1;
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
                if (obstacleGrid[i - 1][j - 1] == 0)
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        return dp[m][n];
    }
};
