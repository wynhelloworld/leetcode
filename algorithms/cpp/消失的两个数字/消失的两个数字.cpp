// Source : https://leetcode.cn/problems/missing-two-lcci/description/
// Author : Yanan Wang
// Date   : 2023-08-17

/**
 * 本题结合了《268. 消失的数字》和《260. 只出现一次的数字 III》
 * 本题有两个集合：
 *         一是从1到N的整数；
 *         二是nums。
 * 但nums == 集合一缺两个数字。
 * 那么如果把集合一和集合二看做一个集合。问题就变为了“有一个集合，其中恰有两个数字出现一次，其余元素均出现两次，找出仅出现一次的两个数字”
 *                                 也就是《260. 只出现一次的数字 III》
 */

class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        int N = nums.size() + 2;
        int xorsum = 0;
        for (int i = 1; i <= N; ++i) xorsum ^= i;
        for (auto &x : nums) xorsum ^= x;
        int lowbit = xorsum == INT_MIN ? xorsum : xorsum & (-xorsum);
        vector<int> ans(2);
        for (int i = 1; i <= N; ++i) {
            if (i & lowbit)
                ans[0] ^= i;
            else
                ans[1] ^= i;
        }
        for (auto &x : nums) {
            if (x & lowbit)
                ans[0] ^= x;
            else
                ans[1] ^= x;
        }
        return ans;
    }
};