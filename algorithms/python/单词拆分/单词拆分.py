# Source : https://leetcode.cn/problems/word-break/description/
# Author : Yanan Wang
# Date   : 2024-01-17

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        n = len(s)
        dp = [False] * (n + 1)
        dp[0] = True
        for i in range(1, n + 1):
            for j in range(i, 0, -1):
                if dp[j - 1] and (s[j-1:i] in wordDict):
                    dp[i] = True
        
        return dp[n]