// Source : https://leetcode.cn/problems/combination-sum-iv/
// Author : Yanan Wang
// Date   : 2023-07-22

/**
 * 动态规划类题目的一般步骤：
 *    1. 状态表示
 *         本题很像完全背包问题，但实际上不是，因为完全背包问题解决的是数学上的组合问题，而本题目的“组合”在数学上称为排列。
 *         所以，本题通过分析问题的过程中，发现子问题，进而抽象出一个状态来表示，
 *         当锁定一个nums中的值x的时候，问题就变为了求nums中剩余的数排列和为target-x的个数了。
 *         所以，状态表示为：dp[i]表示凑成和为i的总的排列总数。
 *    2. 状态转移方程
 *         当锁定nums[j]的时候，如果i >= nums[j]，dp[i] += dp[i - nums[j]];
 *    3. 初始化
 *         dp[0] = 1; 因为如果dp[0] = 0的话，后面的填表就全为0。
 *    4. 填表顺序
 *         从前往后。
 *    5. 返回值
 *         dp[target];
 */

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<double> dp(target + 1);
        dp[0] = 1;
        for (int i = 1; i <= target ; ++i) 
            for (auto x : nums) 
                if (i >= x) 
                    dp[i] += dp[i - x];
        return dp[target];
    }
};