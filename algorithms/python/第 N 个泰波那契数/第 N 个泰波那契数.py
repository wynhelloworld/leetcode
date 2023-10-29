# Source : https://leetcode.cn/problems/n-th-tribonacci-number/
# Author : Yanan Wang
# Date   : 2023-10-29

class Solution:
    def tribonacci(self, n: int) -> int:
        if n == 0:
            return 0
        if n <= 2:
            return 1
        a = 0
        b = c = 1
        for i in range(3, n + 1):
            ans = a + b + c
            a, b, c = b, c, ans
        return ans