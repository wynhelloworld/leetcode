// Source : https://leetcode.cn/problems/coin-change/
// Author : Yanan Wang
// Date   : 2023-07-17

/**
 * 动态规划类题目的一般步骤：
 *    1. 状态表示
 *         设dp[i][j]表示从前i个硬币中挑选，凑成总金额j的最少硬币个数。
 *    2. 状态转移方程
 *         根据最后一步的状态分情况讨论：
 *                      |- 当不挑选coins[i]时，dp[i - 1][j];
 *            dp[i][j] -|- 当挑选1个coins[i]时，如果j >= coins[i]，dp[i - 1][j - coins[i]] + 1;
 *                      |- 当挑选2个coins[i]时，如果j >= 2 * coins[i]，dp[i - 1][j - 2 * coins[i]] + 2;
 *                      |- 当挑选3个coins[i]时，如果j >= 3 * coins[i]，dp[i - 1][j - 3 * coins[i]] + 3;
 *                      |- . . .
 *            即，dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i]] + 1);
 *    3. 初始化
 *         多开辟一行：当i==0时，只有当j也为0时，dp[0][0]=0, 当j > 0时，dp[0][j]是非法的，因为该题目求min，所以这些非法位置填一个大数即可
 *         多开辟一列，无初始化，因为填表时会进行if判断
 *         注意下标的映射
 *    4. 填表顺序
 *         从上往下，从左往右
 *    5. 返回值
 *         dp[n][amount] >= INF ? -1 : dp[n][amount];
 */

// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         const int INF = 0x3f3f3f3f;
//         int n = coins.size();
//         vector<vector<int>> dp(n + 1, vector<int>(amount + 1));
//         for (int j = 1; j <= amount; ++j) {
//             dp[0][j] = INF;
//         } 
//         for (int i = 1; i <= n; ++i) {
//             for (int j = 0; j <= amount; ++j) {
//                 dp[i][j] = dp[i - 1][j];
//                 if (j >= coins[i - 1]) {
//                     dp[i][j] = min(dp[i][j], dp[i][j - coins[i - 1]] + 1);
//                 }
//             }
//         }
//         return dp[n][amount] >= INF ? -1 : dp[n][amount];
//     }
// };

/**
 * 空间优化
 */

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int INF = 0x3f3f3f3f;
        int n = coins.size();
        vector<int> dp(amount + 1, INF);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= amount; ++j) {
                if (j >= coins[i - 1]) {
                    dp[j] = min(dp[j], dp[j - coins[i - 1]] + 1);
                }
            }
        }
        return dp[amount] >= INF ? -1 : dp[amount];
    }
};