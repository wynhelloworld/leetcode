// Source : https://leetcode.cn/problems/minimum-falling-path-sum/
// Author : Yanan Wang
// Date   : 2023-06-15

class Solution {
    public int minFallingPathSum(int[][] matrix) {
        int n = matrix.length;
        int[][] dp = new int[n + 1][n + 2];
        for (int i = 1; i <= n; i++) {
            dp[i][0] = dp[i][n + 1] = Integer.MAX_VALUE;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = Math.min(Math.min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i - 1][j + 1]) + matrix[i - 1][j - 1];
            }
        }
        int result = Integer.MAX_VALUE;
        for (int i = 1; i <= n; i++) {
            if (result > dp[n][i]) {
                result = dp[n][i];
            }
        }
        return result;
    }
}