// Source : https://leetcode.cn/problems/check-permutation-lcci/description/
// Author : Yanan Wang
// Date   : 2023-10-07

/**
 * 本题就把两字符串的所有字符都分别放入hash中，看hash是否一样就行了。
 * 但其实还可以优化成一个hash，s1往hash里增加数量，s2往hash里减少数量。
 * 最终看hash中是否有0即可。
 */

class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if (s1.size() != s2.size()) {
            return false;
        }
        int hash[26] = { 0 };
        for (int i = 0; i < s1.size(); ++i) {
            ++hash[s1[i] - 'a']; 
            --hash[s2[i] - 'a']; 
        }
        for (int i = 0; i < 26; ++i) {
            if (hash[i] != 0) {
                return false;
            }
        }
        return true;
    }
};