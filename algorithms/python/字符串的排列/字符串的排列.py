# Source : https://leetcode.cn/problems/permutation-in-string/description/
# Author : Yanan Wang
# Date   : 2023-12-22

class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False
        cnt = [0] * 26
        for c in s1:
            cnt[ord(c) - ord('a')] -= 1
        left = 0
        right = 0
        while right < len(s2):
            x = s2[right]
            cnt[ord(x) - ord('a')] += 1
            while cnt[ord(x) - ord('a')] > 0:
                y = s2[left]
                cnt[ord(y) - ord('a')] -= 1
                left += 1
            if right - left + 1 == len(s1):
                return True
            right += 1

        return False