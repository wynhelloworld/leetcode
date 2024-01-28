# Source : https://leetcode.cn/problems/target-sum/description/
# Author : Yanan Wang
# Date   : 2024-01-28

class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        n = sum(nums) + target
        if n < 0 or n % 2:
            return 0
        n //= 2
        
        dp = [0] * (n + 1)
        dp[0] = 1
        for i in range(1, len(nums) + 1):
            for j in range(n, -1, -1):
                if j >= nums[i - 1]:
                    dp[j] += dp[j - nums[i - 1]]
        return dp[-1]