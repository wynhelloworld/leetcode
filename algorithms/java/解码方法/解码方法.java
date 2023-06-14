// Source : https://leetcode.cn/problems/decode-ways/
// Author : Yanan Wang
// Date   : 2023-06-14

class Solution {
    public int numDecodings(String s) {
        int n = s.length();
        int[] dp = new int[n + 1];
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            if (check(s.charAt(i - 1))) {
                dp[i] += dp[i - 1];
            }
            if (i > 1 && check(s.charAt(i - 2), s.charAt(i - 1))) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
    
    public boolean check(char ch) {
        return ch == '0' ? false : true;
    }

    public boolean check(char ch1, char ch2) {
        return (ch1 == '1' || (ch1 == '2' && ch2 <= '6')) ? true : false;
    }
}