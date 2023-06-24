// Source : https://leetcode.cn/problems/arithmetic-slices/
// Author : Yanan Wang
// Date   : 2023-06-24

class Solution {
    public int numberOfArithmeticSlices(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n];
        int result = 0;
        for (int i = 2; i < n; i++) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                dp[i] = dp[i - 1] + 1;
            } 
            result += dp[i];
        }
        return result;
    }
}