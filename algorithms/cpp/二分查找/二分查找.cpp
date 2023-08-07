// Source : https://leetcode.cn/problems/binary-search/description/
// Author : Yanan Wang
// Date   : 2023-08-07

/**
 * 二分查找并非仅仅是有序的时候能用，而是在有“二段性”的时候用，所以有时即使无序但符合“二段性”这个特点也能用二分查找。
 * 简单二分查找模版：
 *      while (left <= right) {
 *          int mid = left + (right - left) / 2;
 *          if (. . .) {
 *              left = mid + 1;
 *          } else if (. . .) {
 *              right = mid - 1;
 *          } else {
 *              return . . .;
 *          }
 *      }
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};