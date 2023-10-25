// Source : https://leetcode.cn/problems/merge-intervals/description/ 
// Author : Yanan Wang
// Date   : 2023-10-25

/**
 * 先按左端点将intervals进行排序,
 * 然后将intervals中的第一个集合放入ans中,
 * 再然后遍历intervals中的其它集合, 若set[0] > ans.back()[1], 则表示set与ans中的集合无交集
 *                              反之, 有交集, 更改ans.back()[1]为两交集右端点的最大值
 */

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for (auto &set : intervals) {
            if (ans.empty() || ans.back()[1] < set[0]) {
                ans.push_back(move(set));
            } else {
                ans.back()[1] = max(ans.back()[1], set[1]);
            }
        }
        return ans;
    }
};