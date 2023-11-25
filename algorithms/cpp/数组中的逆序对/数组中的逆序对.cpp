// Source : https://leetcode.cn/problems/shu-zu-zhong-de-ni-xu-dui-lcof/description/
// Author : Yanan Wang
// Date   : 2023-11-25

class Solution {
public:
    vector<int> tmp;
    int MergeSort(vector<int> &record, int begin, int end) {
        if (begin >= end) {
            return 0;
        }
        int mid = begin + (end - begin) / 2;
        int ans = MergeSort(record, begin, mid) + MergeSort(record, mid + 1, end);
        int i = begin;
        int cur1 = begin;
        int cur2 = mid + 1;
        while (cur1 <= mid && cur2 <= end) {
            if (record[cur1] <= record[cur2]) {
                tmp[i++] = record[cur1++];
            } else {
                tmp[i++] = record[cur2++];
                ans += mid - cur1 + 1;
            }
        } 
        while (cur1 <= mid) {
            tmp[i++] = record[cur1++];
        }
        while (cur2 <= end) {
            tmp[i++] = record[cur2++];
        }
        for (i = begin; i <= end; ++i) {
            record[i] = tmp[i];
        }
        return ans;
    }
    int reversePairs(vector<int>& record) {
        tmp.resize(record.size());
        return MergeSort(record, 0, record.size() - 1);
    }
};