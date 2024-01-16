# Source : https://leetcode.cn/problems/maximum-product-subarray/description/
# Author : Yanan Wang
# Date   : 2024-01-16

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        n = len(nums)
        max_dp = [1] * (n + 1) 
        min_dp = [1] * (n + 1) 
        ans = nums[0]

        for i in range(1, n + 1):
            max_dp[i] = max(nums[i - 1], max_dp[i - 1] * nums[i - 1], min_dp[i - 1] * nums[i - 1])
            min_dp[i] = min(nums[i - 1], max_dp[i - 1] * nums[i - 1], min_dp[i - 1] * nums[i - 1])
            ans = max(ans, max_dp[i])

        return ans