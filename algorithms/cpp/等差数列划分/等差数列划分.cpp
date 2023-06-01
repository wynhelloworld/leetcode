// Source : https://leetcode.cn/problems/arithmetic-slices/
// Author : Yanan Wang
// Date   : 2023-06-01

/**
 * 动态规划类题目的一般步骤：
 *   1. 状态表示
 *        设dp[i]表示以i结尾的所有子数组中的等差数列的个数
 *   2. 状态转移方程
 *        依据原理： 假设[a b c] 成等差数列，并且c - b == d - c，那么 [a b c d]也成等差数列
 *        给定数组 nums [a b c d e] 假设，此时d的下标为i，那么怎么求dp[i]呢？
 *           仅需判断 c - b == d - c 是否成立，若成立则dp[i] = dp[i - 1] + 1; 若不成立，则dp[i] = 0.
 *        所以，if (nums[i - 1] - nums[i - 2] == nums[i] - nums[i - 1]) 
 *                 dp[i] = dp[i -1] + 1;
 *             else
 *                 dp[i] = 0; 
 *   3. 初始化
 *        dp[0] 和 dp[1] 肯定 == 0，因为等差数列必须要求个数>=3
 *   4. 填表顺序
 *        从i = 2 开始从左向右
 *   5. 返回值
 *        返回dp的所有个数
 */

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        int result = 0;
        for (int i = 2; i < n; ++i)
        {
            if (nums[i - 1] - nums[i - 2] == nums[i] - nums[i - 1])     
                dp[i] = dp[i -1] + 1;
            else
                dp[i] = 0;
             result += dp[i];
        }
        return result;
    }
};