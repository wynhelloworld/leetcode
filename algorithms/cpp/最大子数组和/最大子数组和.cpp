// Source : https://leetcode.cn/problems/maximum-subarray/
// Author : Yanan Wang
// Date   : 2023-05-30

/**
 * 动态规划类题目的一般步骤：
 *   1. 状态表示
 *        设dp[i]表示以i结尾的子数组中的最大和
 *   2. 状态转移方程
 *        以i结尾的子数组有两种状态，要么就是本身，要么就是i-1结尾的子数组加上本身，so
 *        dp[i] = max(nums[i], dp[i - 1] + nums[i]);
 *   3. 初始化
 *        要么手动初始化dp[0]为nums[0]，要么dp多开一个位置，
 *        当选择dp多开一个位置时，要注意两点：1、多开位置放入的值不能影响后面的填表
 *                                      2、要注意dp和nums下标的映射
 *   4. 填表顺序
 *        从左向右
 *   5. 返回值
 *        dp里记录着所有以i结尾的子数组中的最大和，那么就返回dp的最大值
 */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; ++i)
            dp[i] = max(nums[i - 1], dp[i - 1] + nums[i - 1]);
        int result = INT_MIN;
        for (int i = 1; i <= n; ++i)
            if (result < dp[i])
                result = dp[i];
        return result;
    }
};