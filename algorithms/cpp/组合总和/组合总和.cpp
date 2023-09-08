// Source : https://leetcode.cn/problems/combination-sum/description/
// Author : Yanan Wang
// Date   : 2023-09-08

class Solution {
private:
    vector<vector<int>> ans;
    vector<int> path;
    int sum;
public:
    void dfs(vector<int> &candidates, int index, int target) {
        if (target < sum) {
            return;
        }
        if (target == sum) {
            ans.push_back(path);
            return;
        }
        for (int i = index; i < candidates.size(); ++i) {
            path.push_back(candidates[i]);
            sum += candidates[i];
            dfs(candidates, i, target);
            path.pop_back();
            sum -= candidates[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sum = 0;
        dfs(candidates, 0, target);
        return ans;
    }
};