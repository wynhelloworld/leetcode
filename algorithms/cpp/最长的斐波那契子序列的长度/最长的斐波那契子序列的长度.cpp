// Source : https://leetcode.cn/problems/length-of-longest-fibonacci-subsequence/
// Author : Yanan Wang
// Date   : 2023-06-30

/**
 * 动态规划类题目的一般步骤：
 *    1. 状态表示
 *         ⭐️先设dp[i]表示以arr[i]结尾的子序列中，最长斐波那契子序列的长度。
 *           但根据上述状态表示无法进行状态转移，因为，无法根据最后一个值推导出前两个值，因为前两个dp只存放的是长度，而推不出序列形状。
 *         ⭐️所以设dp[i][j]表示以arr[i]和arr[j]结尾的子序列中，最长斐波那契子序列的长度。（0 < i < j）
 *           因为，根据7和9，可以推导出前一个数为5，而5和7此时已有dp值，即填dp时：dp(7, 9) = dp(5, 7) + 1;
 *         ⭐️因为根据后两个数可以推导出具体的前一个数，而在进行填表时，需要前一个数的下标，那么不妨将所有的数和下标放入hash，用时即取，不需遍历。
 *    2. 状态转移方程
 *         dp[i][j] = dp[hash[tmp]][i] + 1;  (tmp--k, 0 <= k < i)
 *    3. 初始化
 *         全部初始化为2，这里的dp记录下真实的长度
 *    4. 填表顺序
 *         从左向右，从上到下
 *    5. 返回值
 *         dp中的最大值ret， ret == 2 ? 0 : ret
 */

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> hash;
        for (int i = 0; i < n; ++i) {
            hash[arr[i]] = i;
        }
        vector<vector<int>> dp(n, vector<int>(n, 2));
        int result = 2;
        for (int i = 1; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int tmp = arr[j] - arr[i];
                if (hash.count(tmp) && tmp < arr[i]) {
                    dp[i][j] = dp[hash[tmp]][i] + 1;
                } 
                result = max(result, dp[i][j]);
            }
        }
        return result == 2 ? 0 : result;
    }
};