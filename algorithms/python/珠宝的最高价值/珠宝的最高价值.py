# Source : https://leetcode.cn/problems/li-wu-de-zui-da-jie-zhi-lcof/description/
# Author : Yanan Wang
# Date   : 2024-01-13

class Solution:
    def jewelleryValue(self, frame: List[List[int]]) -> int:
        m = len(frame)
        n = len(frame[0])
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + frame[i - 1][j - 1]
        
        return dp[m][n]