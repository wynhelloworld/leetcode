// Source : https://leetcode.cn/problems/sort-an-array/description/
// Author : Yanan Wang
// Date   : 2023-08-23

/**
 * 方法一：快速排序
 * Leetcode 更新之后会超时，原因是引入了新的测试用例“元素全都相等”
 * 当元素全都相等时，快速排序的时间复杂度会变为O(N^2) 
*/
class Solution {
public:
    int Partition(vector<int> &nums, int left, int right) {
        int key = left;
        while (left < right) {
            while (left < right && nums[right] >= nums[key] && --right);
            while (left < right && nums[left] <= nums[key] && ++left);
            if (left < right) {
                swap(nums[left], nums[right]);
            }
        }
        swap(nums[key], nums[left]);
        return left;
    }
    void QuickSort(vector<int> &nums, int left, int right) {
        if (left >= right) {
            return;
        }
        int key = Partition(nums, left, right);
        QuickSort(nums, left, key - 1);
        QuickSort(nums, key + 1, right);
    }
    vector<int> sortArray(vector<int>& nums) {
        QuickSort(nums, 0, nums.size() - 1);
        return nums;            
    }
};

/**
 * 方法二：快速选择
 * 解决了当测试用例元素全都相等时，快速排序的时间复杂度为O(N^2)的问题
 * 此时快速选择的时间复杂度为O(N)
*/
class Solution {
public:
    void QuickSelect(vector<int> &nums, int begin, int end) {
        if (begin >= end) {
            return;
        }
        // 等概率随机法选key
        int key = nums[begin + rand() % (end - begin + 1)];
        int i = begin;
        int left = begin - 1;
        int right = end + 1;
        while (i < right) {
            if (nums[i] < key) {
                swap(nums[++left], nums[i++]);
            } else if (nums[i] == key) {
                ++i;
            } else {
                swap(nums[i], nums[--right]);
            }
        }
        QuickSelect(nums, begin, left);
        QuickSelect(nums, right, end);
    }
    vector<int> sortArray(vector<int>& nums) {
        srand(time(nullptr));
        QuickSelect(nums, 0, nums.size() - 1);
        return nums;            
    }
};

/**
 * 方法三：归并排序
*/
class Solution {
public:
    vector<int> tmp;
    void MergeSort(vector<int> &nums, int left, int right) {
        if (left >= right) {
            return;
        }
        int mid = left + (right - left) / 2;
        MergeSort(nums, left, mid);
        MergeSort(nums, mid + 1, right);
        int i = left;
        int cur1 = left;
        int cur2 = mid + 1;
        while (cur1 <= mid && cur2 <= right) {
            tmp[i++] = nums[cur1] < nums[cur2] ? nums[cur1++] : nums[cur2++]; 
        }
        while (cur1 <= mid) {
            tmp[i++] = nums[cur1++];
        }
        while (cur2 <= right) {
            tmp[i++] = nums[cur2++];
        }
        for (i = left; i <= right; ++i) {
            nums[i] = tmp[i];
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        tmp.resize(nums.size());
        MergeSort(nums, 0, nums.size() - 1);
        return nums;            
    }
};