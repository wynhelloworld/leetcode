// Source : https://leetcode.cn/problems/sort-the-people/
// Author : Yanan Wang
// Date   : 2023-10-20

/**
 * 本题有很多种方法: pair绑定法、hash映射法、排序下标法等.
 *      但前两种方法都有空间的消耗, 第三种无
 * 排序下标法:
 *      用index数组, 存储下标, 然后根据heights中的值进行降序排序, 
 *      排完序后, index里的下标对应到heights中的值, 就是降序的.
 */

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = heights.size();
        vector<int> index(n);
        iota(index.begin(), index.end(), 0);
        
        sort(index.begin(), index.end(), [&](int lhs, int rhs){
            return heights[lhs] > heights[rhs];
        });

        vector<string> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = names[index[i]];
        }
        return ans;
    }
};