// Source : https://leetcode.cn/problems/search-insert-position/description/
// Author : Yanan Wang
// Date   : 2023-08-09

/**
 * 本题，就是在查找小于等于target的区间内的最左端，可以采用二分查找的查找左端点方法。
 */

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        if (nums[left] < target) return left + 1;
        return left;
    }
};