# Source : https://leetcode.cn/problems/JEj789/description/
# Author : Yanan Wang
# Date   : 2024-01-14

class Solution:
    def minCost(self, costs: List[List[int]]) -> int:
        n = len(costs)
        r = [0] * (n + 1)
        g = [0] * (n + 1)
        b = [0] * (n + 1)

        for i in range(1, n + 1):
            r[i] = min(g[i - 1], b[i - 1]) + costs[i - 1][0]
            g[i] = min(r[i - 1], b[i - 1]) + costs[i - 1][1]
            b[i] = min(g[i - 1], r[i - 1]) + costs[i - 1][2]

        return min(r[n], g[n], b[n])
