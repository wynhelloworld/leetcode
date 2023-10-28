// Source : https://leetcode.cn/problems/reorganize-string/description/
// Author : Yanan Wang
// Date   : 2023-10-28

/**
 * 本题与《1054. 距离相等的条形码》几乎一样
 * 区别就是:
 *      《1054. 距离相等的条形码》必定有解
 *       本题, 可能有解, 可能无解
 * 所以, 本题需要多一步进行判断是否有解.
 * 方法:
 *      先统计出出现次数最多的数的次数cnt, 然后根据鸽巢原理,
 *      若 cnt <= (n+1)/2, 则必定有解
 *      反之, 无解
 */

class Solution {
public:
    string reorganizeString(string s) {
        int max_cnt = 0; // 出现字符最多的次数
        int max_val = 0; // 出现最多次数的字符
        unordered_map<char, int> hash;
        for (auto &c : s) {
            ++hash[c];
            if (max_cnt < hash[c]) {
                max_cnt = hash[c];
                max_val = c;
            }
        }
        hash.erase(max_val);
        
        int n = s.size();
        if (max_cnt > (n + 1) / 2) {
            return "";
        }

        string ans;
        ans.resize(n);
        int i = 0;
        while (max_cnt--) {
            ans[i] = max_val;
            i += 2;
        }
        for (auto &[k, v] : hash) {
            while (v--) {
                if (i >= n) {
                    i  = 1;
                }
                ans[i] = k;
                i += 2;
            }
        }
        return ans;
    }
};