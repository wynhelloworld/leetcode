// Source : https://leetcode.cn/problems/word-break/
// Author : Yanan Wang
// Date   : 2023-06-06

/**
 * 动态规划类题目的一般步骤：
 *   1. 状态表示
 *        设dp[i]表示以s[i]结尾的字符串能否利用字典拼接
 *   2. 状态转移方程
 *        设一个下标j，s[j]--s[i]表示以s[i]结尾的最后一个单词
 *        那么，如果dp[j - 1] == true && s[j]--s[i]单词在wordDict里，那么dp[i] = true，反之dp[i] = false;
 *   3. 初始化
 *        在寻找最后一个单词的起始下标j的时候，j的范围其实是[0, i]的，所以如果当j=0时，dp[j-1]就会越界，
 *        所以dp前面多开一个，此时要注意：1. dp[0]的值不能影响后面的填表，只能填true
 *                                   2. 下标的映射关系，此时可以在s的前面添加一个字符
 *   4. 填表顺序
 *        一起从左向右
 *   5. 返回值
 *        dp的最后一个元素
 */

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> hash;
        for (auto &str : wordDict) {
            hash.insert(str);
        }
        s.insert(s.begin(), ' ');
        int n = s.size();
        vector<bool> dp(n, false);
        dp[0] = true;
        for (int i = 1; i < n; ++i) {
            for (int j = i; j > 0; --j) {
                if (dp[j - 1] && hash.count(s.substr(j, i - j + 1))) {
                    dp[i] = true;
                }
            }
        }
        return dp[n - 1];
    }
};