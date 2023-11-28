// Source : https://leetcode.cn/problems/sum-root-to-leaf-numbers/description/
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
    int dfs(TreeNode *root, int pre_sum) {
        int base = pre_sum * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            return base;
        }
        int left_val = 0;
        if (root->left != nullptr) {
            left_val = dfs(root->left, base);
        } 
        int right_val = 0;
        if (root->right != nullptr) {
            right_val = dfs(root->right, base);
        }
        return left_val + right_val;
    }
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};