# Source : https://leetcode.cn/problems/the-masseuse-lcci/description/
# Author : Yanan Wang
# Date   : 2024-01-14

class Solution:
    def massage(self, nums: List[int]) -> int:
        if not nums:
            return 0

        n = len(nums)
        f = [0] * n
        g = [0] * n
        f[0] = nums[0]
        
        for i in range(1, n):
            f[i] = g[i - 1] + nums[i]
            g[i] = max(f[i - 1], g[i - 1])

        return max(f[n - 1], g[n - 1])