// Source : https://leetcode.cn/problems/wiggle-subsequence/
// Author : Yanan Wang
// Date   : 2023-06-26

/**
 * 动态规划类题目的一般步骤：
 *    1. 状态表示
 *         设dp[i][0]表示以nums[i]结尾的子序列中，最后差为正数的摆动序列的最长长度
 *         设dp[i][1]表示以nums[i]结尾的子序列中，最后差为负数的摆动序列的最长长度
 *    2. 状态转移方程
 *         dp[i][0] = dp[j][1] + 1;    (0 <= j < i, 只加最大的dp[j][1])
 *         dp[1][1] = dp[j][0] + 1;    (0 <= j < i, 只加最大的dp[j][0])
 *    3. 初始化
 *         dp[i][0] = dp[i][1] = 1;
 *    4. 填表顺序
 *         从左向右
 *    5. 返回值
 *         dp中的最大值
 */
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2, 1));
        int result = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] - nums[i - 1] > 0) {
                for (int j = i - 1; j >= 0; --j) {
                    dp[i][1] = max(dp[i][1], dp[j][0] + 1);
                }
            } else if (nums[i] - nums[i - 1] < 0) {
                for (int j = i - 1; j >= 0; --j) {
                    dp[i][0] = max(dp[i][0], dp[j][1] + 1);
                }
            }
            result = max(max(result, dp[i][0]), dp[i][1]);
        }
        return result;
    }
};