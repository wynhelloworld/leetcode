// Source : https://leetcode.cn/problems/sort-an-array/description/
// Author : Yanan Wang
// Date   : 2023-08-23

/**
 * 本题解采用归并排序：
 * 归并排序与快速排序很像，只不过从递归的角度看，归并排序是后序遍历，而快速排序是前序遍历。
 */

class Solution {
public:
    vector<int> tmp;
    void mergeSort(vector<int> &nums, int left, int right) {
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        int i = left, cur1 = left, cur2 = mid + 1;
        while (cur1 <= mid && cur2 <= right)
            tmp[i++] = nums[cur1] < nums[cur2] ? nums[cur1++] : nums[cur2++];
        while (cur1 <= mid)
            tmp[i++] = nums[cur1++];
        while (cur2 <= right)
            tmp[i++] = nums[cur2++];
        for (int i = left; i <= right; ++i)
            nums[i] = tmp[i];
    }
    vector<int> sortArray(vector<int>& nums) {
        tmp.resize(nums.size());
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};