// Source : https://leetcode.cn/problems/advantage-shuffle/description/ 
// Author : Yanan Wang
// Date   : 2023-10-20

/**
 * 本题用田忌赛马的思想:
 *      1、将nums1和nums2都升序排序.
 *      2、依次拿nums1和nums2中的元素进行比较
 *              若nums1头部 > nums2头部, 即为优势
 *              反之, 就拿nums1头部, 去消耗nums2尾部
 *  但是这样得出的结果, 是跟排序后的nums2一一对应的, 而不是跟排序前的nums2一一对应,
 *  所以, 不能对nums2进行排序, 而是对nums2的下标进行排序, nums1通过排序后的下标间接与nums2进行比较
 */

class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());

        int n = nums1.size();
        vector<int> index(n);
        iota(index.begin(), index.end(), 0);
        sort(index.begin(), index.end(), [&](int lhs, int rhs){
            return nums2[lhs] < nums2[rhs];
        });     
        
        vector<int> ans(n);
        int left = 0, right = n - 1;
        for (auto &x : nums1) {
            if (x > nums2[index[left]]) {
                ans[index[left++]] = x;
            } else {
                ans[index[right--]] = x;
            }
        }
        return ans;
    }
};