// Source : https://leetcode.cn/problems/maximum-length-of-pair-chain/
// Author : Yanan Wang
// Date   : 2023-06-28

/**
 * 动态规划类题目的一般步骤：
 *    1. 状态表示
 *         本题目要先做一些预处理：因为状态规划类题目的状态推导（例如，以i位置为结尾时，i-1位置必须是已经计算过的）必须是有序的，
 *         但本题的数对是无序的，所以要对数对进行排序，排序用数对的left作为key，因为这样排序后的数对能够保障当前数对永远不会排在后面数对的后面，
 *         因为：[a1, a2] [b1, b2] ，我们按照a1 <= b1来排序，又因为b1 < b2，所以得出a1 < b2，所以能得出a1a2数对永远不会排在b1b2数对后面
 *         dp[i]表示以i位置结尾的数对链的，最长数对链的长度
 *    2. 状态转移方程
 *         if (pairs[j][1] < pairs[i][0])        (0 <= j < i)
 *             dp[i] += dp[j] + 1;
 *         else
 *             dp[i] = 1;
 *    3. 初始化
 *         全部初始化为1，就可以简化状态转移方程
 *    4. 填表顺序
 *         从左向右
 *    5. 返回值
 *         dp中的最大值
 */

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int n = pairs.size();
        vector<int> dp(n, 1);
        int result = 1;
        for (int i = 1; i < n; ++i) {
            int dp_max = 0;
            for (int j = 0; j < i; ++j) {
                if (pairs[j][1] < pairs[i][0]) {
                    dp_max = max(dp_max, dp[j]);
                }
            }
            dp[i] += dp_max;
            result = max(result, dp[i]);
        }
        return result;
    }
};