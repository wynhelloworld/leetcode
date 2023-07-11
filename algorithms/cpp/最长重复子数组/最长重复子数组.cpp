// Source : https://leetcode.cn/problems/maximum-length-of-repeated-subarray/
// Author : Yanan Wang
// Date   : 2023-07-11

/**
 * 动态规划类题目的一般步骤：
 *    1. 状态表示
 *         设dp[i][j]表示以nums1[i]结尾并且nums2[j]结尾的所有公共子数组的最长长度。
 *    2. 状态转移方程
 *         如果nums1[i] == nums2[j], 那么dp[i][j] = dp[i - 1][j - 1] + 1;
 *         如果nums1[i] != nums2[j], 那么dp[i][j] = 0;
 *    3. 初始化
 *         多开辟一行和一列, 但当nums1或者nums2为空时,公共子数组的长度就为0, 所以初始化为0
 *    4. 填表顺序
 *         从左向右, 从上向下
 *    5. 返回值
 *         dp中的最大值
 */

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        int result = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                }
                result = max(result, dp[i][j]);
            }
        }
        return result;
    }
};