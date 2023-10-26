// Source : https://leetcode.cn/problems/minimum-number-of-arrows-to-burst-balloons/description/ 
// Author : Yanan Wang
// Date   : 2023-10-26

/**
 * 本题要求的其实是, 最多数量的交集.
 * 先将区间按照左端点进行升序排序
 * 记录下第一个区间的右端点
 * 然后开始遍历后边的区间, 若左端点 > 记录的右端点, 则说明该区间和以记录的右端点所在区间无交集, 此时箭数+1;
 *                      反之, 有交集, 此时, 要更新右端点为两区间最靠左的右端点(寻找最多交集)
 */

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int ans = 1;
        int right_side = points[0][1];
        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] > right_side) {
                right_side = points[i][1];
                ++ans;
            } else {
                right_side = min(right_side, points[i][1]);
            }
        }
        return ans;
    }
};