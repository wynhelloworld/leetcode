# Source : https://leetcode.cn/problems/sum-of-all-subset-xor-totals/description/
# Author : Yanan Wang
# Date   : 2023-09-01

# 该题与《78. 子集》几乎差不多
# 但值得一提的是：本题可以利用异或的特性“消消乐”来进行恢复现场

class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        ans, path = 0, 0
        def dfs(nums, pos = 0):
            nonlocal ans, path
            ans += path
            for i in range(pos, len(nums)):
                path ^= nums[i]
                dfs(nums, i + 1)
                # 恢复现场
                path ^= nums[i]

        dfs(nums)
        return ans                 