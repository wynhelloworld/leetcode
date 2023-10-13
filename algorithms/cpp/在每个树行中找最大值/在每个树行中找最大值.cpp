// Source : https://leetcode.cn/problems/find-largest-value-in-each-tree-row/description/ 
// Author : Yanan Wang
// Date   : 2023-10-13

/**
 * 在层序遍历过程中，用一个变量记录每一层的最大值即可。
 */

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
    vector<int> largestValues(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        vector<int> ans;
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty()) {
            int maxval = INT_MIN;
            int size = que.size();
            while (size--) {
                TreeNode *node = que.front();
                que.pop();
                maxval = max(maxval, node->val);
                if (node->left != nullptr) {
                    que.push(node->left);
                }
                if (node->right != nullptr) {
                    que.push(node->right);
                }
            }
            ans.push_back(maxval);
        }
        return ans;
    }
};