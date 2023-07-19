// Source : https://leetcode.cn/problems/perfect-squares/
// Author : Yanan Wang
// Date   : 2023-07-19

/**
 * 动态规划类题目的一般步骤：
 *    1. 状态表示
 *         设dp[i][j]表示从前i个完全平方数中挑选，总和正好等于j的选法中的最少数量。
 *    2. 状态转移方程
 *         根据最后一步的状态分情况讨论：
 *                     |- 当不挑选i^2时，dp[i - 1][j];
 *           dp[i][j] -|- 当挑选1个i^2时，如果j >= i^2，dp[i - 1][j - i^2] + 1;
 *                     |- 当挑选2个i^2时，如果j >= 2 * i^2，dp[i - 1][j - 2 * i^2] + 2;
 *                     |- 当挑选3个i^2时，如果j >= 3 * i^2，dp[i - 1][j - 3 * i^2] + 3;
 *                     |- . . .
 *    3. 初始化
 *         多开辟一行，当i==0时，只有j也==0时，dp[0][0] = 0，当j>0时，dp[0][j]时选不到的，本题求最少数量，所以dp[0][j]可以填一个无穷大
 *         多开辟一列，但不用初始化，因为填表时会进行if判断
 *    4. 填表顺序
 *         从前往后，从左到右
 *    5. 返回值
 *         dp[sqrt(n)][n]
 */

// class Solution {
// public:
//     int numSquares(int n) {
//         const int INF = 0x3f3f3f3f;
//         int m = sqrt(n);
//         vector<vector<int>> dp(m + 1, vector<int>(n + 1));
//         for (int j = 1; j <= n; ++j) {
//             dp[0][j] = INF;
//         }
//         for (int i = 1; i <= m; ++i) {
//             for (int j = 0; j <= n; ++j) {
//                 dp[i][j] = dp[i - 1][j];
//                 if (j >= i * i) {
//                     dp[i][j] = min(dp[i][j], dp[i][j - i * i] + 1);
//                 }
//             }
//         }
//         return dp[m][n];
//     }
// }; 

/**
 * 空间优化
 */

class Solution {
public:
    int numSquares(int n) {
        const int INF = 0x3f3f3f3f;
        int m = sqrt(n);
        vector<int> dp(n + 1, INF);
        dp[0] = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (j >= i * i) {
                    dp[j] = min(dp[j], dp[j - i * i] + 1);
                }
            }
        }
        return dp[n];
    }
}; 
