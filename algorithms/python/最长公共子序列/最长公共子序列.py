# Source : https://leetcode.cn/problems/longest-common-subsequence/description/
# Author : Yanan Wang
# Date   : 2024-01-26

class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        text1 = ' ' + text1
        text2 = ' ' + text2
        m = len(text1)
        n = len(text2)
        dp = [[0] * n for _ in range(m)]
        for i in range(1, m):
            for j in range(1, n):
                if text1[i] == text2[j]:
                    dp[i][j] = dp[i - 1][j - 1] + 1
                else:
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
        return dp[-1][-1]
