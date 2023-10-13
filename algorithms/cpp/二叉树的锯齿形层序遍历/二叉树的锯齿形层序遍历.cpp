// Source : https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/description/
// Author : Yanan Wang
// Date   : 2023-10-13

/**
 * 在标准的层序遍历过程中，设置一个标志位，根据该标志位来决定tmp是否翻转
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        vector<vector<int>> ans;
        queue<TreeNode *> que;
        que.push(root);
        bool flag = true;
        while (!que.empty()) {
            int size = que.size();
            vector<int> tmp;
            while (size--) {
                TreeNode *node = que.front();
                que.pop();
                tmp.push_back(node->val);
                if (node->left != nullptr) {
                    que.push(node->left);
                }
                if (node->right != nullptr) {
                    que.push(node->right);
                }
            }
            if (!flag) {
                reverse(tmp.begin(), tmp.end());
                flag = true;
            } else {
                flag = false;
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};