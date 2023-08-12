// Source : https://www.nowcoder.com/practice/99eb8040d116414ea3296467ce81cbbc?tpId=230&tqId=38962&ru=/exam/oj
// Author : Yanan Wang
// Date   : 2023-08-12

/**
 * 本题可以先制造一个前缀和数组dp，即dp[i][j]表示矩阵中[0, 0]到[i, j]上值的和
 * 那这一步其实是一个简单的动态规划
 * 然后根据这个dp，再结合x1、y1、x2、y2求出答案即可
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> dp[i][j];
            dp[i][j] += dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
        }
    }
    int x1, y1, x2, y2;
    while (cin >> x1 >> y1 >> x2 >> y2) { 
        cout << dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1] << endl;
    }
    return 0;
}