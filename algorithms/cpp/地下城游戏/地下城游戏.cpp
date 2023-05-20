// Source : https://leetcode.cn/problems/dungeon-game/
// Author : Yanan Wang
// Date   : 2023-05-20

/**
 * 动态规划类题目的一般步骤：
 *   1. 状态表示
 *        根据一般套路：以dp[i][j]为开头或者结尾，然后根据i、j的最近几步推导出状态转移方程
 *        假设以dp[i][j]为结尾，那么dp[i][j]表示从左上角走到dungeon[i][j]所需的最低初始健康点数。
 *           假设为结尾是不可行的，因为这样推导出dp[i][j]需要dp[i-1][j]和dp[i][j-1]，但同时也会
 *           受到dungeon[i][j]后面的影响（假设血包很小，那么此时的dp[i][j]就无效了）。
 *        假设以dp[i][j]为开头，那么dp[i][j]表示从dungeon[i][j]走到右下角所需的最低初始健康点数。
 *   2. 状态转移方程
 *        根据以dp[i][j]为开头推导出状态转移方程：dp[i][j] + dungeon[i][j] >= min(dp[i+1][j], dp[i][j+1])
 *        即dp[i][j] = min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j], 但dp[i][j]必须得是>=1的
 *        即dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
 *   3. 初始化
 *        这里dp多开辟一行一列，但是是添加在末行和末列的，所以不需要进行下标映射
 *        dp全初始化为INT_MAX，dp[m-1][n]或者dp[m][n-1]等于1
 *   4. 填表顺序
 *        从下往上，从右向左
 *   5. 返回值
 *        返回dp[0][0]
 */

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        dp[m][n - 1] = 1;
        for (int i = m - 1; i >= 0; --i)
            for (int j = n - 1; j >= 0; --j)
                dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
        return dp[0][0];
    }
};