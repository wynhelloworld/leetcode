// Source : https://leetcode.cn/problems/zui-xiao-de-kge-shu-lcof/description/
// Author : Yanan Wang
// Date   : 2023-11-25

class Solution {
public:
    void QuickSelect(vector<int> &stock, int begin, int end, int cnt) {
        if (begin >= end) {
            return;
        }
        int key = stock[begin + (rand() % (end - begin + 1))];
        int i = begin;
        int left = begin - 1;
        int right = end + 1;
        while (i < right) {
            if (stock[i] < key) {
                swap(stock[++left], stock[i++]);
            } else if (stock[i] == key) {
                ++i;
            } else {
                swap(stock[i], stock[--right]);
            }
        }
        int left_nums = left - begin + 1;
        int mid_nums = right - left - 1;
        if (left_nums > cnt) {
            QuickSelect(stock, begin, left, cnt);
        } else if (left_nums + mid_nums >= cnt) {
            return;
        } else {
            QuickSelect(stock, right, end, cnt - left_nums - mid_nums);
        }
    }
    vector<int> inventoryManagement(vector<int>& stock, int cnt) {
        srand(time(nullptr));
        QuickSelect(stock, 0, stock.size() - 1, cnt);
        return {stock.begin(), stock.begin() + cnt};
    }
};