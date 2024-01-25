# Source : https://leetcode.cn/problems/length-of-longest-fibonacci-subsequence/description/
# Author : Yanan Wang
# Date   : 2024-01-25

class Solution:
    def lenLongestFibSubseq(self, arr: List[int]) -> int:
        n = len(arr)
        dp = [[2] * n for _ in range(n)]
        indices = {x: i for i, x in enumerate(arr)}
        ans = 0
        for i in range(1, n - 1):
            for j in range(i + 1, n):
                prev = arr[j] - arr[i]
                if (prev in indices) and prev < arr[i]:
                    dp[i][j] = dp[indices[prev]][i] + 1
                ans = max(ans, dp[i][j])
        return ans if ans != 2 else 0
