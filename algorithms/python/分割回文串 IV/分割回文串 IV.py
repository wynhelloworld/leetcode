# Source : https://leetcode.cn/problems/palindrome-partitioning-iv/description/
# Author : Yanan Wang
# Date   : 2024-01-26

class Solution:
    def checkPartitioning(self, s: str) -> bool:
        n = len(s)
        dp = [[False] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            for j in range(i, n):
                if s[i] == s[j]:
                    dp[i][j] = dp[i + 1][j - 1] if i + 1 < j else True
        for i in range(n - 2):
            for j in range(i + 2, n):
                if dp[0][i] and dp[i + 1][j - 1] and dp[j][n - 1]:
                    return True
        return False