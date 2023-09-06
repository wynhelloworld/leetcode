# Source : https://leetcode.cn/problems/letter-case-permutation/description/
# Author : Yanan Wang
# Date   : 2023-09-06

# 该题先画一颗决策树，然后根据决策树，再利用全局变量ans和path即可解答本题
#              当递归到数字时，直接将数字插进去递归下一层
#              当递归到字母时，分两种情况递归：1、不转变大小写  2、转变大小写

class Solution:
    def letterCasePermutation(self, s: str) -> List[str]:
        ans, path = [], []
        def dfs(index = 0):
            if len(s) == index:
                ans.append(''.join(path))
                return
            if s[index].isalpha():
                if s[index].islower():
                    path.append(s[index].upper())
                else:
                    path.append(s[index].lower())
                dfs(index + 1)
                path.pop()
            path.append(s[index])
            dfs(index + 1)
            path.pop()

        dfs()
        return ans