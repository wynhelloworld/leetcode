// Source : https://leetcode.cn/problems/find-peak-element/description/
// Author : Yanan Wang
// Date   : 2023-08-10

/**
 * 当nums[i] > nums[i + 1]时，在[0, i]区间上一定有峰值
 * 当nums[i] < nums[i + 1]时，在[i + 1, nums.size() - 1]区间上一定有峰值
 * 由于以上二段性，所以采用二分查找算法即可
 */

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid + 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};