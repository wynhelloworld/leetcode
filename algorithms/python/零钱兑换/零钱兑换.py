# Source : https://leetcode.cn/problems/coin-change/description/
# Author : Yanan Wang
# Date   : 2024-01-29

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [float('inf')] * (amount + 1)
        dp[0] = 0
        for i in range(1, len(coins) + 1):
            for j in range(1, amount + 1):
                if j >= coins[i - 1]:
                    dp[j] = min(dp[j], dp[j - coins[i - 1]] + 1)
        return dp[-1] if dp[-1] != float('inf') else -1