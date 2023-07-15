// Source : https://leetcode.cn/problems/last-stone-weight-ii/
// Author : Yanan Wang
// Date   : 2023-07-15

/**
 * 动态规划类题目的一般步骤：
 *    1. 状态表示
 *         转化：[a, b, c, d, e]
 *                    ⬇️   a和b碰撞，a >= b
 *              [a-b, c, d, e]
 *                    ⬇️   c和a-b碰撞，c >= a-b
 *              [c-a+b, d, e]
 *                    ⬇️   d和c-a+b碰撞，d >= c-a+b
 *              [d-c+a-b, e]
 *                    ⬇️   e和c-a+b碰撞，c-a+b >= e
 *              [d-c+a-b-e]
 *                         此时剩最后一块石头的重量，结果要求>=0
 *              所以本题就变得跟《494.目标和》那道题很像了。
 *              本题，把stones分成A、B两组，求A、B两组差的最小值。
 *              又因为A+B==stones.sum，本题求A-B或者B-A的最小值，所以本题就又转化为了从stones中选择一些数，使得这些数的和最接近于stones.sum/2
 *         所以，状态表示为：设dp[i][j]表示从前i个数中选择，选择出的数组成的和最接近于j
 *    2. 状态转移方程
 *         根据最后一步的状态分情况讨论：
 *                     |- 不选择stones[i]时，dp[i - 1][j];
 *           dp[i][j] -|
 *                     |- 选择stones[i]时，如果j >= stones[i]，dp[i - 1][j - stones[i]] + stones[i];
 *    3. 初始化
 *         多开辟一行，当i==0即挑选前0个数时，dp[0][j] = 0, j >= 0
 *         多开辟一列，当j==0即挑选前i个数组成j时，dp[i][0] = 0, i >= 0
 *    4. 填表顺序
 *         从左向右，从上往下
 *    5. 返回值
 *         stones.sum - 2 * dp[n][stones.sum/2];
 */

// class Solution {
// public:
//     int lastStoneWeightII(vector<int>& stones) {
//         int n = stones.size(), sum = 0;
//         for (auto x : stones) {
//             sum += x;
//         }
//         int aim = sum / 2;
//         vector<vector<int>> dp(n + 1, vector<int>(aim + 1));
//         for (int i = 1; i <= n; ++i) {
//             for (int j = 1; j <= aim; ++j) {
//                 dp[i][j] = dp[i - 1][j];
//                 if (j >= stones[i - 1]) {
//                     dp[i][j] = max(dp[i][j], dp[i - 1][j - stones[i - 1]] + stones[i - 1]);
//                 }
//             }
//         }
//         return sum - 2 * dp[n][aim];
//     }
// };

/**
 * 优化：采用滚动数组的方式
 *   由于填dp[i][j]仅需要dp[i - 1][j]和dp[i - 1][j - nums[i - 1]]，也就是仅需要上一行即可，那么就可以将dp[N][N]优化为dp[2][N]。
 *   但其实还可以将dp[2][N]优化为dp[N]。
 *                                       * 表示dp[i][j]    
 *                                       # 表示dp[i - 1][j]或者dp[i - 1][j - nums[i - 1]]
 *   ---------------------
 *   |   |   |   |   |   |
 *   ---------------------             ---------------------
 *   |   | # |   | # |   |             |   | # |   | # |   |            ------------------------
 *   ---------------------     -->     ---------------------     -->    |   | # |   |   | #(*) | 
 *   |   |   |   | * |   |             |   |   |   | * |   |            ------------------------
 *   ---------------------             ---------------------            改为这种方式，需要从后往前填表
 *   |   |   |   |   |   |
 *   ---------------------
 */

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size(), sum = 0;
        for (auto x : stones) {
            sum += x;
        }
        int aim = sum / 2;
        vector<int> dp(aim + 1);
        for (int i = 1; i <= n; ++i) {
            for (int j = aim; j >= stones[i - 1]; --j) {
                dp[j] = max(dp[j], dp[j - stones[i - 1]] + stones[i - 1]);
            }
        }
        return sum - 2 * dp[aim];
    }
};