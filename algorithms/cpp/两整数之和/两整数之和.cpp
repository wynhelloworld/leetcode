// Source : https://leetcode.cn/problems/sum-of-two-integers/description/
// Author : Yanan Wang
// Date   : 2023-08-17

/**
 * a ^ b有一个特性：无进位相加。也就是说会将a和b相加起来但不会进位，
 * 那么只需再将进位加上就能够准确的求出a+b。
 * 进位的求法：(a & b) << 1
 * 所以 a + b = a ^ b ^ ((a & b) << 1);
 * 但同时有可能进位在和a ^ b相加的时候又产生了进位，所以正确的做法是一个循环，当进位为0的时候退出循环。
 */

class Solution {
public:
    int getSum(int a, int b) {
        while (b) {
            int carry = (a & b) << 1;
            a ^= b;
            b = carry;
        }
        return a;
    }
};