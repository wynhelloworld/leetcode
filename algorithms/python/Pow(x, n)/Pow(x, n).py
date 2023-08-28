# Source : https://leetcode.cn/problems/powx-n/description/
# Author : Yanan Wang
# Date   : 2023-08-28

# 要计算x的n次幂，我们可以先计算x的n/2次幂再相乘即可，若n%2!=0，再乘一个x
#                           x^n
#            x^(n/2)                   x^(n/2)
#   x^(n/2/2)    x^(n/2/2)        ....        ....
# ....
# 这样时间复杂度就为O(lgn)

class Solution:
    def myPow(self, x: float, n: int) -> float:
        def quickMul(n):
            if n == 0:
                return 1.0
            y = quickMul(n // 2)
            return y * y if n % 2 == 0 else y * y * x
        
        return quickMul(n) if n >= 0 else 1.0 / quickMul(-n)
