// Source : https://leetcode.cn/problems/contains-duplicate-ii/description/ 
// Author : Yanan Wang
// Date   : 2023-10-08

/**
 * 用hash存放nums中元素与下标的映射
 * 在遍历过程中，检查hash中是否存在nums[i]，若存在就比较一下i-hahs[nums[i]] <= k，若成立返回true
 * 若不成立，就把nums[i]与i的映射放入hash
 */

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); ++i) {
            if (hash.count(nums[i])) {
                if (i - hash[nums[i]] <= k) {
                    return true;
                }
            }
            hash[nums[i]] = i;
        }
        return false;
    }
};