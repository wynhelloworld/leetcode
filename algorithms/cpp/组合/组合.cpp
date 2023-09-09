// Source : https://leetcode.cn/problems/combinations/description/
// Author : Yanan Wang
// Date   : 2023-09-09

class Solution {
private:
    vector<vector<int>> ans;
    vector<int> path;
public:
    void dfs(int n, int k, int index) {
        if (path.size() == k) {
            ans.push_back(path);
            return;
        }
        for (int i = index; i <= n; ++i) {
            path.push_back(i);
            dfs(n, k, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        dfs(n, k, 1);
        return ans;
    }
};