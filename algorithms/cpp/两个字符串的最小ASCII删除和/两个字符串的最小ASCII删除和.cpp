// Source : https://leetcode.cn/problems/minimum-ascii-delete-sum-for-two-strings/
// Author : Yanan Wang
// Date   : 2023-07-11

/**
 * 动态规划类题目的一般步骤：
 *    1. 状态表示
 *         题目要求返回所删除字符的最小和, 那么不妨先求出两字符串的公共子序列的最大和。
 *         设dp[i][j]表示s1在区间[0,i]以及s2在区间[0,j]上的公共子序列的最大和。
 *    2. 状态转移方程
 *         如果s1[i] == s2[j], 那么此时dp[i][j] = dp[i - 1][j - 1] + s1[i];
 *         如果s1[i] != s2[j], 那么此时dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
 *         最后再求这两个的最大值
 *    3. 初始化
 *         多开辟一行和一列, 但由于s1或者s2为空串时的公共子序列的最大和为0, 所以初始化为0
 *    4. 填表顺序
 *         从左向右, 从上向下
 *    5. 返回值
 *         dp的最后一个值表示公共子序列的最大和, 题目要求返回删除字符的最小和, 那么返回s1和s2总字符和减去最大和
 */

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + s1[i - 1]);
                }
            }
        }
        int sum = 0;
        for (auto c : s1) {
            sum += c;
        }
        for (auto c : s2) {
            sum += c;
        }
        return sum - 2 * dp[m][n];
    }
};