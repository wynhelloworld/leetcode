// Source : https://leetcode.cn/problems/longest-palindromic-subsequence/
// Author : Yanan Wang
// Date   : 2023-07-06

/**
 * 动态规划类题目的一般步骤：
 *    1. 状态表示
 *         设dp[i][j]表示[i, j]区间内的所有子序列中，回文子序列的最长长度。
 *    2. 状态转移方程
 *         既然是求回文子序列，那么算长度时一定是s[i] = s[j]时，此时有三种情况：1、i == j，长度为1，dp[i][j] = 1
 *                                                                    2、i + 1 == j，长度为2，dp[i][j] == 2
 *                                                                    3、i + 1 < j，长度为dp[i + 1][j - 1] + 2，dp[i][j] = dp[i + 1][j - 1] + 2
 *                                         s[i] != s[j]时，dp[i][j] = max(dp[i][j - 1], dp[i + 1][j])
 *    3. 初始化
 *         无需初始化
 *    4. 填表顺序
 *         从下往上填每一行，从左往右填每一列
 *    5. 返回值
 *         dp[0][n - 1]
 */

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = n - 1; i >= 0; --i) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
                }
            }
        }
        return dp[0][n - 1];
    }
};