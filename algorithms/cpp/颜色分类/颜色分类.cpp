// Source : https://leetcode.cn/problems/sort-colors/description/
// Author : Yanan Wang
// Date   : 2023-11-15

// 用 三个指针, 将nums划分为四个区域, 在遍历的过程当中, 始终维护这四个区域的性质
//      [0, left] -> 0
//      (left, i) -> 1
//      [i, right) -> 未探索
//      [right, n) -> 2
//  ---------------------------
//  ⬆    ⬆       ⬆         ⬆
//  0   left     right      n-1

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int left = -1;
        int right = n; 
        while (i < right) {
            if (nums[i] == 0) {
                swap(nums[++left], nums[i++]);
            } else if (nums[i] == 1) {
                ++i;
            } else {
                swap(nums[i], nums[--right]);
            }
        }
    }
};