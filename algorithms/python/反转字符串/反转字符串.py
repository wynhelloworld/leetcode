# Source : https://leetcode.cn/problems/reverse-string/description/
# Author : Yanan Wang
# Date   : 2023-12-19

class Solution:
    def reverseString(self, s: List[str]) -> None:
        left = 0
        right = len(s) - 1
        while left < right:
            s[left], s[right] = s[right], s[left]
            left += 1
            right -= 1

                                    
