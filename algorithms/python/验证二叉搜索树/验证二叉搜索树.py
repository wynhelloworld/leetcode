# Source : https://leetcode.cn/problems/validate-binary-search-tree/description/
# Author : Yanan Wang
# Date   : 2023-08-30

# 二叉搜索树的中序遍历是严格递增的，按照这一规律，可以设置一个全局变量prev
# 当在遍历当前节点的时候，prev一定是严格小于当前节点的，否则返回False

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        prev = float('-inf')
        def dfs(root):
            if not root:
                return True
            if not dfs(root.left):
                return False
            nonlocal prev
            if prev >= root.val:
                return False
            prev = root.val
            if not dfs(root.right):
                return False
            return True

        return dfs(root)