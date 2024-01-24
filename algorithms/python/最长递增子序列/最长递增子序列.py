# Source : https://leetcode.cn/problems/longest-increasing-subsequence/
# Author : Yanan Wang
# Date   : 2024-01-24

class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if not nums:
            return 0
        dp = [1] * len(nums) 
        for i in range(1, len(nums)):
            for j in range(i):
                if nums[j] < nums[i]:
                    dp[i] = max(dp[i], dp[j] + 1)
        return max(dp)