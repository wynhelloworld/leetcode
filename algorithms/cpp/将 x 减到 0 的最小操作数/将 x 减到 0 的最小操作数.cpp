// Source : https://leetcode.cn/problems/minimum-operations-to-reduce-x-to-zero/description/
// Author : Yanan Wang
// Date   : 2023-08-03

/**
 * 本题目如果从正面解“左边减/右边减”是很难的，所以从反面解：从中间找最长的子数组，使其和恰好为nums.size()-x。
 * 然后再运用动态规划的方法就很好解了。
 */

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = -x;
        for (auto &a : nums) target += a;
        if (target < 0) return -1;
        int op_nums = -1;
        for (int left = 0, right = 0, sum = 0; right < nums.size(); ++right) {
            sum += nums[right];
            while (sum > target) sum -= nums[left++];
            if (sum == target) op_nums = max(op_nums, right - left + 1);
        }
        if (-1 == op_nums) return -1;
        return nums.size() - op_nums;
    }
};