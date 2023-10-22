// Source : https://leetcode.cn/problems/di-string-match/description/
// Author : Yanan Wang
// Date   : 2023-10-22

/**
 * 本题的贪心策略就是, 每次碰到I的时候, 选目前最小的值
 *                      碰到D的时候, 选目前最大的值
 */

class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        int left = 0, right = n;
        vector<int> ans(n + 1);
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'I') {
                ans[i] = left++;
            } else {
                ans[i] = right--;
            }
        }
        ans[n] = left;
        return ans;
    }
};