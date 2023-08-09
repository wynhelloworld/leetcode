// Source : https://leetcode.cn/problems/sqrtx/description/
// Author : Yanan Wang
// Date   : 2023-08-09

/**
 * 暴力解法：从1开始遍历，看该数的平方，若等于x则返回该数，若大于x则返回该数-1
 * 优化：从暴力解法能看出，遍历的区间是有序递增的，并且要找的数是小于等于x范围内最右边的数。那么就能够采用二分查找的查找右端点方法。
 */

class Solution {
public:
    int mySqrt(int x) {
        if (0 == x) return 0;
        int left = 1, right = x;
        while (left < right) {
            long long mid = left + (right - left + 1) / 2;
            if (mid * mid <= x) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};