// Source : https://leetcode.cn/problems/count-of-smaller-numbers-after-self/description/
// Author : Yanan Wang
// Date   : 2023-11-25

class Solution {
public:
    vector<int> ans;
    vector<int> idx;
    vector<int> idx_tmp;
    vector<int> num_tmp;
    void MergeSort(vector<int> &nums, int begin, int end) {
        if (begin >= end) {
            return;
        }
        int mid = begin + (end - begin) / 2;
        MergeSort(nums, begin, mid);
        MergeSort(nums, mid + 1, end);
        int i = begin;
        int cur1 = begin;
        int cur2 = mid + 1;
        while (cur1 <= mid && cur2 <= end) {
            if (nums[cur1] > nums[cur2]) {
                ans[idx[cur1]] += end - cur2 + 1;
                idx_tmp[i] = idx[cur1];
                num_tmp[i++] = nums[cur1++];
            } else {
                idx_tmp[i] = idx[cur2];
                num_tmp[i++] = nums[cur2++];
            }
        }
        while (cur1 <= mid) {
            idx_tmp[i] = idx[cur1];
            num_tmp[i++] = nums[cur1++];
        }
        while (cur2 <= end) {
            idx_tmp[i] = idx[cur2];
            num_tmp[i++] = nums[cur2++];
        }
        for (i = begin; i <= end; ++i) {
            idx[i] = idx_tmp[i];
            nums[i] = num_tmp[i];
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        ans.resize(n);
        idx.resize(n);
        idx_tmp.resize(n);
        num_tmp.resize(n);
        for (int i = 0; i < n; ++i) {
            idx[i] = i;
        }
        MergeSort(nums, 0, n - 1);
        return ans;
    }
};