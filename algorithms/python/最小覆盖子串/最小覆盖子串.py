# Source : https://leetcode.cn/problems/M1oyTv/description/
# Author : Yanan Wang
# Date   : 2023-12-25

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        kind = 0
        base = [0] * 128
        for elem in t:
            if base[ord(elem)] == 0:
                kind += 1
            base[ord(elem)] += 1

        ans_begin = 0
        ans_end = -1
        ans_len = float('inf')
        left = right = cnt = 0
        win = [0] * 128
        while right < len(s):
            win[ord(s[right])] += 1            
            if win[ord(s[right])] == base[ord(s[right])]:
                cnt += 1
            while cnt == kind:
                if ans_len > right - left + 1:
                    ans_len = right - left + 1
                    ans_begin = left
                    ans_end = right
                if win[ord(s[left])] == base[ord(s[left])]:
                    cnt -= 1
                win[ord(s[left])] -= 1
                left += 1
            right += 1    
            
        return s[ans_begin: ans_end + 1] if ans_len != float('inf') else ""     
