// Source : https://leetcode.cn/problems/word-break/
// Author : Yanan Wang
// Date   : 2023-06-24

class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        Set<String> hash = new HashSet(wordDict);
        int n = s.length();
        boolean[] dp = new boolean[n + 1];
        dp[0] = true;
        s = " " + s;
        for (int i = 1; i <= n; i++) {
            for (int j = i; j > 0; j--) {
                if (dp[j - 1] && hash.contains(s.substring(j, i + 1))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
}