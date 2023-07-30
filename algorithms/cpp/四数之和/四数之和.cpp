// Source : https://leetcode.cn/problems/4sum/description/
// Author : Yanan Wang
// Date   : 2023-07-30

/**
 * 本题跟三数之和一样，只是多了一个固定值进而多了一重循环而已，本题跟三数之和有一个区别就是：
 *     三数之和能根据if(nums[i] > 0) 直接return result;
 *     但四数之和不能这样，因为本题是要求target，而target是有可能为负数的，一旦为负数，if(nums[i] > target) 就return result;的思路就错了。 
 */

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int n = nums.size();
        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int left = j + 1, right = n - 1;
                while (left < right) {
                    if ((long long)nums[i] + nums[j] + nums[left] + nums[right] < target) {
                        ++left;
                    } else if ((long long)nums[i] + nums[j] + nums[left] + nums[right] > target) {
                        --right;
                    } else {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        ++left;
                        --right;
                        while (left < right && nums[left] == nums[left - 1] && ++left);
                        while (left < right && nums[right] == nums[right + 1] && --right);
                    }
                }
            }
        }
        return result;
    }
};