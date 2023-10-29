# Source : https://leetcode.cn/problems/three-steps-problem-lcci/description/
# Author : Yanan Wang
# Date   : 2023-10-29

class Solution:
    def waysToStep(self, n: int) -> int:
        if n <= 2:
            return n
        a = b = 1
        c = 2
        for i in range(3, n + 1):
            ans = (a + b + c) % 1000000007
            a, b, c = b, c, ans
        return ans