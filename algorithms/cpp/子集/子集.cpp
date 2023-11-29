// Source : https://leetcode.cn/problems/subsets/description/
// Author : Yanan Wang
// Date   : 2023-11-29

class Solution {
public:
    vector<int> path;
    vector<vector<int>> ans;
    void dfs(vector<int> &nums, int i) {
        ans.push_back(path);
        for (; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            dfs(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return ans;
    }
};