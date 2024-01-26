# Source : https://leetcode.cn/problems/palindrome-partitioning-ii/description/
# Author : Yanan Wang
# Date   : 2024-01-26

class Solution:
    def minCut(self, s: str) -> int:
        n = len(s)
        is_pal = [[False] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            for j in range(i, n):
                if s[i] == s[j]:
                    is_pal[i][j] = is_pal[i + 1][j - 1] if i + 1 < j else True
        dp = [float('inf')] * n
        for i in range(n):
            if is_pal[0][i]:
                dp[i] = 0
            else:
                for j in range(1, i + 1):
                    if is_pal[j][i]:
                        dp[i] = min(dp[i], dp[j - 1] + 1)
        return dp[-1]