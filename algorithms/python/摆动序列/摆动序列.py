# Source : https://leetcode.cn/problems/wiggle-subsequence/description/
# Author : Yanan Wang
# Date   : 2024-01-24

class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        f = [1] * len(nums)
        g = [1] * len(nums)
        for i in range(len(nums)):
            for j in range(i):
                if nums[j] < nums[i]:
                    f[i] = max(f[i], g[j] + 1)
                elif nums[j] > nums[i]:
                    g[i] = max(g[i], f[j] + 1)
        return max(max(f), max(g))
