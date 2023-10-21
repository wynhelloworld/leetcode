// Source : https://leetcode.cn/problems/longest-palindrome/description/
// Author : Yanan Wang
// Date   : 2023-10-21

/**
 * 本题, 若能够知道所有的字符种类和数量的话, 就能够按照数量往基准线两侧放字符
 *      eg:
 *          a 6
 *          b 5
 *          c 4
 *                 c c b b a a a | a a a b b c c
 *      遇到偶数就对半往两边放
 *      遇到奇数就-1, 然后对半往两边放
 *      但是, 基准线那里也可以放字符, 若中间能遇到奇数的话, 就往基准线那放一个字符
 *  所以, 第一步: 用hash存储所有的字符种类和数量
 *       第二步: 根据数量填充答案, 若是偶数直接全加
 *                                 奇数-1全部加
 *              最后看是否存在奇数, 若有奇数再+1
 */

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> hash;
        for (auto &c : s) {
            ++hash[c];
        }
        
        int ans = 0;
        int flag = 0;
        for (auto &[k, v] : hash) {
            if (v % 2 == 0) {
                ans += v;
            } else {
                ans += v - 1;    
                flag = 1;
            }
        }
        return ans + flag;
    }
};