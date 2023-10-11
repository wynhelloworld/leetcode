// Source : https://leetcode.cn/problems/add-binary/description/
// Author : Yanan Wang
// Date   : 2023-10-11

/**
 * 就像小学的时候学数字加法一样，这里用代码模拟这个过程。
 *       1 0 1 0
 *     +     
 *           1 1
 *    ------------
 *       1 1 0 1          
 */

class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int carry = 0;
        int i = a.size() - 1;
        int j = b.size() - 1;
        while (i >= 0 || j >= 0 || carry != 0) {
            if (i >= 0) {
                carry += a[i--] - '0';
            }
            if (j >= 0) {
                carry += b[j--] - '0';
            }
            ans += (carry % 2) + '0';
            carry /= 2;
        }       
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
