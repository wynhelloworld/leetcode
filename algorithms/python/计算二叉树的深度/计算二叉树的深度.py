# Source : https://leetcode.cn/problems/er-cha-shu-de-shen-du-lcof/description/
# Author : Yanan Wang
# Date   : 2023-12-29

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def calculateDepth(self, root: Optional[TreeNode]) -> int:
        def maxDepth(root, depth):
            if not root:
                return 
            nonlocal ans
            ans = max(ans, depth)
            maxDepth(root.left, depth + 1)
            maxDepth(root.right, depth + 1)

        ans = 0
        maxDepth(root, 1)
        return ans
