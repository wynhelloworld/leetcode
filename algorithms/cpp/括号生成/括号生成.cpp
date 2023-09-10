// Source : https://leetcode.cn/problems/generate-parentheses/description/
// Author : Yanan Wang
// Date   : 2023-09-10

class Solution {
private:
    vector<string> ans;
    string path;
    int leftNums;
    int rightNums;
public:
    void dfs(int n) {
        if (rightNums == n) {
            ans.push_back(path);
            return;
        }
        if (leftNums < n) {
            path.push_back('(');
            ++leftNums;
            dfs(n);
            path.pop_back();
            --leftNums;
        }
        if (rightNums < leftNums) {
            path.push_back(')');
            ++rightNums;
            dfs(n);
            path.pop_back();
            --rightNums;
        }
    }
    vector<string> generateParenthesis(int n) {
        leftNums = 0;
        rightNums = 0;
        dfs(n);
        return ans;
    }
};