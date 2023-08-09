// Source : https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/
// Author : Yanan Wang
// Date   : 2023-08-09

/**
 * 求左端点:
 *             [1, 2, 3, 4, 4, 4, 5, 6]         t = 4
 *             [ 小于t ]  [  大于等于t  ]
 *                x区          y区
 *       循环体：
 *             当nums[mid] < t时，由于nums[mid]肯定处在x区，那么left = mid + 1;
 *             当nums[mid] >= t时，由于nums[mid]肯定处在y区，但不知道nums[mid]究竟是==t还是>t，所以只能right = mid;
 *       循环条件：
 *             只能是left < right，而不能是left <= right
 *             nums有三种情况：
 *                    1、有结果（正常情况）
 *                    2、全部 > t（极端情况）
 *                    2、全部 < t（极端情况）
 *             在第一种情况下：如果left < right，那么最终退出循环时，left==right，此时判断nums[left] == target即可；
 *                           如果left <= right，那么当left == right时，由于循环体中的right=mid，所以可能会导致死循环。
 *             在剩余两种情况下：如果left < right，那么最终退出循环时，left==right，此时判断nums[left] == target即可；
 *        求mid：
 *             求mid有两种方法：
 *                    1、mid = left + (right - left) / 2;       偶数时，求出的结果为中间两数靠左的那个
 *                    2、mid = left + (right - left + 1) / 2;   偶数时，求出的结果为中间两数靠右的那个
 *             在求左端点时，由于循环体中的right=mid，所以求mid时，如果求靠右的，可能会导致死循环，所以只能使用方法一；
 * 求右端点：
 *             [1, 2, 3, 4, 4, 4, 5, 6]         t = 4
 *             [     小于等于    ] [大于t]
 *                     x区         y区
 *       循环体：
 *             和上面相反即可
 *       循环条件：
 *             和上面保持一致
 *       求mid：
 *             和上面相反即可 
 */

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1, -1};
        // 求左端点
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        if (nums[left] != target) return {-1, -1};
        int ansL = left;
        // 求右端点
        left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            if (nums[mid] <= target) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        int ansR = left;
        return {ansL, ansR};
    }
};