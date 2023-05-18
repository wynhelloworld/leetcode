// Source : https://leetcode.cn/problems/min-cost-climbing-stairs/
// Author : Yanan Wang
// Date   : 2023-05-17

/**
 * 解法一：
 * 动态规划类题目的一般步骤：
 *   1. 状态表示
          根据题目要求：返回达到楼梯顶部的最低花费，那么不妨假设dp[i]就是从第0阶达到第i阶的最低花费
 *   2. 状态转移方程
 *        题目还说，支付cost[i]，即可选择向上爬一个或者两个台阶，即达到i阶的上一阶只能是i-1或者i-2阶，
 *        也就是说，dp[i-1]+cost[i-1]或者dp[i-2]+cost[i-2]就是dp[i]，
 *        即，dp[i] = min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2]);
 *   3. 初始化
 *        根据状态转移方程，可得出i >= 2, 那么只需要初始化dp[0]和dp[1],
 *        题目说了，可以选择从下标为0或下标为1的台阶开始爬楼梯，即dp[0]=dp[1]=0
 *   4. 填表顺序
 *        根据状态表示和状态转移方程，可以得出，为求dp[i],就要先求dp[i-1]和dp[i-2]，
 *        所以填表顺序为从左向右
 *   5. 返回值
 *        dp[i]表示达到i阶的最低花费，题目要求达到楼梯顶部的最低花费，那么返回dp[n]即可
 */

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1);
        for (int i = 2; i <= n; ++i)
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        return dp[n];
    }
};

/**
 * 解法二：
 * 动态规划类题目的一般步骤：
 *   1. 状态表示
          根据题目要求：假设dp[i]是从第i阶达到楼顶的最低花费
 *   2. 状态转移方程
 *        i阶的下一步有两种，一是i+1阶，二是i+2阶
 *        dp[i+1]和dp[i+2]分别表示第i+1阶达到楼顶的最低花费和第i+2阶达到楼顶的最低花费
 *        那么dp[i] = cost[i] + min(dp[i+1], dp[i+2]);
 *   3. 初始化
 *        根据状态转移方程，为求dp[i]要先求dp[i+1]和dp[i+2]，而cost给出了最后两阶的dp
 *        dp[n-1]=cost[n-1], dp[n-2]=cost[n-2]
 *   4. 填表顺序
 *        很显然，从右向左
 *   5. 返回值
 *        dp[i]表示从第i阶达到楼顶的最低花费，而题目允许我们选择从下标0或1开始爬楼梯，
 *        即返回 min(dp[0], dp[1])
 */

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n);
        dp[n - 1] = cost[n - 1];
        dp[n - 2] = cost[n - 2];
        for (int i = n - 3; i >= 0; --i)
            dp[i] = cost[i] + min(dp[i + 1], dp[i + 2]);
        return min(dp[0], dp[1]);
    }
};