# Source : https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/
# Author : Yanan Wang
# Date   : 2023-09-03

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        n = len(digits)
        if 0 == n:
            return []
        MP = ['', '', 'abc', 'def', 'ghi', 'jkl', 'mno', 'pqrs', 'tuv', 'wxyz']
        ans, path = [], []
        def dfs(index):
            if len(path) == n:
                ans.append(''.join(path))
                return
            for c in MP[int(digits[index])]:
                path.append(c)
                dfs(index + 1)
                path.pop()
        
        dfs(0)
        return ans
        