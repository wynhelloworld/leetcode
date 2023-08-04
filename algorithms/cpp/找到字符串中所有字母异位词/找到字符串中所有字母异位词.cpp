// Source : https://leetcode.cn/problems/find-all-anagrams-in-a-string/description/
// Author : Yanan Wang
// Date   : 2023-08-04

/**
 * 一般的，用于比较俩字符串是否是异位词，需要先将两字符串排序，然后比较，但是这样效率低下。
 * 所以，可以借助hash来统计字符串中的字符种类及其数量，若两字符串的hash都相等，则是异位词。
 * s = "c b a e b a b a c d", p = "a b c"
 *      -----
 *        -----
 *          -----
 *            . . .
 * 暴力解法：在遍历时，在s中拿跟p相同数量的子串，然后分别放入hash，再进行比较。
 * 优化（动态规划）：根据上面图示可以看到，每一次循环都会重复的将一些字符放入hash，所以不妨用同一个hash，每次遍历时，仅需取出左边字符、放入右边字符即可。
 */

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        unordered_map<char, int> base, temp;
        for (auto c : p) ++base[c];
        for (int left = 0, right = 0; right < s.size(); ++right) {
            ++temp[s[right]];
            if (right - left + 1 > p.size()) {
                if (0 == --temp[s[left]]) 
                    temp.erase(s[left]);
                ++left;
            }
            if (base == temp) 
                result.push_back(left);
        }
        return result;
    }
};