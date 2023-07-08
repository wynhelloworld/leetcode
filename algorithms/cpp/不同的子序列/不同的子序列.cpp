// Source : https://leetcode.cn/problems/distinct-subsequences/
// Author : Yanan Wang
// Date   : 2023-07-08

/**
 * 动态规划类题目的一般步骤：
 *    1. 状态表示
 *         设dp[i][j]表示s在区间[0,j]内的所有子序列中，有多少个t在区间[0,i]内的子串。
 *    2. 状态转移方程
 *         根据s的子序列的最后一个位置包含不包含s[j]
 *         如果不包含的话, dp[i][j] = dp[i][j - 1];
 *         如果包含的话，并且如果s[i] == t[j]的话, dp[i][j] += dp[i - 1][j - 1]; 
 *    3. 初始化
 *         多开一行和一列，第一行为1(因为此时t为空串)，其余为0
 *    4. 填表顺序
 *         从左向右，从上向下
 *    5. 返回值
 *         dp的最后一个值
 */

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = t.size();
        int n = s.size();
        vector<vector<double>> dp(m + 1, vector<double>(n + 1));
        for (int j = 0; j <= n; ++j) {
            dp[0][j] = 1;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = dp[i][j - 1];
                if (t[i - 1] == s[j - 1]) {
                    dp[i][j] += dp[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};