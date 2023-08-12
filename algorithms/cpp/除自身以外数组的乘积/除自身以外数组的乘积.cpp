// Source : https://leetcode.cn/problems/product-of-array-except-self/description/
// Author : Yanan Wang
// Date   : 2023-08-12

/**
 * 本题可用前缀和(积)思想：
 *      f[i]表示[0, i - 1]区间上数的积
 *      g[i]表示[i + 1, n - 1]区间上数的积
 *      f[0] = g[n - 1] = 1;
 *      然后result[i] = f[i] * g[i]
 */
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n, 1), g(n, 1);
        for (int i = 1; i < n; ++i)
            f[i] = f[i - 1] * nums[i - 1];
        for (int i = n - 2; i >= 0; --i)
            g[i] = g[i + 1] * nums[i + 1];
        vector<int> result(n);
        for (int i = 0; i < n; ++i) 
            result[i] = f[i] * g[i];
        return result;
    }
};