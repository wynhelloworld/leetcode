# Source : https://leetcode.cn/problems/reverse-words-in-a-string/description/ 
# Author : Yanan Wang
# Date   : 2023-12-20

class Solution:
    def reverseWords(self, s: str) -> str:
        s = s.strip()
        i = j = len(s) - 1
        ans = []
        while i >= 0:
            while i >= 0 and s[i] != ' ':
                i -= 1
            ans.append(s[i+1:j+1])
            while i >= 0 and s[i] == ' ':
                i -= 1
            j = i
        return ' '.join(ans)