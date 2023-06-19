// Source : https://leetcode.cn/problems/house-robber-ii/
// Author : Yanan Wang
// Date   : 2023-06-19

class Solution {
    public int rob(int[] nums) {
        if (1 == nums.length) return nums[0];
        if (2 == nums.length) return Math.max(nums[0], nums[1]);
        if (3 == nums.length) return Math.max(Math.max(nums[0], nums[1]), nums[2]);
        int result1 = rob1(nums, 0, nums.length - 1);
        int result2 = rob1(nums, 1, nums.length - 2) + nums[nums.length - 1];
        return Math.max(result1, result2);
    }
    public int rob1(int[] nums, int left, int right) {
        int n = right - left;
        int f[] = new int[n + 1];
        int g[] = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            f[i] = g[i - 1] + nums[left + i - 1];
            g[i] = Math.max(f[i - 1], g[i - 1]);
        }
        return Math.max(f[n], g[n]);
    }
}