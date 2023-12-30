# Source : https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
# Author : Yanan Wang
# Date   : 2023-12-30

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        valToIndex = {}
        for i in range(len(inorder)):
            valToIndex[inorder[i]] = i
        return self.build(postorder, 0, len(postorder) - 1, 
                        inorder, 0, len(inorder) - 1, valToIndex)

    
    def build(self, postorder, postStart, postEnd, inorder, inStart, inEnd, valToIndex):
        if postStart > postEnd:
            return None
        
        rootVal = postorder[postEnd]
        rootIdx = valToIndex[rootVal]
        rightSize = inEnd - rootIdx
        root = TreeNode(rootVal)
        
        root.right = self.build(postorder, postEnd - rightSize, postEnd - 1,
                            inorder, rootIdx + 1, inEnd, valToIndex)

        root.left = self.build(postorder, postStart, postEnd - rightSize - 1, 
                            inorder, inStart, rootIdx - 1, valToIndex)

        return root 
