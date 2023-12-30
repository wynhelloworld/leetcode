# Source : https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/
# Author : Yanan Wang
# Date   : 2023-12-30

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def constructFromPrePost(self, preorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        valToIndex = {}
        for idx, val in enumerate(postorder):
            valToIndex[val] = idx
        return self.build(preorder, 0, len(preorder) - 1,
                        postorder, 0, len(postorder) - 1, valToIndex)
    

    def build(self, preorder, preStart, preEnd, postorder, postStart, postEnd, valToIndex):
        if preStart > preEnd:
            return None
        if preStart == preEnd:
            return TreeNode(preorder[preStart])
        
        rootVal = preorder[preStart]
        leftRootVal = preorder[preStart + 1]
        leftRootIdx = valToIndex[leftRootVal]
        leftSize = leftRootIdx - postStart + 1
        root = TreeNode(rootVal)
        
        root.left = self.build(preorder, preStart + 1, preStart + leftSize,
                            postorder, postStart, leftRootIdx, valToIndex)

        root.right = self.build(preorder, preStart + leftSize + 1, preEnd,
                            postorder, leftRootIdx + 1, postEnd - 1, valToIndex)

        return root
