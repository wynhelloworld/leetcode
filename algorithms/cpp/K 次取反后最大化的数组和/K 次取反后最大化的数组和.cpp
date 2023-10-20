// Source : https://leetcode.cn/problems/maximize-sum-of-array-after-k-negations/description/
// Author : Yanan Wang
// Date   : 2023-10-20

/**
 * 本题, 先统计出负数的个数negatives
 *      若 negatives > k, 就将最小的那几个负数取反
 *      若 negatives == k, 就将全部的负数取反
 *      若 negatives < k, 就将全部的负数取反, 然后看k - negatives 的奇偶性
 *              若 为偶数, 就什么也不做
 *              若 为奇数, 就将nums中最小的那个数取反
 */

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int negatives = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < 0) {
                ++negatives;
            }
        }        
        if (negatives >= k) {
            for (int i = 0; i < k; ++i) {
                nums[i] *= -1;
            }
        } else {
            for (int i = 0; i < negatives; ++i) {
                nums[i] *= -1;
            }
            if ((k - negatives) % 2 != 0) {
                sort(nums.begin(), nums.end());
                nums[0] *= -1;
            } 
        }
        int ans = 0;
        for (auto &x : nums) {
            ans += x;
        }
        return ans;
    }
};