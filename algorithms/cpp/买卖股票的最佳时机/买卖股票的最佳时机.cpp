// Source : https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/
// Author : Yanan Wang
// Date   : 2023-05-27

/**
 * 动态规划类题目的一般步骤：
 *   1. 状态表示
 *        设dp[i][0]为第i天有票状态的最大利润
 *        设dp[i][1]为第i天无票状态的最大利润
 *   2. 状态转移方程
 *   |--------------------------------------------------
 *   |      第i-1天状态      状态转换过程        第i天状态   
 *   |--------------------------------------------------
 *   |     dp[i - 1][0]    第i天什么都不做      dp[i][0]  
 *   |          0          第i天买票           dp[i][0] （由于只能买一次票，所以由无票->有票只能是0->买票）
 *   |--------------------------------------------------
 *   |     dp[i - 1][0]    第i天卖票           dp[i][1]  
 *   |     dp[i - 1][1]    第i天什么都不做      dp[i][1]  
 *   |--------------------------------------------------
 *                           |
 *                           | 推导出状态转移方程
 *                          \./ 
 *    dp[i][0] = max(dp[i - 1][0], -prices[i])
 *    dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i])
 *   3. 初始化
 *        dp[0][0]表示第0天有票，即第0天买票，即等于-prices[0];
 *        dp[0][1]表示第0天无票，即等于0
 *   4. 填表顺序
 *        一起从左向右
 *   5. 返回值
 *        dp[n - 1][0]表示第n天有票，即还有票未卖出，那么肯定不是最大利润
 *        即, return dp[n - 1][1]
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][0] = -prices[0];
        for (int i = 1; i < n; ++i)
        {
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }
        return dp[n - 1][1];
    }
}; 


/**
 * 新增一种贪心解法
 * 本题的贪心解法, 是在暴力解法的基础上进行优化而得出的.
 * 暴力解法:
 *      两层for循环, 外层在范围[1, prices,size())遍历卖出价格, 
 *                  内层在范围[0, i)遍历买入价格,为求一个最低买入价格,
 *                  然后用卖出价格减去最低买入价格更新最大利润. 
 * 贪心解法:
 *      用一层for循环就够了, 没必要内层[0, i)重新遍历买入价格,
 *      因为遍历到i的时候, i之前的价格都已经清楚了, 用一个变量存储最低价格就好了
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int low_price = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            ans = max(ans, prices[i] - low_price);
            low_price = min(low_price, prices[i]);
        }
        return ans;
    }
};