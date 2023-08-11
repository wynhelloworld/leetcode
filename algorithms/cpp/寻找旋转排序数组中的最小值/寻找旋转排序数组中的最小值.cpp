// Source : https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/description/
// Author : Yanan Wang
// Date   : 2023-08-11

/**
 * 本题把数组形象化一点就变成了如下所示：
 *          +｜ 
 *        +  ｜
 *      +    ｜
 *    -------｜--------
 *           ｜    +     
 *           ｜  +     
 *           ｜+
 *    分成了两段，左边一段严格递增，右边一段严格递增，但同时左边一段的数全部大于右边一段的数。
 *    那么，如果要找最小值，假设选中了一个数nums[i]，它位于左段，那么它肯定不是最小的数，但如果它位于右段，则有可能是最小的数。
 *    所以，根据以上二段性，就能够使用二分查找方法来解决本题。
 *  关键点：如何判断一个数处于哪一段，有两种方法
 *         1、是根据nums[0]来判断，若数nums[i] >= nums[0]，则nums[i]一定处于左段，反之若nums[i] < nums[0]，则nums[i]一定处于右段。
 *         2、是根据nums[nums.size() - 1]来判断，若数nums[i] > nums[nums.size() - 1]，则nums[i]一定处于左段，反之若nums[i] <= nums[nums.size() - 1]，则nums[i]一定处于右段。
 *         如何选择以上两种判断方法呢？
 *            因为本题是求最小值，那么选用方法二最好，因为left和right的区间范围是不断的往右段的下方移动的，即出循环时就是答案。
 *            但若采用方法一也可以，但是要先求最大值，因为一般情况，最大值后面的就是最小值，但有特例"给定的nums是全部完全递增的，不分段的"，在这种情况下，返回nums[0]即可。           
 */

class Solution {
public:
    int findMin(vector<int>& nums) {
        // 方法一
        // int left = 0, right = nums.size() - 1, key = nums[nums.size() - 1];
        // while (left < right) {
        //     int mid = left + (right - left) / 2;
        //     if (nums[mid] > key) {
        //         left = mid + 1;
        //     } else {
        //         right = mid;
        //     }
        // }
        // return nums[left];
        // 方法二
        int left = 0, right = nums.size() - 1, key = nums[0];
        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            if (nums[mid] >= key) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        if (left == nums.size() - 1) return nums[0];
        return nums[left + 1];
    }
};