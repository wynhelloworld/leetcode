// Source : https://leetcode.cn/problems/two-sum/description/ 
// Author : Yanan Wang
// Date   : 2023-10-07

/**
 * 本题的暴力解法就是正向的双重for循环
 *        for (int i = 0; ...) 
 *           for (int j = i + 1; ...)
 *                  ...
 * 但本题还可以用反向的双重for循环
 *        for (int i = 0; ...)
 *           for (int j = i - 1; ...)
 *                  ...
 * 在反向的双重for循环的基础上，还能加上哈希表进行优化，使时间复杂度由O(N^2) -> O(N)
 *      由于反向双for的第二个for就是在找target-nums[i]，而我们可以在遍历的时候就把前面的元素全都放入hash
 *      然后就不需要第二层for了，直接一层for就行，每次遍历时去hash找target-nums[i]就行          
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); ++i) {
            if (hash.count(target - nums[i])) {
                return {hash[target - nums[i]], i};
            }
            hash[nums[i]] = i;
        }      
        return {};
    }
};  