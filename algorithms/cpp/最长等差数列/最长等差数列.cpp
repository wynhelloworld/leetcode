// Source : https://leetcode.cn/problems/longest-arithmetic-subsequence/
// Author : Yanan Wang
// Date   : 2023-07-01

/**
 * 动态规划类题目的一般步骤：
 *    1. 状态表示
 *         设dp[i][j]表示以nums[i]和nums[j]结尾的子序列中，最长等差子序列的长度。（0 <= i < j）
 *    2. 状态转移方程
 *         ⭐️dp[i][j] = dp[k][i] + 1      (0 <= k < i)
 *           若是采用上述方程的话，需要三层for循环，时间复杂度太高，本题通不过
 *         ⭐️因为根据后两个数，就可以推出前一个数，那么只需将前一个数以及下标放入hash，即可变为两层for循环
 *           dp[i][j] = dp[hash[tmp]][i] + 1;      (tmp--hash[tmp])
 *           在本题中，是会有很多重复元素的，所以若是一开始就将全部的值和下标放入hash，是不对的。
 *           况且在填dp表的时候，实际上根据后两个数推导出的前一个数在nums中可能是有多个的。
 *           但是，推导出的前一个数一定是要采用离nums[i]最近的那个，所以，可以采用一边填dp一边填hash的方法。
 *           即，用完nums[i]时，再把nums[i]和i填入hash，可保证下次推导出的数一定是最新最近的。
 *    3. 初始化
 *         全部初始化为2
 *    4. 填表顺序
 *         从上往下，从左向右
 *    5. 返回值
 *         返回dp中的最大值
 */
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 2));
        unordered_map<int, int> hash;
        hash[nums[0]] = 0;
        int result = 2;
        for (int i = 1; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int tmp = nums[i] - (nums[j] - nums[i]);
                if (hash.count(tmp) && hash[tmp] < i) {
                    dp[i][j] = dp[hash[tmp]][i] + 1; 
                }
                result = max(result, dp[i][j]);
            }
            hash[nums[i]] = i;
        }
        return result;
    }
};