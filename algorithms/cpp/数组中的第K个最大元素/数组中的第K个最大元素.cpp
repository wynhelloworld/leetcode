// Source : https://leetcode.cn/problems/kth-largest-element-in-an-array/description/
// Author : Yanan Wang
// Date   : 2023-11-25

class Solution {
public:
    int QuickSelect(vector<int> &nums, int begin, int end, int k) {
        if (begin == end) {
            return nums[begin];
        }
        int key = nums[begin + (rand() % (end - begin + 1))];
        int i = begin;
        int left = begin - 1;
        int right = end + 1;
        while (i < right) {
            if (nums[i] > key) {
                swap(nums[++left], nums[i++]);
            } else if (nums[i] == key) {
                ++i;
            } else {
                swap(nums[i], nums[--right]);
            }
        }
        int left_nums = left - begin + 1;
        int mid_nums = right - left - 1;
        if (left_nums >= k) {
            return QuickSelect(nums, begin, left, k);
        } else if (left_nums + mid_nums >= k) {
            return key;
        } else {
            return QuickSelect(nums, right, end, k - left_nums - mid_nums);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(nullptr));
        return QuickSelect(nums, 0, nums.size() - 1, k);
    }
};