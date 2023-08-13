// Source : https://leetcode.cn/problems/subarray-sum-equals-k/description/
// Author : Yanan Wang
// Date   : 2023-08-13

/**
 * 设sum[i]表示[0, i]区间上数的和。
 * 设hash存着[0, i-1]区间上,前缀和==sum[i]-k的个数。
 * 要计算[0, i]区间连续子数组和为k的个数，那么可以先求[0, i-1]区间前缀和为sum[i]-k的个数。
 */

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>hash;
        hash[0] = 1;
        int sum = 0, result = 0;
        for (auto &x : nums) {
            sum += x;
            if (hash.count(sum - k)) result += hash[sum - k];
            ++hash[sum];
        }
        return result;
    }
};