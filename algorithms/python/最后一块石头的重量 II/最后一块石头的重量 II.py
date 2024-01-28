# Source : https://leetcode.cn/problems/last-stone-weight-ii/description/
# Author : Yanan Wang
# Date   : 2024-01-28

class Solution:
    def lastStoneWeightII(self, stones: List[int]) -> int:
        n = sum(stones) // 2
        dp = [0] * (n + 1)
        for i in range(0, len(stones)):
            for j in range(n, 0, -1):
                if j >= stones[i - 1]:
                    dp[j] = max(dp[j], dp[j - stones[i - 1]] + stones[i - 1])
        return sum(stones) - 2 * dp[-1]
