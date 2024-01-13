# Source : https://leetcode.cn/problems/minimum-falling-path-sum/description/
# Author : Yanan Wang
# Date   : 2024-01-13

class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        m = len(matrix)
        n = len(matrix[0])
        dp = [[0] * (n + 2) for _ in range(m + 1)]
        for i in range(m + 1):
            dp[i][0] = dp[i][n + 1] = float('inf')
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j], dp[i - 1][j + 1]) + matrix[i - 1][j - 1]
        ans = float('inf')
        for j in range(1, n + 1):
            ans = min(ans, dp[m][j])
        
        return ans
