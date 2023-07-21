// Source : https://leetcode.cn/problems/profitable-schemes/
// Author : Yanan Wang
// Date   : 2023-07-21

/**
 * 动态规划类题目的一般步骤：
 *    1. 状态表示
 *         设dp[i][j][k]表示从前i个计划中挑选，人数不超过j，利润不低于k的选法种数。
 *    2. 状态转移方程
 *         根据最后一步的状态分情况讨论：
 *                       |- 当不挑选第i个计划时，dp[i - 1][j][k];
 *          dp[i][j][k] -|
 *                       |- 当挑选第i个计划时，如果j >= group[i]，dp[i - 1][j - group[i]][max(0, k - profit[i])];
 *                                                                                   因为利润不低于k，所以k-profit[i]时可以小于0的，
 *                                                                                   虽然状态可以小于0，但数组没有小于0的下标，
 *                                                                                   又由于小于0和等于0的效果其实是一样的，所以这里选了max(...)。
 *    3. 初始化
 *         当i == 0时，dp[0][j][0] = 1，
 *         当j == 0时，无需初始化，因为填表时会进行if判断
 *         当k == 0时，无需初始化
 *    4. 填表顺序
 *         从前往后
 *    5. 返回值
 *         dp[len][n][minProfit]
 */

// class Solution {
// public:
//     int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
//         const int MOD = 1e9 + 7;
//         int len = group.size();
//         vector<vector<vector<int>>> dp(len + 1, vector<vector<int>>(n + 1, vector<int>(minProfit + 1)));
//         for (int j = 0; j <= n; ++j) {
//             dp[0][j][0] = 1;
//         }
//         for (int i = 1; i <= len; ++i) {
//             for (int j = 0; j <= n; ++j) {
//                 for (int k = 0; k <= minProfit; ++k) {
//                     dp[i][j][k] = dp[i - 1][j][k];
//                     if (j >= group[i - 1]) {
//                         dp[i][j][k] += dp[i - 1][j - group[i - 1]][max(0, k - profit[i - 1])];
//                     }
//                     dp[i][j][k] %= MOD;
//                 }
//             }
//         }
//         return dp[len][n][minProfit];
//     }
// };

/**
 * 空间优化
 */

class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        const int MOD = 1e9 + 7;
        int len = group.size();
        vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1));
        for (int j = 0; j <= n; ++j) {
            dp[j][0] = 1;
        }
        for (int i = 1; i <= len; ++i) {
            for (int j = n; j >= group[i - 1]; --j) {
                for (int k = minProfit; k >= 0; --k) {
                    dp[j][k] += dp[j - group[i - 1]][max(0, k - profit[i - 1])];
                    dp[j][k] %= MOD;
                }
            }
        }
        return dp[n][minProfit];
    }
};