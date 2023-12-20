# Source : https://leetcode.cn/problems/spiral-matrix-ii/description/
# Author : Yanan Wang
# Date   : 2023-12-20

class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        u = 0
        d = n - 1
        l = 0
        r = n - 1
        martix = [[0] * n for _ in range(n)]
        k = 1
        while True:
            for i in range(l, r + 1):
                martix[u][i] = k
                k += 1
            u += 1
            if u > d:
                break

            for i in range(u, d + 1):
                martix[i][r] = k
                k += 1
            r -= 1
            if r < l:
                break
            
            for i in range(r, l - 1, -1):
                martix[d][i] = k
                k += 1
            d -= 1
            if d < u:
                break
            
            for i in range(d, u - 1, -1):
                martix[i][l] = k
                k += 1
            l += 1
            if l > r:
                break
        
        return martix