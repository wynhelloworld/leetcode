// Source : https://leetcode.cn/problems/uncrossed-lines/
// Author : Yanan Wang
// Date   : 2023-07-08

/**
 * 动态规划类题目的一般步骤：
 *    1. 状态表示
 *         设dp[i][j]表示nums1在[0,i]区间以及nums2在[0,j]区间上的最大连线数。
 *    2. 状态转移方程
 *         if (nums1[i] == nums2[j]) { dp[i][j] = dp[i - 1][j - 1] + 1; }
 *         else { dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]); }
 *    3. 初始化
 *         多开辟一行和一列，初始化为0。
 *    4. 填表顺序
 *         从左到右，从上到下。
 *    5. 返回值
 *         dp的最后一个值。
 */

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        return dp[n1][n2];
    }
};