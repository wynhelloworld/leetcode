# Source : https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/description/
# Author : Yanan Wang
# Date   : 2023-12-29

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        if not root:
            return 
        
        self.flatten(root.left)
        self.flatten(root.right)
        
        left = root.left
        right = root.right

        root.left = None
        root.right = left

        cur = root
        while cur.right:
            cur = cur.right
        cur.right = right
