// Source : https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/ 
// Author : Yanan Wang
// Date   : 2023-05-29

/**
 * 这道题目和买卖股票的最佳时机 III，可以说一模一样，
 * 但是增加一个小细节，题目虽然给了k次交易机会，但实际上可能最多的有效交易次数都达不到k次，
 * 举个例子：
 *    假设天数为10，交易次数k为30
 *    那么，这10天最多的有效交易次数只有5次，
 *    假设天数为15，交易次数k为20
 *    这15天最多的有效交易次数只有7次。
 * 即，k真正的有效值应该 <= n/2
 */

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        k = min(k, n / 2);
        vector<vector<int>> f(n, vector<int>(k + 1, -(1000 + 1)));
        vector<vector<int>> g(n, vector<int>(k + 1, -(1000 + 1)));
        f[0][0] = 0;
        g[0][0] = -prices[0];
        for (int i = 1; i < n; ++i) 
        {
            for (int j = 0; j <= k; ++j)
            {
                if (j - 1 >= 0)
                    f[i][j] = max(f[i - 1][j], g[i - 1][j - 1] + prices[i]);
                else 
                    f[i][j] = f[i - 1][j];
                g[i][j] = max(g[i - 1][j], f[i - 1][j] - prices[i]);
            }
        }
        int result = 0;
        for (int i = 1; i <= k; ++i)
            if (result < f[n - 1][i])
                result = f[n - 1][i];
        return result;
    }
};