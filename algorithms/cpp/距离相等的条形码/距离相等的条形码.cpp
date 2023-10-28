// Source : https://leetcode.cn/problems/distant-barcodes/description/
// Author : Yanan Wang
// Date   : 2023-10-28

/**
 * 1、先统计出出现次数最多的数val和次数cnt,
 * 2、然后将val按照cnt, 往ans里隔一个放一个, 
 * 3、放完val之后, 其它数继续从后面, 隔一个放一个, 
 * 4、后面放完后, 剩余的空位, 随便放数字就行.
 * 证明:
 *      因为本题一定有解, 所以根据鸽巢原理, 得出cnt <= (n+1)/2
 *      假设 cnt == (n+1)/2
 *          那么, ans里肯定每隔一个位, 就有一个位被填, 次数, 剩余的数随便往ans里填都行.
 *      假设 cnt < (n+1)/2
 *          那么, 此时val被填完了, 用其它数往ans里继续向后填充, 也一定不会相邻,
 *          因为, 如果用y从后继续填充, 并且转一圈后又相邻了, 那么出现次数最多的就不是val而是y了.
 */ 

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int max_cnt = 0;// 出现值最多的次数
        int max_val = 0;// 出现次数最多的值
        unordered_map<int, int> hash;
        for (auto &x : barcodes) {
            ++hash[x];
            if (max_cnt < hash[x]) {
                max_cnt = hash[x];
                max_val = x;
            }
        }
        hash.erase(max_val);

        int n = barcodes.size();
        vector<int> ans(n);
        int i = 0;
        while (max_cnt--) {
            ans[i] = max_val;
            i += 2;
        }
        for (auto &[k, v] : hash) {
            while (v--) {
                if (i >= n) {
                    i = 1;
                }
                ans[i] = k;
                i += 2;
            }
        }
        return ans;
    }
};