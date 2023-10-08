// Source : https://leetcode.cn/problems/contains-duplicate/description/
// Author : Yanan Wang
// Date   : 2023-10-08

/**
 * 遍历的过程中，检查元素是否在hash中存在过，若存在的话就返回true，若不存在就把元素放入hash中
 */

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> hash;
        for (auto &x : nums) {
            if (hash.count(x)) {
                return true;
            }
            ++hash[x];
        }
        return false;
    }
};