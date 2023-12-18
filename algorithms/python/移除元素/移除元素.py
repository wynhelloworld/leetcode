# Source : https://leetcode.cn/problems/remove-element/description/
# Author : Yanan Wang
# Date   : 2023-12-18

class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        slow = 0
        fast = 0
        while fast < len(nums):
            if nums[fast] != val:
                nums[slow] = nums[fast]
                slow += 1
            fast += 1
        
        return slow