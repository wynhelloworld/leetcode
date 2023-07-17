// Source : https://www.nowcoder.com/practice/237ae40ea1e84d8980c1d5666d1c53bc?tpId=230&tqId=2032575&ru=/exam/oj&qru=/ta/dynamic-programming/question-ranking&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D196
// Author : Yanan Wang
// Date   : 2023-07-16

/**
 * 动态规划类题目的一般步骤：
 *    1. 状态表示
 *         (1) 设dp[i][j]表示背包在[0,i]区间内挑选，总体积不超过j的最大价值。
 *         (2) 设dp[i][j]表示背包在[0,i]区间内挑选，总体积恰好等于j的最大价值。
 *    2. 状态转移方程
 *         根据最后一步的状态分情况讨论：
 *            (1)             |- 当不挑选n[i]时，dp[i - 1][j];
 *                dp[i][j] = -|- 当挑选1个n[i]时，如果j - v[i] >= 0，dp[i - 1][j - v[i]] + w[i];
 *                            |- 当挑选2个n[i]时，如果j - 2 * v[i] >= 0，dp[i - 1][j - 2 * v[i]] + 2 * w[i];
 *                            |- 当挑选3个n[i]时，如果j - 3 * v[i] >= 0，dp[i - 1][j - 3 * v[i]] + 3 * w[i];
 *                            |- . . .

 *                即，状态转移方程为：{
 *                                     dp[i][j] = dp[i - 1][j];
 *                                     if (j >= v[i]) {
 *                                         dp[i][j] = max(dp[i][j], dp[i][j - v[i]] + w[i]);   
 *                                     }
 *                                 }          
 *            (2) 当满足dp[i][j]的条件不存在时，dp[i][j] = -1;
 *                            |- 当不挑选n[i]时，dp[i - 1][j];
 *                dp[i][j] = -|- 当挑选1个n[i]时，如果j >= v[i] && dp[i - 1][j - v[i]] != -1，dp[i - 1][j - v[i]] + w[i];
 *                            |- 当挑选2个n[i]时，如果j >= 2 * v[i] && dp[i - 1][j - 2 * v[i]] != -1，dp[i - 1][j - 2 * v[i]] + w[i];
 *                            |- 当挑选3个n[i]时，如果j >= 3 * v[i] && dp[i - 1][j - 3 * v[i]] != -1，dp[i - 1][j - 3 * v[i]] + w[i];
 *                            |- . . .
 *                即，状态转移方程为：{
 *                                     dp[i][j] = dp[i - 1][j];
 *                                     if (j >= v[i] && dp[i][j - v[i]] != -1) {
 *                                         dp[i][j] = max(dp[i][j], dp[i][j - v[i]] + w[i]);   
 *                                     }
 *                                 }            
 *    3. 初始化
 *         (1) 多开辟一行，当i == 0，即物品个数为0时，dp[0][j] = 0;
 *             多开辟一列，当j == 0，即物品体积为0时，dp[i][0] = 0;(不用初始化也行，因为填列的时候会进行if判断)
 *         (2) 多开辟一行，当i == 0，即物品个数为0时，dp[0][0] = 0;  dp[0][j] = -1; (j > 0)
 *             多开辟一列，当j == 0，即物品体积为0时，dp[i][0] = 0;(不用初始化也行，因为填列的时候会进行if判断)
 *    4. 填表顺序
 *         (1) 因为填dp[i][j]需要dp[i-1][j]或者dp[i][j-v[i]]，所以从左往右，从上往下填表
 *         (2) 因为填dp[i][j]需要dp[i-1][j]或者dp[i][j-v[i]]，所以从左往右，从上往下填表
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
//         for (int j = 0; j <= V; ++j) {
//             dp[i][j] = dp[i - 1][j];
//             if (j >= v[i]) {
//                 dp[i][j] = max(dp[i][j], dp[i][j - v[i]] + w[i]);
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
//         for (int j = 0; j <= V; ++j) {
//             dp[i][j] = dp[i - 1][j];
//             if (j >= v[i] && dp[i][j - v[i]] != -1) {
//                 dp[i][j] = max(dp[i][j], dp[i][j - v[i]] + w[i]);
//             }
//         }
//     }
//     cout << (dp[n][V] == -1 ? 0 : dp[n][V]) << endl;
//     return 0;
// }

/**
 * 优化：采用滚动数组的方式
 *   由于填dp[i][j]仅需要dp[i - 1][j]和dp[i][j - v[i]]，也就是仅需要上一行和当前行即可，那么就可以将dp[N][N]优化为dp[2][N]。
 *   但其实还可以将dp[2][N]优化为dp[N]。
 *                                       * 表示dp[i][j]    
 *                                       # 表示dp[i - 1][j]或者dp[i][j - v[i]]
 *   ---------------------
 *   |   |   |   |   |   |
 *   ---------------------             ---------------------
 *   |   |   |   | # |   |             |   |   |   | # |   |            ------------------------
 *   ---------------------     -->     ---------------------     -->    |   | # |   |   | #(*) | 
 *   |   | # |   | * |   |             |   | # |   | * |   |            ------------------------
 *   ---------------------             ---------------------            遍历顺序不变->一定要从左向右，                    
 *   |   |   |   |   |   |                                       因为当填*是用的#要么是上一行的，要么是当前行的左边。
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
        for (int j = 0; j <= V; ++j) {
            if (j >= v[i]) {
                dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
            }
        }
    }
    cout << dp[V] << endl;
    // 第二问
    memset(dp, 0, sizeof dp);
    for (int j = 1; j <= V; ++j) {
        dp[j] = -1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= V; ++j) {
            dp[j] = dp[j];
            if (j >= v[i] && dp[j - v[i]] != -1) {
                dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
            }
        }
    }
    cout << (dp[V] == -1 ? 0 : dp[V]) << endl;
    return 0;
}