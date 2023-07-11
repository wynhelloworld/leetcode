// Source : https://leetcode.cn/problems/interleaving-string/
// Author : Yanan Wang
// Date   : 2023-07-11

/**
 * 动态规划类题目的一般步骤：
 *    1. 状态表示
 *         设dp[i][j]表示s1在区间[0,i]以及s2在区间[0,j]能否交错组成s3在区间[0,i+j+1]
 *         由于下标从1开始更为简单, 所以在s1、s2、s3前填充一个字符, 使其下标从1开始。
 *         即状态表示为：设dp[i][j]表示s1在区间[1,i]以及s2在区间[1,j]能否交错组成s3在区间[1,i+j]
 *    2. 状态转移方程
 *         dp[i][j] = (s1[i] == s3[i + j] && dp[i - 1][j]) || (s2[j] == s3[i + j] && dp[i][j - 1]);
 *    3. 初始化
 *         在s1.size() + s2.size() == s3.size()的情况下
 *         s1和s2都为空时, dp[0][0] = true;
 *         s1为空, s2不为空时, 仅有s2[j]和s3[j]从前往后相等的时候为true, 一旦不相等, 后面全为false; 
 *         s2为空, s1不为空时, 仅有s1[i]和s3[i]从前往后相等的时候为true, 一旦不相等, 后面全为false; 
 *    4. 填表顺序
 *         从上到下, 从左到右
 *    5. 返回值
 *         dp的最后一个值
 */

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        if (m + n != s3.size()) {
            return false;
        }
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));
        s1 = ' ' + s1, s2 = ' ' + s2, s3 = ' ' + s3;
        dp[0][0] = true;
        for (int i = 1; i <= m; ++i) {
            if (s1[i] == s3[i]) {
                dp[i][0] = true;
            } else {
                break;
            }
        }
        for (int j = 1; j <= n; ++j) {
            if (s2[j] == s3[j]) {
                dp[0][j] = true;
            } else {
                break;
            }
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = (s1[i] == s3[i + j] && dp[i - 1][j]) || (s2[j] == s3[i + j] && dp[i][j - 1]);
            }
        }
        return dp[m][n];
    }
};