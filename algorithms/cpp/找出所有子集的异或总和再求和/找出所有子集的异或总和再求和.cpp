// Source : https://leetcode.cn/problems/sum-of-all-subset-xor-totals/description/
// Author : Yanan Wang
// Date   : 2023-11-29

class Solution {
public:
    int ans = 0;
    int xor_sum = 0;
    void dfs(vector<int> &nums, int i) {
        ans += xor_sum;
        for (; i < nums.size(); ++i) {
            xor_sum ^= nums[i];
            dfs(nums, i + 1);
            xor_sum ^= nums[i];
        }
    }
    int subsetXORSum(vector<int>& nums) {
        dfs(nums, 0);
        return ans;
    }
};