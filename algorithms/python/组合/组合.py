# Source : https://leetcode.cn/problems/combinations/description/
# Author : Yanan Wang
# Date   : 2023-09-04

# 本题还是先画出决策树，然后分析好剪枝情况，递归自然就能写出来
# 本题有两种剪枝情况：
#            1、本层使用掉的元素，下一层不能再使用
#            2、本题是不能够有重复的组合的，所以重复的组合也要剪枝掉

class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        ans, path, used = [], [], [False for _ in range(n + 1)]
        def dfs(index = 1):
            if len(path) == k:
                ans.append(path[:])
                return
            for i in range(index, n + 1):
                if not used[i]:
                    path.append(i)
                    used[i] = True
                    dfs(i + 1)
                    path.pop()
                    used[i] = False
        
        dfs()
        return ans
        