// Source : https://leetcode.cn/problems/minimum-window-substring/description/
// Author : Yanan Wang
// Date   : 2023-08-06

/**
 * 本题先用暴力解法，然后优化细节就能变成动态规划的做法，但是在判断两字符串时，一般的做法是遍历t和s中的字符数量进行比较。
 * 上面的方法比较慢（官方题解），下面是更优解法：
 *    用cnt来记录窗口中“有效字符种类数量”，当cnt==t中的字符种类数量时，进行更新。
 *    1、 在进窗口后，判断该字符在窗口和t中的数量，若相等，则为有效字符，++cnt
 *    2、 在出窗口前，判断该字符在窗口和t中的数量，若相等，则该有效字符被剔除掉了，--cnt
 */

class Solution {
public:
    string minWindow(string s, string t) {
        char base[128] = { 0 }, kinds = 0;
        for (const auto &c : t) 
            if (0 == base[c]++) ++kinds;
        int start = 0, len = INT_MAX;
        char window[128] = { 0 };
        for (int left = 0, right = 0, cnt = 0; right < s.size(); ++right) {
            char in = s[right];
            if (base[in] == ++window[in]) ++cnt;
            while (cnt == kinds) {
                if (right - left + 1 < len) {
                    len = right - left + 1;
                    start = left;
                }
                char out = s[left++];
                if (base[out] == window[out]--) --cnt;
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};