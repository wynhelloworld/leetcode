// Source : https://leetcode.cn/problems/maximum-sum-circular-subarray/
// Author : Yanan Wang
// Date   : 2023-05-30

/**
 * 这道题目和《最大子数组和》非常相似，唯一不同的点就是将数组变成环形的了。
 * 像这么非常相似的拓展题目，可以尽量往最本质的题上靠。
 * 现在，假设最终答案在数组的中间，那么就可以用《最大子数组和》来直接求这部分，
 * 但还有一种可能就是答案不在数组的中间，而在两端（开始首位相接了），也求出这部分答案，
 * 最后返回这两部分答案的最大值即可。
 *  1、        假设答案在这部分区间
 *    ｜--------------------------------｜
 *    ｜        ***************         ｜
 *    ｜--------------------------------｜
 *
 *  2、       假设答案在这头和尾区间
 *    ｜--------------------------------｜
 *    ｜********               *********｜
 *    ｜--------------------------------｜
 *     对于该情况，要求头尾区间的最大值还是有难度的（情况太多），
 *     但若是求出中间空白区域的最小值，用总值-最小值即是头尾区间的最大值
 *  即，返回max(f_max, sum - g_min);
 *  但，还有个特殊情况，就是假设nums全部都是负数，那么sum-g_min == 0，
 *  返回的最终结果应是f_max，但却会返回0.
 *  所以最终答案是：
 *     if (sum == g_min) return f_max;
 *     return max(f_max, sum - g_min);
 */ 

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n + 1);
        vector<int> g(n + 1);
        int sum = 0;
        for (int i = 1; i <= n; ++i)
        {
            f[i] = max(nums[i - 1], f[i - 1] + nums[i - 1]);
            g[i] = min(nums[i - 1], g[i - 1] + nums[i - 1]);
            sum += nums[i - 1];
        }
        int f_max = INT_MIN;
        int g_min = INT_MAX;
        for (int i = 1; i <= n; ++i)
        {
            if (f_max < f[i]) f_max = f[i];
            if (g_min > g[i]) g_min = g[i];
        }
        if (sum == g_min) return f_max;
        return max(f_max, sum - g_min);
    }
};