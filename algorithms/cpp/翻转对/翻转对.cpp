// Source : https://leetcode.cn/problems/reverse-pairs/
// Author : Yanan Wang
// Date   : 2023-11-25

class Solution {
public:
    vector<int> tmp;
    int MergeSort(vector<int> &nums, int begin, int end) {
        if (begin >= end) {
            return 0;
        }
        int mid = begin + (end - begin) / 2;
        int ans = MergeSort(nums, begin, mid) + MergeSort(nums, mid + 1, end);
        int cur1 = begin;
        int cur2 = mid + 1;
        while (cur1 <= mid && cur2 <= end) {
            if (nums[cur1] > 2.0 * nums[cur2]) {
                ans += mid - cur1 + 1;
                ++cur2;
            } else {
                ++cur1;
            }
        }
        int i = begin;
        cur1 = begin;
        cur2 = mid + 1;
        while (cur1 <= mid && cur2 <= end) {
            if (nums[cur1] < nums[cur2]) {
                tmp[i++] = nums[cur1++];
            } else {
                tmp[i++] = nums[cur2++];
            }
        }
        while (cur1 <= mid) {
            tmp[i++] = nums[cur1++];
        }
        while (cur2 <= end) {
            tmp[i++] = nums[cur2++];
        }
        for (i = begin; i <= end; ++i) {
            nums[i] = tmp[i];
        }
        return ans;
    }
    int reversePairs(vector<int>& nums) {
        tmp.resize(nums.size());
        return MergeSort(nums, 0, nums.size() - 1);
    }
};