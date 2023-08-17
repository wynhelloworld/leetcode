// Source : https://leetcode.cn/problems/counting-bits/description/
// Author : Yanan Wang
// Date   : 2023-08-17

/**
 * n & (n - 1)可以获取到n的最低位的那个1
 * eg：
 *        n   0 1 0 1 1
 *       n-1  0 1 1 0 0
 *        &  ----------- 
 *            0 1 0 0 0 
 */
 
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        for (int i = 1; i <= n; ++i) {
            int cnt = 0, tmp = i;
            while (tmp) {
                tmp &= (tmp - 1);
                ++cnt;
            }
            ans[i] = cnt;
        }
        return ans;
    }
};