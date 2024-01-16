# Source : https://leetcode.cn/problems/maximum-subarray/description/
# Author : Yanan Wang
# Date   : 2024-01-16

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [0] * n
        dp[0] = nums[0]

        for i in range(1, n):
            dp[i] = max(dp[i - 1] + nums[i], nums[i])
            
        ans = dp[0]
        for i in range(1, n):
            ans = max(ans, dp[i])
        
        return ans