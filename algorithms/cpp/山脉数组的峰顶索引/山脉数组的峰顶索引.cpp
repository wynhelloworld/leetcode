// Source : https://leetcode.cn/problems/peak-index-in-a-mountain-array/description/
// Author : Yanan Wang
// Date   : 2023-08-09

/**
 * 本题有很强烈的二段性
 *                    x |
 *                 x    | x 
 *              x       |    x
 *           x          |       x  
 *                a段       b段
 *     可以把nums分成a、b两段
 *         a段中：arr[i] > arr[i - 1]
 *         b段中：arr[i] < arr[i - 1]
 *     那么，根据这个二段性，就可以利用二分查找解本题。
 */

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 1, right = arr.size() - 2;
        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            if (arr[mid] > arr[mid - 1]) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};