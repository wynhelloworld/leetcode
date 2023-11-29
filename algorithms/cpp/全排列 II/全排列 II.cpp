// Source : https://leetcode.cn/problems/permutations-ii/description/ 
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
            if (!vis[i] && (i == 0 || nums[i - 1] != nums[i] || vis[i - 1])) {
                path.push_back(nums[i]);
                vis[i] = true;
                dfs(nums);
                path.pop_back();
                vis[i] = false;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        n = nums.size();
        vis.resize(n);
        dfs(nums);
        return ans;
    }
};