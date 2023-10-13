// Source : https://leetcode.cn/problems/n-ary-tree-level-order-traversal/description/ 
// Author : Yanan Wang
// Date   : 2023-10-13

/**
 * 用一个队列，来保存每一层的节点
 *      具体流程如下：
 *          先将头节点入队，此时队列中的元素就是N叉树的第一行
 *          将队头出队，并依次将该队头的所有子节点入队，此时队列中的元素就是N叉树的第二行
 *          依次将队头出队，并依次将该队头的所有子节点入队，此时队列中的元素就是N叉树的第三行
 *          . . . . . .
 *      根据以上流程，可以发现，队列中的元素都是黏在一起的，根本无法区分行与行之间的节点，
 *      所以用一个变量记录队列中的元素数量，根据元素数量就能区分队列中的行与行。
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr) {
            return {};
        }
        vector<vector<int>> ans;
        queue<Node *> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> tmp;
            while (size--) {
                Node *node = que.front();
                que.pop();
                tmp.push_back(node->val);
                for (auto &children : node->children) {
                    que.push(children);
                }
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
