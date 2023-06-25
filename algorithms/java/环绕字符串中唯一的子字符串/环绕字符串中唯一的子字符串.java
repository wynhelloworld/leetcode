// Source : https://leetcode.cn/problems/unique-substrings-in-wraparound-string/
// Author : Yanan Wang
// Date   : 2023-06-25

class Solution {
    public int findSubstringInWraproundString(String s) {
        char[] arr = s.toCharArray();
        int n = arr.length;
        int[] dp = new int[n];
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i - 1] + 1 == arr[i] || (arr[i - 1] == 'z' && arr[i] == 'a')) {
                dp[i] = dp[i - 1] + 1;
            } else {
                dp[i] = 1;
            }
        }     
        int[] hash = new int[26];
        for (int i = 0; i < n; i++) {
            hash[arr[i] - 'a'] = Math.max(hash[arr[i] - 'a'], dp[i]);
        }
        int result = 0;
        for (int x : hash) {
            result += x;
        }
        return result;
    }
}
