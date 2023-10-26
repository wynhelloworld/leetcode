// Source : https://leetcode.cn/problems/non-overlapping-intervals/description/ 
// Author : Yanan Wang
// Date   : 2023-10-26

/**
 * 先按左端点, 进行升序排序.
 * 记录下第一个右端点
 * 然后开始遍历后边的区间, 若左端点 >= 记录的右端点, 则说明该区间和前面记录的右端点所在区间无重叠.
 *                     反之, 则说明有重叠, 那么这种情况下,就看两区间谁的右端点更靠左, 更靠右的要被移除,
 *                  因为,右端点更靠右的区间与后面区间的重叠几率越大.     
 */

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int ans = 0;
        int right_side = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] >= right_side) {
                right_side = intervals[i][1];
            } else {
                right_side = min(right_side, intervals[i][1]);
                ++ans;
            }
        }
        return ans;
    }
};