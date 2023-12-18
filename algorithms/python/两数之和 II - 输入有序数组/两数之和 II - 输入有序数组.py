# Source : https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/description/
# Author : Yanan Wang
# Date   : 2023-12-18

class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        left = 0
        right = len(numbers) - 1
        while left < right:
            if numbers[left] + numbers[right] < target:
                left += 1
            elif numbers[left] + numbers[right] > target:
                right -= 1
            else:
                return left + 1, right + 1
        
        return []