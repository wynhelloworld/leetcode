// Source : https://leetcode.cn/problems/substring-with-concatenation-of-all-words/description/
// Author : Yanan Wang
// Date   : 2023-08-05

/**
 * 本题目是《438. 找到字符串中所有字母异位词》的进阶版。
 * 本题，只需把words中的每个word看做一个char，然后根据word的长度把s看做一个个char，如下图所示。
 *      s = "b a r f o o t h e f o o b a r m a n", words = ["f o o" , "b a r"]
 *           -----|-----|-----|-----|-----|-----             -----     -----
 *             x     y     m     y     x     z                  y        x             
 *      然后，针对想象分界出来的s和words根据题438做即可。
 *      注意：滑动窗口是有执行次数的，因为就如上图所示那是一次，但还可以从下标1开始分界，从下标2开始分界，所以滑动窗口次数是单词的长度，如下图所示。
 *      s = "b a r f o o t h e f o o b a r m a n", words = ["f o o" , "b a r"]
 *           -----|-----|-----|-----|-----|-----             -----     -----
 *             -----|-----|-----|-----|-----|-----             
 *               -----|-----|-----|-----|-----|-----             
 */

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        unordered_map<string, int> base;
        for (auto &word : words) ++base[word];
        int len = words[0].size();
        for (int i = 0; i < len; ++i) {
            unordered_map<string, int> temp;
            for (int left = i, right = i; right + len <= s.size(); right += len) {
                ++temp[s.substr(right, len)];
                if (right - left + 1 > words.size() * len) {
                    if (0 == --temp[s.substr(left, len)]) {
                        temp.erase(s.substr(left, len));
                    }
                    left += len;
                }
                if (base == temp) result.push_back(left);
            }
        }
        return result;
    }
};