# Source : https://leetcode.cn/problems/binary-tree-pruning/description/
# Author : Yanan Wang
# Date   : 2023-08-29

# 当遍历到一个结点时，如何判断该结点是否被释放：
#           当该结点的左子树为空，右子树也为空，并且该结点为0时，会被释放。（函数体）

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pruneTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root:
            return None
        root.left = self.pruneTree(root.left)
        root.right = self.pruneTree(root.right)
        if root.val == 0 and not root.left and not root.right:
            return None
        return root