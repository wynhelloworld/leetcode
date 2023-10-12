// Source : https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/description/
// Author : Yanan Wang
// Date   : 2023-10-12

/**
 * 在遍历过程中用栈模拟
 *      当栈顶元素 == 当前遍历元素时，删除掉栈顶元素
 *      当栈顶元素 != 当前遍历元素时，把该元素添加进栈中（栈为空时，也把该元素添加进栈中）
 */

class Solution {
public:
    string removeDuplicates(string s) {
        string ans;
        for (auto &c : s) {
            if (ans.empty() || ans.back() != c) {
                ans.push_back(c);
            } else {
                ans.pop_back();
            }
        }
        return ans;
    }
};