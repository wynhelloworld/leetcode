# Source : https://leetcode.cn/problems/kth-smallest-element-in-a-bst/description/
# Author : Yanan Wang
# Date   : 2023-08-30

# 二叉搜索树的中序遍历是严格递增的，那么按照这一规律，可以设置一个cnt和ans
# 在中序遍历的过程中cnt--，当cnt==0时返回ans=root.val

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        ans = 0
        def dfs(root):
            nonlocal k
            if k == 0 or not root:
                return
            dfs(root.left)
            k -= 1
            if (k == 0):
                nonlocal ans
                ans = root.val
                return
            dfs(root.right)    

        dfs(root)
        return ans        