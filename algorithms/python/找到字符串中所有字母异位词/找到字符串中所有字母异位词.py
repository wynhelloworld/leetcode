# Source : https://leetcode.cn/problems/VabMRr/
# Author : Yanan Wang
# Date   : 2023-12-25

class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        cnt = [0] * 26
        for elem in p:
            cnt[ord(elem) - ord('a')] -= 1
        
        ans = []
        left = 0
        right = 0
        while right < len(s):
            x = ord(s[right]) - ord('a')
            cnt[x] += 1
            while cnt[x] > 0:
                y = ord(s[left]) - ord('a')
                cnt[y] -= 1
                left += 1
            if right - left + 1 == len(p):
                ans.append(left)
            right += 1

        return ans