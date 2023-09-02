# Source : https://leetcode.cn/problems/permutations-ii/description/
# Author : Yanan Wang
# Date   : 2023-09-02

# 本题比《46. 全排列 I》要多一道剪枝的步骤。
# 假设给出nums = [1, 1, 2, 1], 模仿46题的决策树
#      当第一个位置选1号1的时候，剩下的三个位置是1、1、2在挑
#      当第一个位置选2号1的时候，剩下的三个位置是1、1、2在挑
#      当第一个位置选3号1的时候，剩下的三个位置是1、1、2在挑
#    那么这三种情况就是重复的，在本题中，这三种情况只能取一种，剩下的两种要剪掉。
# 如何剪？
#    首先，用过的元素不能再用，该剪枝在46题的时候用了used，那么本题也要用
#    其次，重复的元素不能再用，可以先将nums进行排序，将重复元素放在一起
#              然后会有两种思考方式：
#                    1、只关心“不合法”分支
#                         i != 0 and nums[i-1] == nums[i] and used[i-1] == False
#                    2、只关心"合法"分支
#                         i == 0 or nums[i-1] != nums[i] or used[i-1] == True
#    所以总的判断条件有两种方式：
#          1、used[i] == True or (i != 0 and nums[i-1] == nums[i] and used[i-1] == False)
#          2、used[i] == False and (i == 0 or nums[i-1] != nums[i] or used[i-1] == True)

class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ans, path, used = [], [], [False for _ in range(len(nums))]
        def dfs(nums):
            if len(path) == len(nums):
                ans.append(path[:])
                return
            for i in range(len(nums)):
                if not used[i] and (0 == i or nums[i - 1] != nums[i] or used[i - 1]):
                    path.append(nums[i])
                    used[i] = True
                    dfs(nums)
                    path.pop()
                    used[i] = False

        dfs(nums)
        return ans