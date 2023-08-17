// Source : https://leetcode.cn/problems/single-number-iii/description/
// Author : Yanan Wang
// Date   : 2023-08-17

/**
 * 先把所有的数^，能得出一个数字xorsum，xorsum就是最终答案的两个数字^的结果。
 * 现在的问题是如何将上面求出的xorsum分解成最终答案。
 * 由于xorsum肯定不为0，那么肯定有一个bit为1，而这个bit为1的含义就是：最终答案的两个数字的该位比特位不相同。
 * 由于nums中其它偶数个数字的该位比特位不是0就是1，那么就可以根据该比特位将整个nums分为两组：比特位为0的占一组，比特位为1的占一组。
 *       以“0组”举例：该组有2n+1个元素，这些元素的该位都是0，然后将该组元素^起来，这2n个元素就变为0了，就求出最终答案其中的一个了。
 *         “1组”也是同样的道理。      
 */

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorsum = 0;
        for (auto &x : nums) xorsum ^= x;
        int lowbit = xorsum == INT_MIN ? xorsum : xorsum & (-xorsum);
        vector<int> ans(2);
        for (auto &x : nums) {
            if (x & lowbit) 
                ans[0] ^= x;
            else
                ans[1] ^= x;
        }
        return ans;
    }
};