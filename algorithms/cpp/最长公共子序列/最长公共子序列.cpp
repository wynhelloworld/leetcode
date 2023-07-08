// Source : https://leetcode.cn/problems/longest-common-subsequence/
// Author : Yanan Wang
// Date   : 2023-07-08

/**
 * 动态规划类题目的一般步骤：
 *    1. 状态表示
 *         设dp[i][j]表示text1在区间[0,i]以及text2在区间[0,j]上的最长公共子序列的长度。
 *    2. 状态转移方程
 *         当text1[i] == text2[j]时，最长公共子序列一定是以text1[i]和text2[j]结尾的，因为假设在内部有最长公共子序列时，但此时又因为text1[i]==text2[j]，所以上述结论一定正确。
 *         所以 if (text1[i] == text2[j]) { dp[i][j] = dp[i - 1][j - 1] + 1; }
 *              else { dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]); }
 *    3. 初始化
 *         本题，空串是有意义的，最长公共子序列的长度为0，并且为了防止上述状态转移方程填表时的越界，这里选择多开辟一行和一列。
 *         此时，会有两个注意点：1、多的这一行和一列里的值不能影响后续填表的结果，这里选择全部填0；
 *                           2、要注意下标的映射关系，针对这一点，可以选择对两字符串前边分别添加一个字符即可。
 *    4. 填表顺序
 *         从上往下，从前往后
 *    5. 返回值
 *         dp的最后一个值
 */

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        text1 = ' ' + text1;
        text2 = ' ' + text2;
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1, vector<int>(n2));
        for (int i = 1; i < n1; ++i) {
            for (int j = 1; j < n2; ++j) {
                if (text1[i] == text2[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        return dp[n1 - 1][n2 - 1];
    }
};