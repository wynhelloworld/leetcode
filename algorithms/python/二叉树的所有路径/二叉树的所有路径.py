# Source : https://leetcode.cn/problems/binary-tree-paths/description/
# Author : Yanan Wang
# Date   : 2023-08-31

# 本题用两个全局变量ans和path
# 在二叉树前序遍历过程中，用path记录下所有节点，当遇到叶子结点时，将path插入ans中
#                                        当进行回溯时，pop掉path中的尾元素
# 但本题由于要操作字符串并且还有'->'，所以用path进行“恢复现场”比较麻烦，所以将全局变量path改为函数参数

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        ans = []
        def dfs(root, path = ''):
            if not root:
                return
            path += str(root.val)
            if not root.left and not root.right:
                nonlocal ans
                ans.append(path)
                return
            path += '->'
            dfs(root.left, path)
            dfs(root.right, path)

        dfs(root)
        return ans
