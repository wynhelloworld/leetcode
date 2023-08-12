// Source : https://leetcode.cn/problems/find-pivot-index/description/
// Author : Yanan Wang
// Date   : 2023-08-12

/**
 * 本题可用前缀和思想：
 *      f[i]表示[0, i - 1]区间上数的和
 *      g[i]表示[i + 1, n - 1]区间上数的和
 *      f[0] = g[n - 1] = 0;
 *      然后若存在f[i]==g[i]则返回i否则返回-1
 */
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n), g(n);
        for (int i = 1; i < n; ++i) 
            f[i] = f[i - 1] + nums[i - 1];
        for (int i = n - 2; i >= 0; --i)
            g[i] = g[i + 1] + nums[i + 1];
        for (int i = 0; i < n; ++i) 
            if (f[i] == g[i]) 
                return i;
        return -1;
    }
};