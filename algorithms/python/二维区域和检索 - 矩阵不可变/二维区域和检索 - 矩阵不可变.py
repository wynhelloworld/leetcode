# Source : https://leetcode.cn/problems/range-sum-query-2d-immutable/description/
# Author : Yanan Wang
# Date   : 2023-12-19

class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        m = len(matrix) + 1
        n = len(matrix[0]) + 1
        dp = [[0] * n for _ in range(m)]
        print(dp)
        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + matrix[i - 1][j - 1]
        self.dp = dp

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        return self.dp[row2 + 1][col2 + 1] - self.dp[row2 + 1][col1] - self.dp[row1][col2 + 1] + self.dp[row1][col1]


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)