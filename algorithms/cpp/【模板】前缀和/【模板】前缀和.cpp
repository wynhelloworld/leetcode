// Source : https://www.nowcoder.com/practice/acead2f4c28c401889915da98ecdc6bf?tpId=230&tqId=2021480&ru=%2Fpractice%2F99eb8040d116414ea3296467ce81cbbc&qru=%2Fta%2Fdynamic-programming%2Fquestion-ranking&sourceUrl=
// Author : Yanan Wang
// Date   : 2023-08-12

/**
 * 本题可以先制造一个前缀和数组dp，即dp[i]表示[0, i]区间上的和
 * 然后，输出dp[r] - dp[l - 1]即可求出查询结果
 * 求前缀和数组实际是一个非常简单的动态规划
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<long long> dp(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> dp[i];
        dp[i] += dp[i - 1];
    }
    int l, r;
    while (cin >> l >> r) { 
        cout << dp[r] - dp[l - 1] << endl;
    }
    return 0;
}