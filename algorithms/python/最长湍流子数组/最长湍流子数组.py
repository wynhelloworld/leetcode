# Source : https://leetcode.cn/problems/longest-turbulent-subarray/description/
# Author : Yanan Wang
# Date   : 2024-01-16

class Solution:
    def maxTurbulenceSize(self, arr: List[int]) -> int:
        n = len(arr)
        f = [1] * n
        g = [1] * n
        ans = 1
        
        for i in range(1, n):
            if arr[i - 1] < arr[i]:
                f[i] = g[i - 1] + 1
            elif arr[i - 1] > arr[i]:
                g[i] = f[i - 1] + 1
            ans = max(ans, f[i], g[i])

        return ans
