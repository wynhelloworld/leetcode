// Source : https://leetcode.cn/problems/top-k-frequent-words/ 
// Author : Yanan Wang
// Date   : 2023-10-14

/**
 * 看题目，就能知道，本题用优先级队列（堆）。
 * 开一个大小为k的堆，根据频率按小根堆存储
 *                 若频率相等，根据字典序按大根堆存储
 * 最后将堆中的元素放入vector中，返回即可
 */

class Solution {
public:
    using PSI = pair<string, int>;
    
    class Cmp {
    public:
        bool operator()(const PSI &lhs, const PSI &rhs) {
            if (lhs.second == rhs.second) {
                return lhs.first < rhs.first; // 大根堆
            }
            return lhs.second > rhs.second; // 小根堆
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string ,int> hash;
        for (auto &word : words) {
            ++hash[word];
        }

        priority_queue<PSI, vector<PSI>, Cmp> heap;
        for (auto &psi : hash) {
            heap.push(psi);
            if (heap.size() > k) {
                heap.pop();
            }
        }

        vector<string> ans(k);
        for (int i = k - 1; i >= 0; --i) {
            ans[i] = heap.top().first;
            heap.pop();
        }

        return ans;
    }
};