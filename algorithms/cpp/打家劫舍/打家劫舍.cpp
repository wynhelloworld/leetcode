// Source : https://leetcode.cn/problems/house-robber/
// Author : Yanan Wang
// Date   : 2023-05-22

/**
 * 动态规划类题目的一般步骤：
 *   1. 状态表示
 *        假设dp[i]表示到nums[i]房屋时偷到的最大金额，那么还可以更细的表示为
 *             f[i]表示到nums[i]房屋时，偷了nums[i]钱后，偷到的最大金额
 *             f[i]表示到nums[i]房屋时，不偷nums[i]钱后，偷到的最大金额
 *   2. 状态转移方程
 *        f[i] = g[i - 1] + nums[i]
 *        g[i] = max(f[i - 1], g[i - 1]) 
 *   3. 初始化
 *        f[0] = nums[0];
 *        g[0] = 0;
 *   4. 填表顺序
 *        一起从左向右
 *   5. 返回值
 *        max(f[n - 1], g[n - 1])
 */

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n);
        vector<int> g(n);
        f[0] = nums[0];
        for (int i = 1; i < n; ++i)
        {
            f[i] = g[i - 1] + nums[i];
            g[i] = max(f[i - 1], g[i - 1]);
        }
        return max(f[n - 1], g[n - 1]);
    }
};