# Source : https://leetcode.cn/problems/arithmetic-slices/description/
# Author : Yanan Wang
# Date   : 2024-01-16

class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [0] * n 
        ans = 0
        
        for i in range(2, n):
            if nums[i] + nums[i - 2] == nums[i - 1] * 2:
                dp[i] = dp[i - 1] + 1
            ans += dp[i]
        
        return ans
