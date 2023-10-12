// Source : https://leetcode.cn/problems/backspace-string-compare/description/ 
// Author : Yanan Wang
// Date   : 2023-10-12

/**
 * 分别对字符串进行退格处理，然后比较两字符串是否相等
 * 退格处理：
 *      在遍历过程中用栈模拟
 *          当栈顶元素 == '#'时，删除掉栈顶元素（删除时，栈必须非空）
 *          当栈顶元素 != '#'时，就把当前元素添加进来
 */

class Solution {
public:
    string handler(string &s) {
        string str;
        for (auto &c : s) {
            if (c == '#') {
                if (!str.empty()) {
                    str.pop_back();
                }
            } else {
                str.push_back(c);
            }
        }
        return str;
    }
    bool backspaceCompare(string s, string t) {
        return handler(s) == handler(t);
    }
};