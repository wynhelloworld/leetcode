// Source : https://leetcode.cn/problems/contiguous-array/description/
// Author : Yanan Wang
// Date   : 2023-08-15

/**
 * 本题若把1改成-1，那么题目就可以变为“找到和为0的最长的连续子数组”。
 * 与《和为K的子数组》题目非常相似，无非一个是求总个数，一个是求最长长度。
 * 那么本题就可以利用《和为K的子数组》思想来解。
 * 但本题的hash存的是<前缀和，下标>
 *      由于本题求最长长度，所以当hash有重复元素时，hash只保留最左边（第一次）的那对
 */

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> hash;
        hash[0] = -1;
        int sum = 0, result = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i] == 0 ? -1 : 1;
            if (hash.count(sum)) 
                result = max(result, i - hash[sum]);
            else
                hash[sum] = i;
        }
        return result;
    }
};