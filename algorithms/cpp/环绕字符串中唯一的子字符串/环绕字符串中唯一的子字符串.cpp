// Source : https://leetcode.cn/problems/unique-substrings-in-wraparound-string/
// Author : Yanan Wang
// Date   : 2023-06-06

/**
 * 动态规划类题目的一般步骤：
 *   1. 状态表示
 *        设dp[i]表示以s[i]结尾的非空字符串中在base中的个数
 *   2. 状态转移方程
 *        以s[i]结尾的字符串有两种情况会在base中: 1、只有s[i]，因为一个字符肯定在base中，dp[i] = 1
 *                                           2、如果s[i]和s[i-1]能拼接起来的话，dp[i] = dp[i-1]
 *   3. 初始化
 *        直接把dp全初始化为1即可，因为每个字符都是肯定在base中的
 *   4. 填表顺序
 *        从左向右
 *   5. 返回值
 *        此时的dp[i]其实是有重复的，eg：cac
 *        所以要进行去重，去重之后返回所有元素的和，
 *        去重思路：以相同字母结尾的dp值选最大即可
 */

class Solution {
public:
    int findSubstringInWraproundString(string s) {
        vector<int> hash(26, 0);
        int n = s.size();
        vector<int> dp(n, 1);
        int result = 0;
        for (int i = 1; i < n; ++i) {
            if ((s[i - 1] + 1 == s[i]) || (s[i - 1] == 'z' && s[i] == 'a')) {
                dp[i] += dp[i - 1];
            }
        }
        for (int i = 0; i < n; ++i) {
            hash[s[i] - 'a'] = max(hash[s[i] - 'a'], dp[i]);
        }
        for (int i = 0; i < 26; ++i) {
            result += hash[i];
        }
        return result;
    }
};