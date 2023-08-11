// Source : https://leetcode.cn/problems/que-shi-de-shu-zi-lcof/description/
// Author : Yanan Wang
// Date   : 2023-08-11

/**
 * 本题有很多解法，就像官方题解给出的四种，但这些时间复杂度都是O(N)的，但其实本题还可以用二分查找算法来解决。
 *           nums [0, 1, 2, 3, 4, 6, 7, 8, 9]
 *           idx   0  1  2  3  4  5  6  7  8
 *           整体观察nums和idx，可以发现区间[0,4]内的nums[idx] == idx，而区间[5, 8]内的nums[idx] != idx;
 *           根据此二段性，可以得出：
 *                       若nums[i] == i, 则nums[i]一定不是缺失的数字                      
 *                       若nums[i] != i, 则nums[i]有可能是缺失的数字
 *           所以就可以采用二分查找算法来解决。                      
 */

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == mid) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[left] == left ? ++left : left;
    }
};