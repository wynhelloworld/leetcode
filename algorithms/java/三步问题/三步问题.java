// Source : https://leetcode.cn/problems/three-steps-problem-lcci/
// Author : Yanan Wang
// Date   : 2023-06-12

class Solution {
    public int waysToStep(int n) {
        if (1 == n || 2 == n) return n;
        if (3 == n) return 4;
        final int MOD = 1000000007;
        int a = 1, b = 2, c = 4, d = 0;
        for (int i = 4; i <= n; i++) {
            d = (((a + b) % MOD) + c) % MOD;
            a = b;
            b = c;
            c = d;
        }
        return d;
    }
}