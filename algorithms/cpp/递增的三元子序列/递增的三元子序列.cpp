// Source : https://leetcode.cn/problems/increasing-triplet-subsequence/description/ 
// Author : Yanan Wang
// Date   : 2023-10-18

/**
 * 本题在《300. 最长递增子序列》贪心解法的基础上, 判断一下tails的大小是否等于3即可
 * 而且, 本题并没有必要进行二分查找, 因为只需判断两次即可, 本题时空复杂度为O(N)
 */

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> tails;
        tails.push_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > tails.back()) {
                tails.push_back(nums[i]);
            } else {
                int left = 0;
                int right = tails.size() - 1;
                while (left < right) {
                    int mid = left + (right - left) / 2;
                    if (tails[mid] < nums[i]) {
                        left = mid + 1;
                    } else {
                        right = mid;
                    }
                }
                tails[left] = nums[i];
            }
            if (tails.size() == 3) {
                return true;
            }
        }
        return false;
    }
};
