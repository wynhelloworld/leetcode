// Source : https://leetcode.cn/problems/permutations/description/ 
// Author : Yanan Wang
// Date   : 2023-11-29

class Solution {
public:
    int n;
    vector<bool> vis;
    vector<int> path;
    vector<vector<int>> ans; 
    void dfs(vector<int> &nums) {
        if (path.size() == n) {
            ans.push_back(path);
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                path.push_back(nums[i]);
                vis[i] = true;
                dfs(nums);
                path.pop_back();
                vis[i] = false; 
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vis.resize(n);
        dfs(nums);
        return ans;
    }
};