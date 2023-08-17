// Source : https://leetcode.cn/problems/hamming-distance/description/
// Author : Yanan Wang
// Date   : 2023-08-17

/**
 * ^ 的运算规则：相同为0，相异为1（或者，无进位相加）
 * x ^ y可以把x和y上不同的位置变为1，然后再利用n & (n - 1)的特性即可解答本题
 */
 
class Solution {
public:
    int hammingDistance(int x, int y) {
        int tmp = x ^ y;
        int cnt = 0;
        while (tmp) {
            tmp &= (tmp - 1);
            ++cnt;
        }
        return cnt;
    }
};