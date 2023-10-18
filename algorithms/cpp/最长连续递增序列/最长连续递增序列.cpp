// Source : https://leetcode.cn/problems/longest-continuous-increasing-subsequence/description/ 
// Author : Yanan Wang
// Date   : 2023-10-18

/**
 * 本题用双指针+贪心
 * i记录递增序列的开始, j记录递增序列的结束
 * 每次更新i时进行贪心, i = j
 */

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size();) {
            int j = i + 1;
            while (j < nums.size() && nums[j - 1] < nums[j]) {
                ++j;
            }
            ans = max(ans, j - i);
            i = j;
        }
        return ans;
    }
};