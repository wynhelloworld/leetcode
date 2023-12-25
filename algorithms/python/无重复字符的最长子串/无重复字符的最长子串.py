# Source : https://leetcode.cn/problems/wtcaE1/description/
# Author : Yanan Wang
# Date   : 2023-12-25

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        ans = 0
        cnt = [0] * 128
        left = 0
        right = 0
        while right < len(s):
            x = ord(s[right]) - ord('a')
            cnt[x] += 1
            while cnt[x] > 1:
                y = ord(s[left]) - ord('a')
                cnt[y] -= 1
                left += 1
            ans = max(ans, right - left + 1)
            right += 1
        
        return ans