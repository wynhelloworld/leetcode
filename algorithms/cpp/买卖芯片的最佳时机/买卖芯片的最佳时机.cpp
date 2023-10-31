// Source : https://leetcode.cn/problems/gu-piao-de-zui-da-li-run-lcof/description/
// Author : Yanan Wang
// Date   : 2023-10-31

/**
 * 动态规划类题目的一般步骤:
 *   1. 状态表示
 *        dp[i][0]表示, 第i天持有股票的最大利润
 *        dp[i][1]表示, 第i天没有股票的最大利润
 *   2. 状态转移方程
 *        dp[i][0] = max(dp[i - 1][0], -prices[i])
 *        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i])
 *   3. 初始化
 *        dp[i][0] = -prices[0]
 *   4. 填表顺序
 *        从左向右
 *   5. 返回值 
 *        dp[n-1][1]
 */

class Solution {
public:
    int bestTiming(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) {
            return 0;
        }
        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][0] = -prices[0];
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }   
        return dp[n - 1][1];         
    }
};