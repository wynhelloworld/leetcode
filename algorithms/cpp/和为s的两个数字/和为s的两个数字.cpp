// Source : https://leetcode.cn/problems/he-wei-sde-liang-ge-shu-zi-lcof/
// Author : Yanan Wang
// Date   : 2023-07-28

/**
 * 这道题很容易想到暴力解法，最终的时间复杂度是O(N^2)
 * 但本道题给出的数组是有序的，有序数组最先想到的点就应该是二分和双指针
 * 本题采用双指针，left和right分别指向nums的开始和结束
 *           nums[10, 26, 30, 31, 47, 60]
 *                ⬆                   ⬆
 *               left                right
 *     当left+right < target时，++left
 *     当left+right > target时，--right
 *     当left+right == target时，return {left, right}
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            if (nums[left] + nums[right] < target) {
                ++left;
            } else if (nums[left] + nums[right] > target) {
                --right;
            } else {
                break;
            }
        }
        return { nums[left], nums[right] };
    }
};