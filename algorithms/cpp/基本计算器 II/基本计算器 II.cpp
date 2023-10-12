// Source : https://leetcode.cn/problems/basic-calculator-ii/description/ 
// Author : Yanan Wang
// Date   : 2023-10-12

/**
 * 可以在遍历过程中用栈模拟
 *      用一个栈保存表达式中的数字
 *      每个数字该如何进行处理全看它前边的运算符，所以再用一个变量存储当前数字的前一个运算符
 *      当op == '+'时，把num添加到栈中
 *      当op == '-'时，把-num添加到栈中
 *      当op == '*'时，把num乘到栈顶元素上
 *      当op == '/'时，把num除以到栈顶元素上
 *    最后把栈中的元素全部加起来返回答案
 */

class Solution {
public:
    int calculate(string s) {
        vector<int> stk;
        int i = 0, n = s.size();
        char op = '+';
        while (i < n) {
            if (s[i] == ' ') {
                ++i;
            } else if (isdigit(s[i])) {
                int num = 0;
                while (i < n && isdigit(s[i])) {
                    num = num * 10 + (s[i++] - '0');
                }
                if (op == '+') {
                    stk.push_back(num);
                } else if (op == '-') {
                    stk.push_back(-num);
                } else if (op == '*') {
                    stk.back() *= num;
                } else if (op == '/') {
                    stk.back() /= num;
                }
            } else {
                op = s[i++];
            }
        }
        int ans = 0;
        for (auto &x : stk) {
            ans += x;
        }
        return ans;
    }
};