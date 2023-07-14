// Source : https://leetcode.cn/problems/partition-equal-subset-sum/
// Author : Yanan Wang
// Date   : 2023-07-14

/**
 * 动态规划类题目的一般步骤：
 *    1. 状态表示
 *         本题把问题转化成：从nums中挑一些数使得这些数的和恰好等于sum/2。这样本题就成了01背包问题了。
 *         设dp[i][j]表示在[0,i]区间内挑一些数能否凑成j。
 *    2. 状态转移方程
 *         以最后一步的状态分情况讨论：
 *                   |- 当不选择nums[i]时，dp[i - 1][j];
 *         dp[i][j] -|
 *                   |- 当选择nums[i]时，如果 j >= nums[i]，dp[i - 1][j - nums[i]];
 *         所以状态转移方程为：dp[i][j] = dp[i - 1][j] || (j >= nums[i] && dp[i - 1][j - nums[i]]);     
 *    3. 初始化
 *         多开辟一行，当i==0，即挑选0个数时，只能凑成j为0，凑不成其它，所以dp[0][0] = true; dp[0][j] = false; j > 0
 *         多开辟一列，当j==0，即凑成j为0时，只需要不选择数即可，所以dp[i][0] = true; i >= 0
 *    4. 填表顺序
 *         从上往下，从左往右
 *    5. 返回值
 *         dp[n][sum / 2]
 */

// class Solution {
// public:
//     bool canPartition(vector<int>& nums) {
//         int n = nums.size();
//         int sum = 0;
//         for (auto x : nums) {
//             sum += x;
//         }
//         if (sum % 2) {
//             return false;
//         }
//         vector<vector<int>> dp(n + 1, vector<int>(sum / 2 + 1));
//         for (int i = 0; i <= n; ++i) {
//             dp[i][0] = true;
//         }
//         for (int i = 1; i <= n; ++i) {
//             for (int j = 1; j <= sum / 2; ++j) {
//                 dp[i][j] = dp[i - 1][j] || (j >= nums[i - 1] && dp[i - 1][j - nums[i - 1]]); 
//             }
//         }
//         return dp[sum / 2];
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
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (auto x : nums) {
            sum += x;
        }
        if (sum % 2) {
            return false;
        }
        vector<int> dp(sum / 2 + 1);
        dp[0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = sum / 2; j >= nums[i - 1]; --j) {
                dp[j] = dp[j] || dp[j - nums[i - 1]]; 
            }
        }
        return dp[sum / 2];
    }
};