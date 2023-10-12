// Source : https://leetcode.cn/problems/decode-string/description/ 
// Author : Yanan Wang
// Date   : 2023-10-12

/**
 * 在遍历过程中用栈进行模拟
 *      由于字符串中包含重复次数k和需要重复的字符串，所以用两个栈分别保存
 *      有如下四种情况：
 *          1、cur == 数字
 *              就把数字添加到数字栈中
 *          2、cur == 字符
 *              就把字符追加到字符串栈顶元素上
 *          3、cur == '['
 *              就把后面的字符串添加到字符串栈中
 *          4、cur == ']'
 *              就把数字栈和字符串栈的栈顶元素拿出来，根据这俩元素构造一个新字符串，追加到栈顶元素上
 *      最后返回栈顶元素
 */

class Solution {
public:
    string decodeString(string s) {
        vector<int> stk_num;
        vector<string> stk_str;
        stk_str.push_back("");
        int i = 0, n = s.size();
        while (i < n) {
            if (isdigit(s[i])) {
                int num = 0;
                while (isdigit(s[i])) {
                    num = num * 10 + (s[i++] - '0');
                }
                stk_num.push_back(num);
            } else if (isalpha(s[i])) {
                string str;
                while (i < n && isalpha(s[i])) {
                    str += s[i++];
                }
                stk_str.back() += str;
            } else if (s[i] == '[') {
                ++i;
                string str;
                while (isalpha(s[i])) {
                    str += s[i++];
                }
                stk_str.push_back(str);
            } else if (s[i] == ']') {
                ++i;
                int num = stk_num.back();
                stk_num.pop_back();
                string str = stk_str.back();
                stk_str.pop_back();
                string newstr;
                while (num--) {
                    newstr += str;
                }
                stk_str.back() += newstr;
            }
        }
        return stk_str.back();
    }
};