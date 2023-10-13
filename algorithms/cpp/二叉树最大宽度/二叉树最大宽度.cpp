// Source : https://leetcode.cn/problems/maximum-width-of-binary-tree/description/ 
// Author : Yanan Wang
// Date   : 2023-10-13

/**
 *      首先能想到的解法就是：标准层序遍历，然后将nullptr也通通入队，但这样理论上可行，但实际上不行，
 *   因为树的层数可能非常高，本题给的节点范围是[1, 3000]，那么树的最高层数就为1500，节点数量就为2^1500-1个
 *      所以，换一种解法：
 *          用队列存储pair<node, index>，每层队列，取出队头和队尾的index相减+1就是该层的宽度。
 *          本题也可以用数组模拟队列，因为考虑到可能有的语言无法取到队列的队尾元素。
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
    int widthOfBinaryTree(TreeNode* root) {
        uint64_t ans = 0;
        vector<pair<TreeNode *, uint64_t>> arr;
        arr.emplace_back(root, 1);
        while (!arr.empty()) {
            vector<pair<TreeNode *, uint64_t>> tmp;
            for (auto &[node, index] : arr) {
                if (node->left != nullptr) {
                    tmp.emplace_back(node->left, index * 2);
                }
                if (node->right != nullptr) {
                    tmp.emplace_back(node->right, index * 2 + 1);
                }
            }
            ans = max(ans, arr.back().second - arr.front().second + 1);
            arr = move(tmp);
        }
        return ans;
    }
};