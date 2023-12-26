# Source : https://leetcode.cn/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/description/
# Author : Yanan Wang
# Date   : 2023-12-26

class Solution:
    def spiralArray(self, array: List[List[int]]) -> List[int]:
        if not array:
            return []

        u = 0
        d = len(array) - 1
        l = 0
        r = len(array[0]) - 1

        ans = []
        while True:
            for i in range(l, r + 1):
                ans.append(array[u][i])
            u += 1
            if u > d:
                break

            for i in range(u, d + 1):
                ans.append(array[i][r])
            r -= 1
            if r < l:
                break

            for i in range(r, l - 1, -1):
                ans.append(array[d][i])
            d -= 1
            if d < u:
                break

            for i in range(d, u - 1, -1):
                ans.append(array[i][l])
            l += 1
            if l > r:
                break

        return ans 