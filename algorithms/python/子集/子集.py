# Source : https://leetcode.cn/problems/subsets/description/
# Author : Yanan Wang
# Date   : 2023-09-01

# 解法一：
#        画决策树：根据每一个元素选或者不选      [1,2,3]
#                         开始
#                      ---------
#                     |         |
#                    选1       不选1
#                    ----      -----
#                   |    |    |     |
#                  选2 不选2  选2   不选2
#                 ....
#              123,12,   13,1   23,2   3,[]
#         用全局变量ans放入最终答案，用全局变量path记录递归最深处的答案，当到了递归出口时append进ans。
# 解法二：
#         画决策树：根据元素的数量
#                          开始   []
#                      -----------
#                      |    |    |
#                      1    2    3
#                    ----- ---
#                    |   |   |
#                   12  13  23 
#                    |
#                  123   
#         
class Solution:
    # 解法一
    # def subsets(self, nums: List[int]) -> List[List[int]]:
    #     ans, path = [], []
    #     def dfs(nums, i = 0):
    #         if i == len(nums):
    #             ans.append(path[:])
    #             return
    #         # 选择当前元素
    #         path.append(nums[i])
    #         dfs(nums, i + 1)
    #         # 不选择当前元素，但由于前面已经选择过当前元素了，所以现在要恢复现场
    #         path.pop()
    #         dfs(nums, i + 1)
        
    #     dfs(nums)
    #     return ans

    # 解法二
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ans, path = [], []
        def dfs(nums, pos = 0):
            ans.append(path[:])
            for i in range(pos, len(nums)):
                path.append(nums[i])
                dfs(nums,i + 1)
                # 恢复现场
                path.pop()
        
        dfs(nums)
        return ans
