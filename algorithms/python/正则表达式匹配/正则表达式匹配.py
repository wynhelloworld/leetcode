# Source : https://leetcode.cn/problems/regular-expression-matching/description/
# Author : Yanan Wang
# Date   : 2024-01-27

class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        m, n = len(s), len(p)
        dp = [[False] * (n + 1) for _ in range(m + 1)]
        dp[0][0] = True
        for j in range(2, n + 1, 2):
            if p[j - 1] != '*':
                break
            dp[0][j] = True
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if p[j - 1] == '*':
                    dp[i][j] = dp[i][j - 2] or (p[j - 2] == '.' or p[j - 2] == s[i - 1]) and dp[i - 1][j] 
                else:
                    dp[i][j] = (p[j - 1] == '.' or s[i - 1] == p[j - 1]) and dp[i - 1][j - 1]
        return dp[-1][-1]