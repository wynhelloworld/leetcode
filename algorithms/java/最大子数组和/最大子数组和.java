// Source : https://leetcode.cn/problems/maximum-subarray/
// Author : Yanan Wang
// Date   : 2023-06-23

class Solution {
    public int maxSubArray(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n + 1];
        int result = nums[0];
        for (int i = 1;  i <= n; i++) {
            dp[i] = Math.max(nums[i - 1], dp[i - 1] + nums[i - 1]);
            result = Math.max(result, dp[i]);
        }
        return result;
    }
}