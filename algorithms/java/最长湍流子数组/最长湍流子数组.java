// Source : https://leetcode.cn/problems/longest-turbulent-subarray/
// Author : Yanan Wang
// Date   : 2023-06-24

class Solution {
    public int maxTurbulenceSize(int[] arr) {
        int n = arr.length;
        int[][] dp = new int[n][2];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                dp[i][j] = 1;
            }
        }
        int result = 1; 
        for (int i = 1; i < n; i++) {
            if (arr[i - 1] > arr[i]) {
                dp[i][1] = dp[i - 1][0] + 1;
            } else if (arr[i - 1] < arr[i]) {
                dp[i][0] = dp[i - 1][1] + 1;
            }
            result = Math.max(Math.max(result, dp[i][0]), dp[i][1]);
        }
        return result;
    }
}