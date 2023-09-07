// Source : https://leetcode.cn/problems/letter-case-permutation/description/
// Author : Yanan Wang
// Date   : 2023-09-07

// 本题先画一颗决策树：当递归到数字时，直接添加上递归到下一层，当递归到字母时，转变大小写进行一次递归，不转变大小写再进行一次递归

class Solution {
private:
    vector<string> ans;
    string path;
public:
    void dfs(const string &s, int index) {
        if (s.size() == index) {
            ans.push_back(path);
            return;
        }
        if (isalpha(s[index])) {
            if (isupper(s[index])) {
                path.push_back(tolower(s[index]));
            } else {
                path.push_back(toupper(s[index]));
            }
            dfs(s, index + 1);
            path.pop_back();
        }
        path.push_back(s[index]);
        dfs(s, index + 1);
        path.pop_back();
    }
    vector<string> letterCasePermutation(string s) {
        dfs(s, 0);
        return ans;
    }
};