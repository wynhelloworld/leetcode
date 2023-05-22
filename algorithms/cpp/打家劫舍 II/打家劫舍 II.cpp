// Source : https://leetcode.cn/problems/house-robber-ii/
// Author : Yanan Wang
// Date   : 2023-05-22

/**
 * 该题和《打家劫舍I》极其相似，
 * 唯一不同的就是：
 *          当nums[0]偷时，nums[1]和nums[n-1]不能偷，nums[2]<--->nums[n-2]跟《打家劫舍I》一模一样
 *          当nums[0]不偷时，nums[1]<--->nums[n-1]跟《打家劫舍I》一模一样
 * 所以，该题分情况，选最大值即可
 */

class Solution {
public:
    int rob1(vector<int> nums) {
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
    int rob(vector<int>& nums) {
        if (1 == nums.size()) return nums[0];
        if (2 == nums.size()) return max(nums[0], nums[1]);
        if (3 == nums.size()) return max(max(nums[0], nums[1]), nums[2]);
        int result1 = rob1(vector<int>(nums.begin() + 2, nums.end() - 1));
        int result2 = rob1(vector<int>(nums.begin() + 1, nums.end()));
        return max(nums[0] + result1, result2);
    }
};