# Source : https://leetcode.cn/problems/min-cost-climbing-stairs/description/ 
# Author : Yanan Wang
# Date   : 2023-10-30

# 状态表示: 
#   设dp[n]表示爬到第n个台阶, 所需要的最低费用. 
# 状态转移方程:
#   dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2])
# 初始化:
#   dp[0] = dp[1] = 0
#   因为可以选择从下标为0或下标为1的台阶开始爬
# 填表顺序:
#   从左向右
# 返回值:
#   dp[n]
#   因为, 题目要求返回达到楼梯“顶部"的最低花费

class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        dp = [0] * (n + 1)
        for i in range(2, n + 1):
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2])
        return dp[n]
