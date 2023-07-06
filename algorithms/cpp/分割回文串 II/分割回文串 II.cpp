// Source : https://leetcode.cn/problems/palindrome-partitioning-ii/
// Author : Yanan Wang
// Date   : 2023-07-06

/**
 * 设动态规划类题目的一般步骤：
 *    1. 状态表示
 *         设dp[i]表示[0, i]区间最长的子串的最少分割次数。
 *    2. 状态转移方程
 *         如果[0, i]区间的最长子串是回文串，那么次数就为0；
 *         如果[0, i]区间的最长子串不是回文串，那么就看[j, i]区间的最长子串是否是回文串，如果是，那么次数就为min(dp[0, j - 1] + 1, dp[i]);
 *       ⭐️此时，有一个优化，就是快速判断一个区间是否回文，可以采用《647.回文子串》的方法。
 *    3. 初始化
 *         初始化dp的值为无穷大，因为在求次数的时候是求min
 *    4. 填表顺序 
 *         从左向右
 *    5. 返回值 
 *         dp[n - 1]
 */
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> isPal(n, vector<bool>(n));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (s[i] == s[j]) {
                    isPal[i][j] = i + 1 < j ? isPal[i + 1][j - 1] : true;
                }
            }
        }
        vector<int> dp(n, INT_MAX);
        for (int i = 0; i < n; ++i) {
            if (isPal[0][i]) {
                dp[i] = 0;
            } else {
                for (int j = i; j > 0; --j) {
                    if (isPal[j][i]) {
                        dp[i] = min(dp[i], dp[j - 1] + 1);
                    }
                }
            }
        }
        return dp[n - 1];
    }
};