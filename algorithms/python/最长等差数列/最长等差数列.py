# Source : https://leetcode.cn/problems/longest-arithmetic-subsequence/description/
# Author : Yanan Wang
# Date   : 2024-01-25

class Solution:
    def longestArithSeqLength(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [[2] * n for _ in range(n)]
        indices = {nums[0]: 0}
        ans = 2
        for i in range(1, n - 1):
            for j in range(i + 1, n):
                prev = 2 * nums[i] - nums[j]
                if prev in indices:
                    dp[i][j] = dp[indices[prev]][i] + 1
                ans = max(ans, dp[i][j])
            indices[nums[i]] = i
        return ans 