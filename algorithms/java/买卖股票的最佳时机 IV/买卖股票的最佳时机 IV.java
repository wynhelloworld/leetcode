// Source : https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/ 
// Author : Yanan Wang
// Date   : 2023-06-22

class Solution {
    public int maxProfit(int k, int[] prices) {
        int n = prices.length;
        k = Math.min(k, n / 2);
        int[][] f = new int[n][k + 1];
        int[][] g = new int[n][k + 1];
        for (int i = 0; i < k + 1; i++) {
            f[0][i] = -1001;
            g[0][i] = -1001;
        }
        f[0][0] = -prices[0];
        g[0][0] = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < k + 1; j++) {
                f[i][j] = Math.max(f[i - 1][j], g[i - 1][j] - prices[i]);
                if (j - 1 >= 0) {
                    g[i][j] = Math.max(g[i - 1][j], f[i - 1][j - 1] + prices[i]);
                } else {
                    g[i][j] = g[i - 1][j];
                }
            }
        }
        int result = 0;
        for (int i = 0; i < k + 1; i++) {
            result = Math.max(result, g[n - 1][i]);
        }
        return result;
    }
}