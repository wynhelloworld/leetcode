# Source : https://leetcode.cn/problems/coin-change-ii/description/
# Author : Yanan Wang
# Date   : 2024-01-29

class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        dp = [1] + [0] * amount
        for i in range(1, len(coins) + 1):
            for j in range(amount + 1):
                if j >= coins[i - 1]:
                    dp[j] += dp[j - coins[i - 1]]
        return dp[-1]
