// Source : https://leetcode.cn/problems/missing-number/description/
// Author : Yanan Wang
// Date   : 2023-08-17

/**
 * nums中缺少的元素，正好在其下标中能够找到。
 * 所以只需将nums中的元素和下标^起来，求出的数即最终结果。
 */

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = 0, i = 0;
        for (; i < nums.size(); ++i) 
            ans ^= nums[i] ^ i;
        return ans ^ i;
    }
};