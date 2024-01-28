# Source : https://leetcode.cn/problems/partition-equal-subset-sum/description/
# Author : Yanan Wang
# Date   : 2024-01-28

class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        m, n = len(nums), sum(nums)
        if n % 2 != 0:
            return False
        dp = [[False] * (n + 1) for _ in range(m + 1)]
        for i in range(m + 1):
            dp[i][0] = True
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                dp[i][j] = dp[i - 1][j]
                if j >= nums[i - 1]:
                    dp[i][j] = dp[i][j] or dp[i - 1][j - nums[i - 1]]
        return dp[-1][n // 2]