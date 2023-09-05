# Source : https://leetcode.cn/problems/combination-sum/description/
# Author : Yanan Wang
# Date   : 2023-09-05

# 本题解采用回溯法
# 先画一颗决策树
#                        开始
#       |-----------|-----------|-----------|
#       2           3           6           7
#    2 3 6 7     2 3 6 7     2 3 6 7     2 3 6 7
#                ^           ^ ^         ^ ^ ^
#               不选          不选         不选
#  ......
# 剪枝的情况分为两种：
#    1、当出现重复组合的时候进行剪枝
#    2、在递归过程中出现sum > target的时候进行剪枝
# 递归出口：当sum == target的时候

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        n = len(candidates)
        ans, path = [], []
        def dfs(sum = 0, index = 0):
            if sum > target:
                return
            if sum == target:
                ans.append(path[:])
                return
            for i in range(index, n):
                path.append(candidates[i])
                dfs(sum + candidates[i], i)
                path.pop()
            
        dfs()
        return ans
    