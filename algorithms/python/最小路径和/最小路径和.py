# Source : https://leetcode.cn/problems/minimum-path-sum/description/
# Author : Yanan Wang
# Date   : 2024-01-13

class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        dp = [[float('inf')] * (n + 1) for _ in range(m + 1)]
        dp[0][1] = 0
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1]

        return dp[m][n]