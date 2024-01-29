# Source : https://leetcode.cn/problems/perfect-squares/description/
# Author : Yanan Wang
# Date   : 2024-01-29

class Solution:
    def numSquares(self, n: int) -> int:
        dp = [float('inf')] * (n + 1)
        dp[0] = 0
        for i in range(1, int(sqrt(n)) + 1):
            for j in range(n + 1):
                if j >= i * i:
                    dp[j] = min(dp[j], dp[j - i * i] + 1)
        return dp[-1]