# Source : https://leetcode.cn/problems/sum-root-to-leaf-numbers/description/
# Author : Yanan Wang
# Date   : 2023-08-29

# 对于二叉树问题，一个非常好用的方法：当遍历到某一个结点时，想清楚该结点要做的事情
#          4
#      9       0
#   5     1
#        
#         假设遍历到了结点9，那么需要知道前驱和4，然后配合本结点的值，求出49
#         再将49传递到结点5和结点1，返回两个数字求出和，返回给上个结点。
#      这就是一个结点需要做的事情，那这就是函数体
#      根据函数体需要的事情，那么就能知道函数头需要一个返回值（树之和）和一个参数（树之根）
#      递归出口就是叶子结点         

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, root, preSum):
        base = preSum * 10 + root.val
        if not root.left and not root.right:
            return base
        ans = 0
        if root.left:
           ans += self.dfs(root.left, base)
        if root.right:
           ans += self.dfs(root.right, base)
        return ans 

    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        return self.dfs(root, 0)