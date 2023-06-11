// Source : https://leetcode.cn/problems/n-th-tribonacci-number/
// Author : Yanan Wang
// Date   : 2023-06-11

class Solution {
    public int tribonacci(int n) {
        if (0 == n) return 0;
        if (1 == n || 2 == n) return 1;
        int a = 0, b = 1, c = 1, d = 0;
        for (int i = 3; i <= n; i++) {
            d = a + b + c;
            a = b;
            b = c;
            c = d;
        }
        return d;
    }
}