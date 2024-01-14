# Source : https://leetcode.cn/problems/house-robber-ii/description/
# Author : Yanan Wang
# Date   : 2024-01-14

class Solution:
    def rob1(self, nums: List[int]) -> int:
        n = len(nums)
        f = [0] * n
        g = [0] * n
        f[0] = nums[0]

        for i in range(1, n):
            f[i] = g[i - 1] + nums[i]
            g[i] = max(f[i - 1], g[i - 1])

        return max(f[n - 1], g[n - 1])

    def rob(self, nums: List[int]) -> int:
        return max(self.rob1(nums[:-1]), self.rob1(nums[1:])) if len(nums) != 1 else nums[0]