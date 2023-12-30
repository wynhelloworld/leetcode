# Source : https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
# Author : Yanan Wang
# Date   : 2023-12-30

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        valToIndex = {}
        for i in range(len(inorder)):
            valToIndex[inorder[i]] = i
        return self.build(preorder, 0, len(preorder) - 1, 
                        inorder, 0, len(inorder) - 1, valToIndex)
         
    
    def build(self, preorder, preStart, preEnd, inorder, inStart, inEnd, valToIndex):
        if preStart > preEnd:
            return None

        rootVal = preorder[preStart]
        rootIdx = valToIndex[rootVal]
        root = TreeNode(rootVal)
        leftSize = rootIdx - inStart

        root.left = self.build(preorder, preStart + 1, preStart + leftSize, 
                            inorder, inStart, rootIdx - 1, valToIndex)

        root.right = self.build(preorder, preStart + leftSize + 1, preEnd, 
                            inorder, rootIdx + 1, inEnd, valToIndex)
        return root
