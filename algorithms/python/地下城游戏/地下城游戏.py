# Source : https://leetcode.cn/problems/dungeon-game/description/
# Author : Yanan Wang
# Date   : 2024-01-13

class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        m = len(dungeon)
        n = len(dungeon[0])
        dp = [[float('inf')] * (n + 1) for _ in range(m + 1)]
        dp[m][n - 1] = 1
        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]
                if dp[i][j] <= 0:
                    dp[i][j] = 1
        
        return dp[0][0]