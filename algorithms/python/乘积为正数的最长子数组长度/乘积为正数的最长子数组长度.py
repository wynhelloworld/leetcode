# Source : https://leetcode.cn/problems/maximum-length-of-subarray-with-positive-product/description/
# Author : Yanan Wang
# Date   : 2024-01-16

class Solution:
    def getMaxLen(self, nums: List[int]) -> int:
        n = len(nums)
        f = [0] * (n + 1)
        g = [0] * (n + 1)
        ans = 0
 
        for i in range(1, n + 1):
            if nums[i - 1] > 0:
                f[i] = f[i - 1] + 1
                g[i] = g[i - 1] + 1 if g[i - 1] != 0 else 0
            elif nums[i - 1] < 0:
                g[i] = f[i - 1] + 1
                f[i] = g[i - 1] + 1 if g[i - 1] != 0 else 0
            ans = max(ans, f[i])
 
        return ans
