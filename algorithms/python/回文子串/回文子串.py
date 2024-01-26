# Source : https://leetcode.cn/problems/palindromic-substrings/description/
# Author : Yanan Wang
# Date   : 2024-01-26

class Solution:
    def countSubstrings(self, s: str) -> int:
        n = len(s)
        dp = [[False] * n for _ in range(n)]
        ans = 0
        for i in range(n - 1, -1, -1):
            for j in range(i, n):
                if s[i] == s[j]:
                    dp[i][j] = dp[i + 1][j - 1] if i + 1 < j else True
                if dp[i][j]:
                    ans += 1
        return ans
        
