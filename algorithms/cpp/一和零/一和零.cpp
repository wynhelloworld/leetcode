// Source : https://leetcode.cn/problems/ones-and-zeroes/
// Author : Yanan Wang
// Date   : 2023-07-20

/**
 * 动态规划类题目的一般步骤：
 *    1. 状态表示
 *         设dp[i][j][k]表示从前i个字符串中挑选，0的个数不超过j，1的个数不超过k的最大子集的长度。
 *    2. 状态转移方程
 *         根据最后一步的状态分情况讨论：
 *                        |- 当不挑选strs[i]时，dp[i-1][j][k];
 *           dp[i][j][k] -| 
 *                        |- 当挑选strs[i]时，如果j>=zeroes && k>=ones[i-1][j-zeroes][k-ones] + 1;
 *    3. 初始化
 *         多开辟一行，当i==0时，意味着从前0个字符串中挑选，0的个数不超过i，1的个数不超过j，所以dp[0][j][k]=0
 *         j和k不用初始化，因为填表的时候会进行if判断
 *    4. 填表顺序
 *         填dp[i][j][k]的时候用到了dp[i-1][j][k]和dp[i-1][j-m][k-n]，所以仅需i从前往后即可
 *    5. 返回值
 *         dp[strs.size()][m][n];
 */

// class Solution {
// public:
//     int findMaxForm(vector<string>& strs, int m, int n) {
//         int len = strs.size();
//         vector<vector<vector<int>>> dp(len + 1, vector<vector<int>>(m + 1, vector<int>(n + 1)));
//         for (int i = 1; i <= len; ++i) {
            // int zeroes = 0;
            // int ones = 0;
            // for (auto x : strs[i - 1]) {
            //     if (x == '0') ++zeroes;
            //     if (x == '1') ++ones;
            // }
//             for (int j = 0; j <= m; ++j) {
//                 for (int k = 0; k <= n; ++k) {
//                     dp[i][j][k] = dp[i - 1][j][k];
//                     if (j >= zeroes && k >= ones) {
//                         dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - zeroes][k - ones] + 1);
//                     }
//                 }
//             }
//         }
//         return dp[len][m][n];
//     }
// };

/**
 * 空间优化
 */

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= len; ++i) {
            int zeroes = 0;
            int ones = 0;
            for (auto x : strs[i - 1]) {
                if (x == '0') ++zeroes;
                if (x == '1') ++ones;
            }
            for (int j = m; j >= zeroes; --j) {
                for (int k = n; k >= ones; --k) {
                    dp[j][k] = max(dp[j][k], dp[j - zeroes][k - ones] + 1);
                }
            }
        }
        return dp[m][n];
    }
};