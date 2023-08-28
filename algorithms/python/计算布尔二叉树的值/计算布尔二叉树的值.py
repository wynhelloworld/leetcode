# Source : https://leetcode.cn/problems/evaluate-boolean-binary-tree/description/
# Author : Yanan Wang
# Date   : 2023-08-28

# 题目本身就是一个重复子问题
# 我们可以求出root.left的bool值和root.right的bool值
# 然后看root.val是or还是and 求最终结果返回即可
# 递归出口就是叶子结点，判断root.left或者root.right是否为空即可

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def evaluateTree(self, root: Optional[TreeNode]) -> bool:
        if not root.left:
            return root.val == 1
        leftNums = self.evaluateTree(root.left)
        rightNums = self.evaluateTree(root.right)
        if root.val == 2:
            return leftNums or rightNums
        elif root.val == 3:
            return leftNums and rightNums
        