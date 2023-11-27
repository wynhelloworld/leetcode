// Source : https://leetcode.cn/problems/powx-n/description/
// Author : Yanan Wang
// Date   : 2023-11-27

class Solution {
public:
    double dfs(double x, long long n) {
        if (n == 0) {
            return 1.0;
        }
        double y = dfs(x, n / 2);
        return n % 2 == 0 ? y * y : y * y * x; 
    }
    double myPow(double x, int n) {
        return n >= 0 ? dfs(x, n) : 1.0 / dfs(x, -(long long)n);
    }
};