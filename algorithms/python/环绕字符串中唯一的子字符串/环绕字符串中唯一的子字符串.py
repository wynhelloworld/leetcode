# Source : https://leetcode.cn/problems/unique-substrings-in-wraparound-string/description/
# Author : Yanan Wang
# Date   : 2024-01-22

class Solution:
    def findSubstringInWraproundString(self, s: str) -> int:
        s = ' ' + s
        n = len(s)
        dp = [1] * n 
        mapper = collections.defaultdict(lambda: 0)

        for i in range(1, n):
            if ord(s[i]) - ord(s[i - 1]) == 1 or ord(s[i]) - ord(s[i - 1]) == -25:
                dp[i] += dp[i - 1]
            mapper[s[i]] = max(mapper[s[i]], dp[i])

        return sum(mapper.values())