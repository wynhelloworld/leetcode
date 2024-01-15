# Source : https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/description/
# Author : Yanan Wang
# Date   : 2024-01-15

class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        n = len(prices)
        f = [[float('-inf')] * (k + 1) for _ in range(n)]
        g = [[float('-inf')] * (k + 1) for _ in range(n)]
        f[0][0] = -prices[0]
        g[0][0] = 0
        
        for i in range(1, n):
            for j in range(k + 1):
                f[i][j] = max(f[i - 1][j], g[i - 1][j] - prices[i])
                g[i][j] = g[i - 1][j]
                if j > 0:
                    g[i][j] = max(g[i][j], f[i - 1][j - 1] + prices[i])

        ans = 0
        for j in range(1, k + 1):
            ans = max(ans, g[n - 1][j])
        
        return ans
