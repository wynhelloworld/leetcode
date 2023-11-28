// Source : https://leetcode.cn/problems/kth-smallest-element-in-a-bst/description/
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
    int ans = 0;
    int K;
    void dfs(TreeNode * root) {
        if (K == 0 || root == nullptr) {
            return;
        }
        dfs(root->left);
        if (--K == 0) {
            ans = root->val;
            return;
        }
        dfs(root->right); 
    }
    int kthSmallest(TreeNode* root, int k) {
        K = k;
        dfs(root);
        return ans; 
    }
};