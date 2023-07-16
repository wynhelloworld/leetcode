// Source : https://www.nowcoder.com/practice/fd55637d3f24484e96dad9e992d3f62e?tpId=230&tqId=2032484&ru=/exam/oj&qru=/ta/dynamic-programming/question-ranking&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D196
// Author : Yanan Wang
// Date   : 2023-07-13

/**
 * 动态规划类题目的一般步骤：
 *    1. 状态表示
 *         (1) 设dp[i][j]表示背包在[0,i]区间内挑选，总体积不超过j的最大价值。
 *         (2) 设dp[i][j]表示背包在[0,i]区间内挑选，总体积恰好等于j的最大价值。
 *    2. 状态转移方程
 *         根据最后一步的状态分情况讨论：
 *            (1)             |- 当不挑选n[i]时，dp[i - 1][j];
 *                dp[i][j] = -|
 *                            |- 当挑选n[i]时，如果j - v[i] >= 0，dp[i - 1][j - v[i]] + w[i];
 *                即，状态转移方程为：{
 *                                     dp[i][j] = dp[i - 1][j];
 *                                     if (j >= v[i]) {
 *                                         dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]] + w[i]);   
 *                                     }
 *                                 }          
 *            (2) 当满足dp[i][j]的条件不存在时，dp[i][j] = -1;
 *                            |- 当不挑选n[i]时，dp[i - 1][j];
 *                dp[i][j] = -|
 *                            |- 当挑选n[i]时，如果j >= v[i] && dp[i - 1][j - v[i]] != -1，dp[i - 1][j - v[i]] + w[i];
 *                即，状态转移方程为：{
 *                                     dp[i][j] = dp[i - 1][j];
 *                                     if (j >= v[i] && dp[i - 1][j - v[i]] != -1) {
 *                                         dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]] + w[i]);   
 *                                     }
 *                                 }            
 *    3. 初始化
 *         (1) 多开辟一行，当i == 0，即物品个数为0时，dp[0][j] = 0;
 *             多开辟一列，当j == 0，即物品体积为0时，dp[i][0] = 0;
 *         (2) 多开辟一行，当i == 0，即物品个数为0时，dp[0][0] = 0;  dp[0][j] = -1; (j > 0)
 *             多开辟一列，当j == 0，即物品体积为0时，dp[i][0] = 0;
 *    4. 填表顺序
 *         (1) 因为填dp[i][j]需要dp[i-1][j]或者dp[i-1][j-v[i]]，所以从左往右，从上往下填表
 *         (2) 因为填dp[i][j]需要dp[i-1][j]或者dp[i-1][j-v[i]]，所以从左往右，从上往下填表
 *    5. 返回值
 *         (1) dp[n][V];
 *         (2) dp[n][V] == -1 ? 0 : dp[n][V];
 */

// #include <iostream>
// #include <cstring>

// using namespace std;

// const int N = 1001;
// int n, V, v[N], w[N];
// int dp[N][N];

// int main() {
//     // 读入数据
//     cin >> n >> V;
//     for (int i = 1; i <= n; ++i) {
//         cin >> v[i] >> w[i];
//     }
//     // 第一问
//     for (int i = 1; i <= n; ++i) {
//         for (int j = 1; j <= V; ++j) {
//             dp[i][j] = dp[i - 1][j];
//             if (j >= v[i]) {
//                 dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
//             }
//         }
//     }    
//     cout << dp[n][V] << endl;
//     // 第二问
//     memset(dp, 0, sizeof dp);
//     for (int j = 1; j <= V; ++j) {
//         dp[0][j] = -1;
//     }
//     for (int i = 1; i <= n; ++i) {
//         for (int j = 1; j <= V; ++j) {
//             dp[i][j] = dp[i - 1][j];
//             if (j >= v[i] && dp[i - 1][j - v[i]] != -1) {
//                 dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
//             }
//         }
//     }    
//     cout << (dp[n][V] == -1 ? 0 : dp[n][V]);
//     return 0;
// }

/**
 * 优化：采用滚动数组的方式
 *   由于填dp[i][j]仅需要dp[i - 1][j]和dp[i - 1][j - v[i]]，也就是仅需要上一行即可，那么就可以将dp[N][N]优化为dp[2][N]。
 *   但其实还可以将dp[2][N]优化为dp[N]。
 *                                       * 表示dp[i][j]    
 *                                       # 表示dp[i - 1][j]或者dp[i - 1][j - v[i]]
 *   ---------------------
 *   |   |   |   |   |   |
 *   ---------------------             ---------------------
 *   |   | # |   | # |   |             |   | # |   | # |   |            ------------------------
 *   ---------------------     -->     ---------------------     -->    |   | # |   |   | #(*) | 
 *   |   |   |   | * |   |             |   |   |   | * |   |            ------------------------
 *   ---------------------             ---------------------            改为这种方式，需要从后往前填表
 *   |   |   |   |   |   |
 *   ---------------------
 */

#include <iostream>
#include <cstring>

using namespace std;

const int N = 1001;
int n, V, v[N], w[N];
int dp[N];

int main() {
    // 读入数据
    cin >> n >> V;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i] >> w[i];
    }
    // 第一问
    for (int i = 1; i <= n; ++i) {
        for (int j = V; j >= v[i]; --j) {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }    
    cout << dp[V] << endl;
    // 第二问
    memset(dp, 0, sizeof dp);
    for (int j = 1; j <= V; ++j) {
        dp[j] = -1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = V; j >= v[i]; --j) {
            if (dp[j - v[i]] != -1) {
                dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
            }
        }
    }    
    cout << (dp[V] == -1 ? 0 : dp[V]);
    return 0;
}