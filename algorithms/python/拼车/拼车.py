# Source : https://leetcode.cn/problems/car-pooling/description/
# Author : Yanan Wang
# Date   : 2023-12-19

class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        m = len(trips)
        n = 0
        for i in range(m):
            n = max(n, trips[i][2])
        
        lines = [[0] * (n + 1) for _ in range(2)]
        for i in range(m):
            lines[0][trips[i][2]] += trips[i][0]
            lines[1][trips[i][1]] += trips[i][0]

        for i in range(n + 1):
            capacity += lines[0][i]
            capacity -= lines[1][i]
            if capacity < 0:
                return False
        
        return True