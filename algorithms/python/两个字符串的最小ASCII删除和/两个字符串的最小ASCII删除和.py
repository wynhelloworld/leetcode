# Source : https://leetcode.cn/problems/minimum-ascii-delete-sum-for-two-strings/
# Author : Yanan Wang
# Date   : 2024-01-27

class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        m, n = len(s1), len(s2)
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
                if s1[i - 1] == s2[j - 1]:
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + ord(s1[i - 1]))
        total = 0
        for x in s1:
            total += ord(x)
        for x in s2:
            total += ord(x)
        return total - 2 * dp[-1][-1]