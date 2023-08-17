// Source : https://leetcode.cn/problems/single-number-ii/description/
// Author : Yanan Wang
// Date   : 2023-08-17

/**
 * 根据题意，可知nums中有3n + 1个元素，
 *    这些元素的同一位上的所有情况为：
 *                        3(n-x)个0  3x个1   1个0         相加%3 == 0
 *                        3(n-x)个0  3x个1   1个1         相加%3 == 1
 *    看这些相同位上的所有数加起来%3得到的结果，就能够知道那个只出现一次的数字该位上的数字是1还是0
 * 以上是求出了只出现一次的数字的某一个bit位，那么仅需循环32次，就能够求出完整的结果。
 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            int bit = 0;
            for (auto &x : nums) 
                bit += (x >> i) & 1;
            ans |= (bit % 3) << i;
        }
        return ans;
    }
};