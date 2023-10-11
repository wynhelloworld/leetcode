// Source : https://leetcode.cn/problems/longest-palindromic-substring/
// Author : Yanan Wang
// Date   : 2023-07-04

/**
 * 动态规划类题目的一般步骤：
 *    1. 状态表示
 *         设dp[i][j]表示以s[i]开始、s[j]结尾的字串是否是回文串
 *    2. 状态转移方程
 *         当s[i] == s[j]时，有三种情况：1、i == j 此时就一个字母，肯定是回文串
 *                                    2、i + 1 == j 此时是相邻两个字母相同，也肯定是回文串
 *                                    3、有三个及以上个字母，此时看s[i + 1]和s[j - 1]是否相等，若相等，则为回文串
 *       ⭐️即，if (s[i] == s[j]) { dp[i][j] = i + 1 < j ? dp[i + 1][j - 1] : true; } 
 *    3. 初始化
 *         无需初始化
 *    4. 填表顺序
 *         从下往上填每一行，从前往后填每一列
 *    5. 返回值
 *         dp表中记录了从i位置到j位置的子串是否为回文串，那么只需要找出i与j的距离最远的那个回文子串，返回即可。
 */

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));
        int length, left = 0;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (s[i] == s[j]) {
                    dp[i][j] = i + 1 < j ? dp[i + 1][j - 1] : true;
                }
                if (dp[i][j] && length < (j - i + 1)) {
                    length = j - i + 1;
                    left = i;
                }
            }
        }
        return s.substr(left, length);
    }
};

/**
 * 新增了一种解法
 * 本解法就是在遍历的过程中，向两边探测，相等就往两边延伸，不相等就结束本次探测。
 *      "dawdwafawwaddwa"
 *             i
 *         left  right
 *    left和right从i开始向两边延伸，此时所找到的回文子串个数全都是奇数的；
 *    left和right从i、i+1开始向两边延伸，此时所找到的回文字串个数全都是偶数的。
 */

class Solution {
public:
    int ans_begin;
    int ans_len;
public:
    void handler(string &s, int left, int right) {
        while ((left >= 0 && right <= s.size()) && (s[left] == s[right])) {
            --left;
            ++right;
        }
        int begin = left + 1;
        int len = right - left - 1;
        if (len >= ans_len) {
            ans_len = len;
            ans_begin = begin;         
        }
    }
    string longestPalindrome(string s) {
        for (int i = 0; i < s.size(); ++i) {
            // 奇数
            handler(s, i, i);
            // 偶数
            handler(s, i, i + 1);
        }
        return s.substr(ans_begin, ans_len);
    }
};