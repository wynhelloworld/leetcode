// Source : https://leetcode.cn/problems/multiply-strings/description/
// Author : Yanan Wang
// Date   : 2023-10-11

/**
 * 小学学乘法的时候，一般是这样的
 *           1 2 3
 *     *     4 5 6
 *         ---------
 *           7 3 8
 *     +   6 1 5
 *     + 4 9 2
 * 用代码模拟以上过程，也是可以的，但比较麻烦。
 * 其实还有一种方法
 *           1 2 3
 *     *     4 5 6
 *         ---------
 *           6 12 18
 *        5 10 15        这里都是各自乘各自的
 *      4 8 12        
 *     --------------
 *     4 13 28 27 18     然后把这些数字加起来
 *     --------------
 *     5  6  0  8  8     最后进行进位
 * 该方法和上面方法的区别就是，进位的时机不一样，上面方法在每一次相乘的时候都进行了进位，而下面方法是在最后进位
 */

class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> arr(num1.size() + num2.size() - 1);
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for (int i = 0; i < num1.size(); ++i) {
            for (int j = 0; j < num2.size(); ++j) {
                arr[i + j] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        string ans;
        int carry = 0;
        int cur = 0;
        while (cur < num1.size() + num2.size() - 1 || carry != 0) {
            if (cur < num1.size() + num2.size() - 1) {
                carry += arr[cur++];
            }
            ans.push_back((carry % 10) + '0');
            carry /= 10;
        }
        while (ans.size() > 1 && ans.back() == '0') {
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};