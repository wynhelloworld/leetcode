// Source : https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/
// Author : Yanan Wang
// Date   : 2023-08-01

/**
 *                   right
 *                    ⬇
 *               s = "d e a b c a b c a";
 *                    ⬆
 *                   left
 * 本题的暴力解法：
 *      当left指向d时，right从left开始一直向右遍历，同时检测是否出现重复字符了，若出现了，记录下长度。
 *      然后left向右移动一步，right重新从left开始向右遍历重复上面的操作。
 *      但是这个暴力解法做了很多无用的遍历。
 * 优化：
 *      1、当出现重复字符，right向右移动时，无需只移动一步，而是要直接跳到重复字符的后面，看下面例子：
 *                             right
 *                              ⬇
 *               s = "d e a b c a b c a";
 *                    ⬆
 *                   left
 *          此时，right指向a，并且a是重复字符，假设left向右移动一步，指向了e，right重新从left开始遍历，
 *          right最终还是会在相同的位置停下来，并且长度还比之前的短，所以这一次遍历就是无用的。
 *          所以left应直接指向第一个b处。
 *       2、当left更新时，right无需移动，因为当left更新时，此时right和left之间的值肯定是唯一的，没有必要right再重新从left开始遍历。
 * 暴力解法经过上面两步优化后，就成了滑动窗口。   
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), len = 0, hash[128] = { 0 };
        for (int left = 0, right = 0; right < n; ++right) {
            ++hash[s[right]];
            while (hash[s[right]] > 1)
                --hash[s[left++]];
            len = max(len, right - left + 1);
        }
        return len;
    }
};