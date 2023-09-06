# Source : https://leetcode.cn/problems/beautiful-arrangement/description/
# Author : Yanan Wang
# Date   : 2023-09-06

# 先画一颗决策树       
# 剪枝条件有两个: 
#       1、使用过的数字不能进行递归
#       2、不能满足整除条件的不能进行递归

class Solution:
    def countArrangement(self, n: int) -> int:
        ans, used = 0, [False for _ in range(n + 1)]
        def dfs(index = 1):
            if n + 1 == index:
                nonlocal ans
                ans += 1
                return
            for i in range(1, n + 1):
                if not used[i] and (i % index == 0 or index % i == 0):
                    used[i] = True
                    dfs(index + 1)
                    used[i] = False

        dfs()
        return ans