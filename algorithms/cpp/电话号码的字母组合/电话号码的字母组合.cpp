// Source : https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/
// Author : Yanan Wang
// Date   : 2023-11-29

class Solution {
public:
    string dict[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    string path;
    vector<string> ans;
    void dfs(string &digits, int level) {
        if (path.size() == digits.size()) {
            ans.push_back(path);
            return;
        }
        string str = dict[digits[level] - '0'];
        for (int i = 0; i < str.size(); ++i) {
            path.push_back(str[i]);
            dfs(digits, level + 1);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return {};
        }
        dfs(digits, 0);
        return ans;
    }
};