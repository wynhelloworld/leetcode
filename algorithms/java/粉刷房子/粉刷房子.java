// Source : https://leetcode.cn/problems/JEj789/
// Author : Yanan Wang
// Date   : 2023-06-21

class Solution {
    public int minCost(int[][] costs) {
        int n = costs.length;
        int[][] dp = new int[n + 1][3];
        for (int i = 1; i <= n; i++) {
            dp[i][0] = Math.min(dp[i - 1][1], dp[i - 1][2]) + costs[i - 1][0];
            dp[i][1] = Math.min(dp[i - 1][0], dp[i - 1][2]) + costs[i - 1][1];
            dp[i][2] = Math.min(dp[i - 1][0], dp[i - 1][1]) + costs[i - 1][2];
        }
        return Math.min(Math.min(dp[n][0], dp[n][1]), dp[n][2]);
    }
}