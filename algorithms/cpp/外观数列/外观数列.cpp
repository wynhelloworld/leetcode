// Source : https://leetcode.cn/problems/count-and-say/description/
// Author : Yanan Wang
// Date   : 2023-08-19

/**
 * 本题的意思是：countAndSay(n)是对于countAndSay(n-1)的描述
 *       eg：
 *            countAndSay(n-1) = "3322251";
 *            描述为: 2个'3'
 *                   3个'2'
 *                   1个'5'
 *                   1个'1'
 *            然后将以上描述变为字符串：23321511
 * 所以本题的解法就是假设给了countAndSay(n)，
 * 那么就利用countAndSay(1)描述成countAndSay(2)
 * 那么就利用countAndSay(2)描述成countAndSay(3)
 * 那么就利用countAndSay(3)描述成countAndSay(4)
 * . . . . . .
 * 那么就利用countAndSay(n-1)描述成countAndSay(n)
 * 描述方法就是：
 *    利用双指针left，right确定相同的字符及个数
 */

class Solution {
public:
    string countAndSay(int n) {
        string prev = "1";
        for (int i = 2; i <= n; ++i) {
            string curr = "";
            int left = 0, right = 0;
            while (right < prev.size()) {
                while (right < prev.size() && prev[left] == prev[right])
                    ++right;
                curr += to_string(right - left) + prev[left];
                left = right;
            }
            prev = curr;
        }        
        return prev;
    }
};