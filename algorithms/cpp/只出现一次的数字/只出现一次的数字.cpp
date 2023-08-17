// Source : https://leetcode.cn/problems/single-number/description/
// Author : Yanan Wang
// Date   : 2023-08-17

/**
 * ^运算有以下特性：
 *       相同为0，相异为1
 *       a ^ 0 == a
 *       a ^ (b ^c) == (a ^ b) ^ c
 * 根据以上特性，使得^运算能够“消消乐”，也就是一群元素^时，若其中有偶数个重复元素，那么这偶数个重复元素会^成0 
 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (auto &x : nums) ans ^= x;
        return ans;
    }
};