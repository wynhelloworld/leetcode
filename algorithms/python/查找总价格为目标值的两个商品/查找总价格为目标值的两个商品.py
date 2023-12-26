# Source : https://leetcode.cn/problems/he-wei-sde-liang-ge-shu-zi-lcof/description/
# Author : Yanan Wang
# Date   : 2023-12-26

class Solution:
    def twoSum(self, price: List[int], target: int) -> List[int]:
        left = 0
        right = len(price) - 1
        while left < right:
            if price[left] + price[right] < target:
                left += 1
            elif price[left] + price[right] > target:
                right -= 1
            else:
                break
        return price[left], price[right]