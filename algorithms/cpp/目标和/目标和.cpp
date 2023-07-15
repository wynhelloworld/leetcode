// Source : https://leetcode.cn/problems/target-sum/
// Author : Yanan Wang
// Date   : 2023-07-15

/**
 * 动态规划类题目的一般步骤：
 *    1. 状态表示
 *         转化：把nums恰好分为两组，一组为A，另一组为B，求A-B==target的总数。
 *         继续转化：因为 A - B == target;A + B == nums.sum;
 *                 所以A == （target + nums.sum） / 2; 
 *         所以状态表示为：设dp[i][j]表示在区间[0,i]上随意挑一些数恰好能组成j的方法总数。
 *    2. 状态转移方程
 *         根据最后一步的状态分情况讨论：
 *                       |- 不选择nums[i]时，dp[i - 1][j];
 *             dp[i][j] -|
 *                       |- 选择nums[i]时，如果j >= nums[i]，dp[i - 1][j - nums[i]];
 *         所以，最终的状态转移方程为：dp[i][j] = dp[i - 1][j] + (j >= nums[i] ? dp[i - 1][j - nums[i]] : 0);
 *    3. 初始化
 *         多开辟一行，当i==0即挑选0个数时，组成j==0的方法数为1，dp[0][0]=1，而组成j==其它的方法书为0，dp[0][j]=0，j>0
 *         多开辟一列，当j==0即挑选一些数组成j==0时，只需要不挑选数字即可组成j==0，dp[i][0]=1，i>=0
 *    4. 填表顺序
 *         从左往右，从上到下
 *    5. 返回值
 *         dp[n][(target+nums.sum)/2]
 */

// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int n = nums.size(), sum = 0;
//         for (auto x : nums) {
//             sum += x;
//         }
//         int aim = (target + sum) / 2;
//         if (aim < 0 || (target + sum) % 2) {
//             return 0;
//         }
//         vector<vector<int>> dp(n + 1, vector<int>(aim + 1));
//         dp[0][0] = 1;
//         for (int i = 1; i <= n; ++i) {
//             for (int j = 0; j <= aim; ++j) {
//                 dp[i][j] = dp[i - 1][j] + (j >= nums[i - 1] ? dp[i - 1][j - nums[i - 1]] : 0);
//             }
//         }
//         return dp[n][aim];
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
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size(), sum = 0;
        for (auto x : nums) {
            sum += x;
        }
        int aim = (target + sum) / 2;
        if (aim < 0 || (target + sum) % 2) {
            return 0;
        }
        vector<int> dp(aim + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = aim; j >= nums[i - 1]; --j) {
                dp[j] += dp[j - nums[i - 1]];
            }
        }
        return dp[aim];
    }
};