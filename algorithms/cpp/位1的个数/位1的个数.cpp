// Source : https://leetcode.cn/problems/number-of-1-bits/description/
// Author : Yanan Wang
// Date   : 2023-08-17

/**
 * n & (n - 1)可以获取到n的最低位的那个1
 * eg：
 *        n   0 1 0 1 1
 *       n-1  0 1 1 0 0
 *        &  ----------- 
 *            0 1 0 0 0 
 */

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while (n) {
            n &= (n - 1);
            ++cnt;
        }
        return cnt;
    }
};