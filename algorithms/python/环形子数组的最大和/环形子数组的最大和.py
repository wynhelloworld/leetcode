# Source : https://leetcode.cn/problems/maximum-sum-circular-subarray/description/
# Author : Yanan Wang
# Date   : 2024-01-16

class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        n = len(nums)
        max_dp = [0] * n
        min_dp = [0] * n 
        max_dp[0] = min_dp[0] = nums[0]

        for i in range(1, n):
            max_dp[i] = max(max_dp[i - 1] + nums[i], nums[i])
            min_dp[i] = min(min_dp[i - 1] + nums[i], nums[i])

        sum_ans = max_ans = min_ans = nums[0]
        for i in range(1, n):
            sum_ans += nums[i]
            max_ans = max(max_ans, max_dp[i])
            min_ans = min(min_ans, min_dp[i])

        if max_ans < 0:
            return max_ans
        return max(max_ans, sum_ans - min_ans)
