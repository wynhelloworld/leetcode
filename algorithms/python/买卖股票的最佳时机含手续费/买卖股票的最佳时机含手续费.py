# Source : https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/
# Author : Yanan Wang
# Date   : 2024-01-15

class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        n = len(prices)
        f = [0] * n
        g = [0] * n
        f[0] = -prices[0]

        for i in range(1, n):
            f[i] = max(f[i - 1], g[i - 1] - prices[i])
            g[i] = max(g[i - 1], f[i - 1] + prices[i] - fee)
        
        return max(f[n - 1], g[n - 1])