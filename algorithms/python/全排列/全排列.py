# Source : https://leetcode.cn/problems/permutations/description/
# Author : Yanan Wang
# Date   : 2023-08-31

# 本题先画出一个决策树，然后根据该树写递归
# 用全局变量ans保存结果，用path记录下递归过程中的数字，用used进行剪枝
# 用Python写本题时，注意递归出口那里，python传参用的是引用传参(浅拷贝)，这里应该用深拷贝

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        ans, path, used = [], [], [False for _ in range(len(nums))]
        def dfs(nums):
            if len(path) == len(nums):
                ans.append(path[:])
                return
            for i in range(len(nums)):
                if not used[i]:
                    path.append(nums[i])
                    used[i] = True
                    dfs(nums)
                    path.pop()
                    used[i] = False

        dfs(nums)
        return ans