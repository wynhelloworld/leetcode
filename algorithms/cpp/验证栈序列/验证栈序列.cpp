// Source : https://leetcode.cn/problems/validate-stack-sequences/description/
// Author : Yanan Wang
// Date   : 2023-10-12

/**
 * 在遍历过程中用栈进行模拟
 *      用i标记poped中元素
 *      每次往栈中push一个pushed中的元素时，就检查栈顶元素和poped中的元素是否相等
 *          若相等，就删除栈顶元素，++i
 *      最后看栈是否为空，为空return true，为非空return false
 */

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int i = 0;
        for (auto &x : pushed) {
            stk.push(x);
            while (!stk.empty() && stk.top() == popped[i]) {
                stk.pop();
                ++i;
            }
        }
        return stk.empty();
    }
};