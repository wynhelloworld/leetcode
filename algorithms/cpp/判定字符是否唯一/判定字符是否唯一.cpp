// Source : https://leetcode.cn/problems/is-unique-lcci/description/
// Author : Yanan Wang
// Date   : 2023-08-17

/**
 * 本题可以用unordered_map记录下astr中出现的字符，
 * 但又因为字符仅26个，所以可以int hash[26],
 * 但本题是判断字符是否唯一，所以hash只需记录字符是否出现过，那么就可以用一个变量int的每个bit位来记录。
 * 利用一个int变量，再利用位运算的“判断x位是否为1”，"给x为写上1"即可解答本题
 */

class Solution {
public:
    bool isUnique(string astr) {
        if (astr.size() > 26) return false;
        int bitmap = 0;
        for (auto &c : astr) {
            if ((bitmap >> (c - 'a')) & 1)
                return false;
            else
                bitmap |= (1 << (c - 'a'));
        }
        return true;
    }
};