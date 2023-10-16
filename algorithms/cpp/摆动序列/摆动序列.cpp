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

/**
 * 新增了一种贪心解法
 * 针对nums[a, b]
 *      若 a < b, 则成上升趋势
 *      若 a == b, 则成水平趋势
 *      若 a > b, 则成下降趋势
 * 根据以上规则，把nums全部画出来，取所有的极值就是本题的贪心解(最优解)
 * 如何取到所有的极值？
 *      用一个left记录所有当前点的前一个趋势
 *      left == 0, 默认趋势
 *      left > 0, 上升趋势
 *      left < 0, 下降趋势
 *      用right来记录当前点的趋势后一个趋势
 */

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int ans = 1;
        int left = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            int right = nums[i + 1] - nums[i];
            if (right == 0) {
                continue;
            }
            if (left * right <= 0) {
                ++ans;
                left = right;
            }
        }
        return ans;
    }
};