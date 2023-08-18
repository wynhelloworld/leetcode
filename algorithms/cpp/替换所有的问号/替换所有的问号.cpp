// Source : https://leetcode.cn/problems/replace-all-s-to-avoid-consecutive-repeating-characters/description/
// Author : Yanan Wang
// Date   : 2023-08-18

/**
 * 遍历字符串，遇到?时，填写一个与前面和后面都不相同的字符即可。
 */

class Solution {
public:
    string modifyString(string s) {
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] != '?') continue;
            for (char ch = 'a'; ch < 'z'; ++ch) {
                if ((i == 0 || ch != s[i - 1]) && (i == n - 1 || ch != s[i + 1])) {
                    s[i] = ch;
                    break;
                }            
            }
        }
        return s;
    }
};