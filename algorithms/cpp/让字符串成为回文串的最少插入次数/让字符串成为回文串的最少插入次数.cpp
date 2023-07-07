// Source : https://leetcode.cn/problems/minimum-insertion-steps-to-make-a-string-palindrome/
// Author : Yanan Wang
// Date   : 2023-07-06

/**
 * 动态规划类题目的一般步骤：
 *    1. 状态表示
 *         设dp[i][j]表示区间[i, j]内的最少操作次数。
 *    2. 状态转移方程
 *         当s[i] == s[j]时，有三种情况：1、i == j，dp[i][j] = 0
 *                                    2、i + 1 == j，dp[i][j] = 0
 *                                    3、i + 1 < j，dp[i][j] = dp[i + 1][j - 1]
 *           s[i] != s[j]时，有两种操作方式：1、左边插入，dp[i][j] = dp[i][j - 1] + 1
 *                                        2、有扁插入，dp[i][j] = dp[i + 1][j] + 1      
 *    3. 初始化
 *         无需初始化
 *    4. 填表顺序
 *         从下往上，从左向右
 *    5. 返回值
 *         dp[0][n - 1]
 */

class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i][j - 1], dp[i + 1][j]) + 1;
                }
            }
        } 
        return dp[0][n - 1];
    }
};