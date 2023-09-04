# Source : https://leetcode.cn/problems/generate-parentheses/description/
# Author : Yanan Wang
# Date   : 2023-09-04

# 要确定一个组合是有效的括号组合要满足两个条件：
#     1、'('的数量 == ')'的数量
#     2、从头开始遍历的过程中，'('的数量 >= ')'的数量
# 
# 先画一个决策树，当n==2时
#                          开始
#                        |-----|
#                      选'('  (该情况被剪枝掉，因为不满足上面的条件2)
#                    |-----|
#                  选'('  选')'
#                |-----|   .....
#                     选')' ......
# (该情况被剪枝掉，因为'('的数量大于了n)
# 根据决策树，可以得出，在递归过程中，只有两种情况，然后分别处理即可，再就是根据'('和')'的数量完成剪枝
#                     递归出口就是当')' == n时

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        left, right = 0, 0
        ans, path = [], []
        def dfs():
            nonlocal left, right
            if right == n:
                ans.append(''.join(path))
                return
            # 处理左括号
            if left < n:
                path.append('(')
                left += 1
                dfs()
                path.pop()
                left -= 1
            # 处理右括号
            if right < left:
                path.append(')')
                right += 1
                dfs()
                path.pop()
                right -= 1
            
        dfs()
        return ans