// Source : https://leetcode.cn/problems/coin-change-ii/
// Author : Yanan Wang
// Date   : 2023-07-18

/**
 * 动态规划类题目的一般步骤：
 *    1. 状态表示
 *         设dp[i][j]表示从前i个元素中挑选，能凑成总金额j的总方法数。
 *    2. 状态转移方程
 *         根据最后一步的状态分情况讨论：
 *                        |- 当不挑选coins[i]时，dp[i - 1][j];
 *            dp[i][j] = -|- 当挑选1个coins[i]时，如果j >= coins[i]，dp[i - 1][j - coins[i]];、
 *                        |- 当挑选2个coins[i]时，如果j >= 2 * coins[i]，dp[i - 1][j - 2 * coins[i]];
 *                        |- 当挑选2个coins[i]时，如果j >= 3 * coins[i]，dp[i - 1][j - 3 * coins[i]];
 *                        |- . . .
 *    3. 初始化
 *         多开辟一行，当i==0时，dp[0][0] = 1; dp[0][j] = 0; j > 0
 *         多开辟一列，无需初始化，因为填表时会有if判断
 *    4. 填表顺序
 *         从左向右，从上向下
 *    5. 返回值
 *         dp[n][amount]
 */

// class Solution {
// public:
//     int change(int amount, vector<int>& coins) {
//         int n = coins.size();
//         vector<vector<int>> dp(n + 1, vector<int>(amount + 1));
//         dp[0][0] = 1;
//         for (int i = 1; i <= n; ++i) {
//             for (int j = 0; j <= amount; ++j) {
//                 dp[i][j] = dp[i - 1][j];
//                 if (j >= coins[i - 1]) {
//                     dp[i][j] += dp[i][j - coins[i - 1]];
//                 }
//             }
//         }
//         return dp[n][amount];
//     }
// };

/**
 * 空间优化
 */

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= amount; ++j) {
                if (j >= coins[i - 1]) {
                    dp[j] += dp[j - coins[i - 1]];
                }
            }
        }
        return dp[amount];
    }
};