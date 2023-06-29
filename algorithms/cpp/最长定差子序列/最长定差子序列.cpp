// Source : https://leetcode.cn/problems/longest-arithmetic-subsequence-of-given-difference/
// Author : Yanan Wang
// Date   : 2023-06-29

/**
 * 动态规划类题目的一般步骤：
 *    1. 状态表示
 *         设dp[i]表示以arr[i]结尾的所有子序列中，最长定差子序列的长度
 *    2. 状态转移方程
 *       ⭐️if (arr[i] - arr[i - 1] == difference) dp[i] = max(dp[i], dp[j] + 1);
 *         但若仅仅是上面这样，本题通过不了，时间复杂度太高。
 *         因为本题目是定差并且给定了difference，那么当我们填arr[i]的dp[i]时，其实就已经知道要找的dp[j]是arr[i] - difference的，
 *         在arr[i]之前可能有很多个arr[i]-difference，优化方法就是只取最近的那一个即可。
 *            eg: [a, a, d, c, g, d, d, d, f, e] (difference = 1) 
 *                  当填充e的dp时，我们有四个d可以选择，但为了正确性，应该选择右边那3个d；
 *                                                  为了效率，应该选择最右边那一个d。
 *       ⭐️所以，状态转移方程就变为if (arr[i] - arr[i - 1] == difference) { dp[i] = dp[j] + 1; break;}
 *         但还能继续优化，因为根据arr[i]就已经知道前一个数是arr[i]-difference，那么我们可以直接把所有的dp都填入hash表中
 *       ⭐️所以，状态转移方程就变为hash[arr[i]] = hash[arr[i] - difference] + 1;
 *    3. 初始化
 *         因为用hash表来补充状态，有则用之，无则补0，所以不需要初始化
 *    4. 填表顺序
 *         从左向右
 *    5. 返回值
 *         哈希表中的最大值
 */

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        unordered_map<int, int> hash;
        int result = 1;
        for (int i = 0; i < n; ++i) {
            hash[arr[i]] = hash[arr[i] - difference] + 1;
            result = max(result, hash[arr[i]]);
        }
        return result;
    }
};