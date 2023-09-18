// Source : https://leetcode.cn/problems/unique-paths/
// Author : Yanan Wang
// Date   : 2023-05-19

/**
 *  动态规划类题目的一般步骤：
 *    1. 状态表示
 *         题目问“达到网格右下角总共有多少种不同的路径”，即问达到网格[m-1][n-1]总共有多少种不同路径，
 *         那么，不妨假设dp[i][j]就是达到网格[i][j]位置的不同路径总数。
 *    2. 状态转移方程
 *         根据一般套路（以dp[i][j]为结尾或者开头，根据i、j的最近几步推倒处状态转移方程），
 *         这里以dp[i][j]为结尾，即根据题目描述“机器人每次只能向下或者向右移动一步”，
 *         那么dp[i][j]=dp[i-1][j]+dp[i][j-1]
 *    3. 初始化
 *         一般的初始化，这里需要将dp[0][j]和dp[i][0]全都初始化为1，但这里可以选用一个技巧，
 *         即dp数组多开辟一行一列
 *    4. 填表顺序
 *         可以选用先填满每一行（从左向右），再以行为单位填满每一列（从上向下），
 *         也可以选先填满每一列（从上向下），再以列为单位填满每一行（从左向右）。
 *    5. 返回值
 *         由于dp多开辟了一行一列，即返回dp[m][n]
 */

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        dp[0][1] = 1;
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        return dp[m][n];
    }
};

// 新增了一种记忆化搜索的方法

class Solution {
private:
    vector<vector<int>> memory;
public:
    int memorySearch(int i, int j) {
        if (memory[i][j] != -1) return memory[i][j];
        if (i == 0 || j == 0) return 0;
        if (i == 1 && j == 1) {
            memory[i][j] = 1;
            return memory[i][j];
        }
        memory[i][j] = memorySearch(i - 1, j) + memorySearch(i, j - 1);
        return memory[i][j];
    }
    int uniquePaths(int m, int n) {
        memory.resize(m + 1, vector<int>(n + 1, -1));
        return memorySearch(m, n);
    }
};