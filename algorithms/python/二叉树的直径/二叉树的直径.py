# Source : https://leetcode.cn/problems/diameter-of-binary-tree/description/
# Author : Yanan Wang
# Date   : 2023-12-29

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.max_diameter = 0
    
    
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.maxDepth(root)
        return self.max_diameter


    def maxDepth(self, root):
        if not root:
            return 0
        left_depth = self.maxDepth(root.left)
        right_depth = self.maxDepth(root.right)
        self.max_diameter = max(self.max_diameter, left_depth + right_depth)
        return 1 + max(left_depth, right_depth)
