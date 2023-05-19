// Source : https://leetcode.cn/problems/li-wu-de-zui-da-jie-zhi-lcof/
// Author : Yanan Wang
// Date   : 2023-05-19

/**
 * 动态规划类题目的一般步骤：
 *   1. 状态表示
 *        题目的意思就是，给一个棋盘，从左上角走到右下角，返回这一条路径上礼物的最多价值。
 *        那么假设dp[i][j]表示从左上角走到棋盘[i][j]位置时所能拿到礼物的最多价值。
 *   2. 状态转移方程
 *        以dp[i][j]为结尾，以i、j最近的几步推导出状态转移方程：
 *        dp[i][j]=grid[i][j]+max(dp[i-1][j], dp[i][j-1])
 *   3. 初始化
 *        正常的初始化需要人为的将dp数组的第一行和第一列计算并填充，这里可以选择创建一个多一行和多一列的dp数组
 *        并且状态转移方程修改为：dp[i][j]=grid[i-1][j-1]+max(dp[i-1][j], dp[i][j-1])
 *   4. 填表顺序
 *        按照正常的二维数组的遍历顺序即可（先从左向右填满第一行，再填第二行. . .）
 *   5. 返回值
 *        返回dp[m][n]
 */

class Solution
{
public:
    int maxValue(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
                dp[i][j] = grid[i - 1][j - 1] + max(dp[i - 1][j], dp[i][j - 1]);
        return dp[m][n];
    }
};