# Source : https://leetcode.cn/problems/longest-palindromic-substring/description/
# Author : Yanan Wang
# Date   : 2024-01-26

class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        dp = [[False] * n for _ in range(n)]
        ans_beg = 0
        ans_len = 1
        for i in range(n - 1, -1, -1):
            for j in range(i, n):
                if s[i] == s[j]:
                    dp[i][j] = dp[i + 1][j - 1] if i + 1 < j else True
                if dp[i][j] and ans_len < j - i + 1:
                    ans_beg = i
                    ans_len = j - i + 1 
        return s[ans_beg:ans_beg + ans_len]
