// Source : https://leetcode.cn/problems/minimum-size-subarray-sum/description/
// Author : Yanan Wang
// Date   : 2023-07-31

/**
 * 本题若采用暴力法：时间复杂度为O(n^2)
 *              right
 *               ⬇
 *          nums[2, 3, 1, 2, 4, 3]
 *               ⬆   
 *              left   
 *          当left选中时，right向右一遍遍历，一遍记录和，直到和>=target时，记录下长度，当right向右遍历完时，left向右移动。这样一直遍历，便是暴力法。
 *          但其实，上面的方法中，有两处可以优化的地方：
 *                 1、由于元素全是正整数，所以只要元素相加，那么和必定增大，当right向右遍历第一次找到和>=target时，就无需再向右遍历了。
 *                 2、当找到和>=target时，重新遍历，left向右移动，但right无需变动，因为此时right和left之间的和仅为上一次的和减去nums[left]。
 *          上面这两点优化使得整个算法称为“同向双指针”，俗称“滑动窗口”。 
 */

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), sum  = 0, len = INT_MAX;
        for (int left = 0, right = 0; right < n; ++right) {
            sum += nums[right];
            while (sum >= target) {
                len = min(len, right - left + 1);
                sum -= nums[left++];
            }        
        }
        return (len == INT_MAX ? 0 : len);
    }
};