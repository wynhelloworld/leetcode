// Source : https://leetcode.cn/problems/evaluate-boolean-binary-tree/description/
// Author : Yanan Wang
// Date   : 2023-11-28

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) {
            return root->val;
        }       
        int op = root->val;
        int left_val = evaluateTree(root->left);
        int right_val = evaluateTree(root->right);
        return op == 2 ? (left_val || right_val) : (left_val && right_val); 
    }
};