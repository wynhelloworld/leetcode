// Source : https://leetcode.cn/problems/maximum-product-subarray/
// Author : Yanan Wang
// Date   : 2023-06-23

class Solution {
    public int maxSubarraySumCircular(int[] nums) {
        int n = nums.length;    
        int[][] dp = new int[n + 1][2];
        int sum = 0;
        int max = nums[0];
        int min = nums[0];
        for (int i = 1; i <= n; i++) {
            dp[i][0] = Math.max(nums[i - 1], dp[i - 1][0] + nums[i - 1]);
            dp[i][1] = Math.min(nums[i - 1], dp[i - 1][1] + nums[i - 1]);
            sum += nums[i - 1];
            max = Math.max(max, dp[i][0]);
            min = Math.min(min, dp[i][1]);
        }
        if (max < 0) {
            return max;
        }
        return Math.max(max, sum - min);
    }
}