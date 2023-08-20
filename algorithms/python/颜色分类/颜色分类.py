# Source : https://leetcode.cn/problems/sort-colors/description/
# Author : Yanan Wang
# Date   : 2023-08-20

# 用三个指针，将nums划分为四个区域
#  -------------
#  ^     ^     ^
# left   i   right
#
# [0, left)    全部是0
# [left, i)    全部是1
# [i, right]   待检测区域
# (right, n-1] 全部是2

class Solution:
    def sortColors(self, nums: List[int]) -> None:
        n = len(nums)
        i, left, right = 0, 0, n - 1
        while i <= right:
            if nums[i] == 0:
                nums[left], nums[i] = nums[i], nums[left]
                left += 1
                i += 1
            elif nums[i] == 1:
                i += 1
            else:
                nums[i], nums[right] = nums[right], nums[i]
                right -= 1