// Source : https://leetcode.cn/problems/3sum/description/
// Author : Yanan Wang
// Date   : 2023-07-29

/*
 * 本题目和《和为s的两个数字》很像，将本题先排序后，再固定一个数后，剩下的数要做的事情就和《和为s的两个数字》要做的事情一样了。
 * 所以本题目也采用双指针的方法，但本题真正的难点是去重。
 *         nums[-4, -4, -1, 0, 0, 0, 1, 1, 4, 4, 5, 6]
 *              ⬆          ⬆                 ⬆
 *              i          left              right 
 *      当left和right在遍历完上述位置时，下次遇到的0和4已经没有必要再遍历了，所以此时直接跃过相同的值。
 *      当i遍历完上述位置时，下次遇到的-4也没有必要再遍历了，所以此时直接跃过相同的值。
 **/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int n = nums.size();        
        for (int i = 0; i < n - 2; ++i) {
            if (nums[i] > 0) {
                return result;
            }
            if (i > 0 && nums[i - 1] == nums[i]) {
                continue;
            }
            int left = i + 1, right = n - 1;
            while (left < right) {
                if (nums[left] + nums[right] < -nums[i]) {
                    ++left;    
                } else if (nums[left] + nums[right] > -nums[i]) {
                    --right;
                } else {
                    result.push_back({nums[i], nums[left], nums[right]});
                    ++left;
                    --right;
                    while (left < right && nums[left] == nums[left - 1] && ++left);
                    while (left < right && nums[right] == nums[right + 1] && --right);
                }
            }
        }
        return result;
    }
};