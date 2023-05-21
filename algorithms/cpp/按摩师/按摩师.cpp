// Source : https://leetcode.cn/problems/the-masseuse-lcci/
// Author : Yanan Wang
// Date   : 2023-05-21

/**
 * 动态规划类题目的一般步骤：
 *   1. 状态表示
 *        假设dp[i]表示到nums[i]位置的最长预约时间，但还是不够清晰，因为没有说清楚nums[i]位置的预约到底接不接
 *        因此，假设f[i]表示接受nums[i]的预约时的最长预约时间
 *             假设g[i]表示不接受nums[i]的预约时的最长预约时间
 *   2. 状态转移方程
 *        f[i] = g[i-1] + nums[i];
 *        g[i] = max(f[i-1], g[i-1])
 *   3. 初始化
 *        f[0] = nums[0]
 *        g[0] = 0
 *   4. 填表顺序
 *        一起从左向右
 *   5. 返回值
 *        max(f[n - 1], g[n - 1])
 */

class Solution {
public:
    int massage(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
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