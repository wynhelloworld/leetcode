// Source : https://leetcode.cn/problems/longest-common-prefix/description/
// Author : Yanan Wang
// Date   : 2023-10-10

class Solution {
public:
    /*两两字符串横向比较*/
    string longestCommonPrefix(vector<string>& strs) {
        int prefix = INT_MAX;
        for (int i = 0; i < strs.size(); ++i) {
            int len = 0;
            for (int j = 0; j < strs[i].size(); ++j) {
                if (strs[0][j] != strs[i][j]) {
                    break;
                }
                ++len;
            }
            prefix = min(prefix, len);
        }
        return strs[0].substr(0, prefix);
    }
    /*所有字符串一起纵向比较*/
    /*
    string longestCommonPrefix(vector<string>& strs) {
        int prefix = 0;
        for (int j = 0; j < strs[0].size(); ++j) {
            char c = strs[0][j];
            for (int i = 0; i < strs.size(); ++i) {
                if (j == strs[i].size() || strs[i][j] != c) {
                    return strs[0].substr(0, prefix);
                } 
            }
            ++prefix;
        }
        return strs[0];
    }
    */
};