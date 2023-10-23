// Source : https://leetcode.cn/problems/assign-cookies/description/
// Author : Yanan Wang
// Date   : 2023-10-23

/**
 * 本题的贪心策略就是: 用最小尺寸的饼干去满足最小胃口的孩子
 */

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans = 0;
        int si = 0, gi = 0;
        while (si < s.size() && gi < g.size()) {
            if (s[si] >= g[gi]) {
                ++gi;
                ++ans;
            }
            ++si;
        }
        return ans;
    }
};