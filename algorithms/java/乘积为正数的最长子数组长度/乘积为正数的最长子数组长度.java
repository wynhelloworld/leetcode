// Source : https://leetcode.cn/problems/maximum-length-of-subarray-with-positive-product/
// Author : Yanan Wang
// Date   : 2023-06-23

class Solution {
    public int getMaxLen(int[] nums) {
        int n = nums.length;
        int[][] dp = new int[n + 1][2];
        int result = 0;
        for (int i = 1; i <= n; i++) {
            if (nums[i - 1] > 0) {
                dp[i][0] = dp[i - 1][0] + 1;
                dp[i][1] = dp[i - 1][1] == 0 ? 0 : dp[i - 1][1] + 1;
            } else if (nums[i - 1] < 0) {
                dp[i][0] = dp[i - 1][1] == 0 ? 0 : dp[i - 1][1] + 1;
                dp[i][1] = dp[i - 1][0] + 1;
            }  
            result = Math.max(result, dp[i][0]);
        }
        return result;
    }
}