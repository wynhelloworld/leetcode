// Source : https://leetcode.cn/problems/palindrome-partitioning-iv/
// Author : Yanan Wang
// Date   : 2023-07-05

/**
 * 动态规划类题目的一般步骤：
 *    1. 状态表示
 *         设dp[i][j]表示以s[i]开始、s[j]结尾的字串是否是回文串
 *    2. 状态转移方程
 *         当s[i] == s[j]时，有三种情况：1、i == j 此时就一个字母，肯定是回文串
 *                                    2、i + 1 == j 此时是相邻两个字母相同，也肯定是回文串
 *                                    3、有三个及以上个字母，此时看s[i + 1]和s[j - 1]是否相等，若相等，则为回文串
 *       ⭐️即，if (s[i] == s[j]) { dp[i][j] = i + 1 < j ? dp[i + 1][j - 1] : true; } 
 *    3. 初始化
 *         无需初始化
 *    4. 填表顺序
 *         从下往上填每一行，从前往后填每一列
 *    5. 返回值
 *         dp表中存储了所有可能的子串是否是回文串的信息，那么只需要便利dp表，看紧邻的三个区间是否都为回文串即可。
 */

class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (s[i] == s[j]) {
                    dp[i][j] = i + 1 < j ? dp[i + 1][j - 1] : true;
                }
            }
        }
        for (int i = 1; i < n; ++i) {
            for (int j = i; j < n - 1; ++j) {
                if (dp[0][i - 1] && dp[i][j] && dp[j + 1][n - 1]) {
                    return true;
                }
            }
        }
        return false;
    }
};