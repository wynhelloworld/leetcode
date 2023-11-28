// Source : https://leetcode.cn/problems/validate-binary-search-tree/description/ 
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
    long long prev = (long long)INT_MIN - 1;
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        if (!isValidBST(root->left)) {
            return false;
        }
        if (root->val <= prev) {
            return false;
        } 
        prev = root->val;
        if (!isValidBST(root->right)) {
            return false;
        } 
        return true;
    }
};