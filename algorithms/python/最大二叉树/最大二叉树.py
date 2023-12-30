# Source : https://leetcode.cn/problems/maximum-binary-tree/description/
# Author : Yanan Wang
# Date   : 2023-12-30

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> Optional[TreeNode]:
        def build(nums, left, right):
            if left > right:
                return None
            maxVal = nums[left]
            maxIdx = left
            for i in range(left, right + 1):
                if maxVal < nums[i]:
                    maxVal = nums[i]
                    maxIdx = i
            root = TreeNode(maxVal)
            root.left = build(nums, left, maxIdx - 1)
            root.right = build(nums, maxIdx + 1, right)
            return root

        return build(nums, 0, len(nums) - 1)        
