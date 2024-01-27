# Source : https://leetcode.cn/problems/interleaving-string/description/
# Author : Yanan Wang
# Date   : 2024-01-27

class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        s1, s2, s3 = ' ' + s1, ' ' + s2, ' ' + s3
        m, n = len(s1), len(s2)
        dp = [[False] * n for _ in range(m)]
        dp[0][0] = True
        for i in range(1, m):
            if s1[i] != s3[i]:
                break
            dp[i][0] = True
        for j in range(1, n):
            if s2[j] != s3[j]:
                break
            dp[0][j] = True
        for i in range(1, m):
            for j in range(1, n):
                if s1[i] == s3[i + j]:
                    dp[i][j] = dp[i - 1][j]
                elif s2[j] == s3[i + j]:
                    dp[i][j] = dp[i][j - 1]
        return dp[-1][-1]
