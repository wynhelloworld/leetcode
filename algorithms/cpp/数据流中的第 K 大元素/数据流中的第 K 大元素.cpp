// Source : https://leetcode.cn/problems/kth-largest-element-in-a-stream/ 
// Author : Yanan Wang
// Date   : 2023-10-14

/**
 * 看题目就能想到是TOP-K问题。
 * 题目要找第K大元素，那么维护一个大小为K的大根堆即可。
 *      构造函数 -- 将nums中的所有元素push进堆中，一边push，一边检测堆的大小，若大小大于K就pop
 *      add函数 -- 将元素push进堆中，然后检测堆的大小，若大小大于K就pop，最后返回top
 */

class KthLargest {
private:
    int k_;
    priority_queue<int, vector<int>, greater<int>> heap_;
public:
    KthLargest(int k, vector<int>& nums) { 
        k_ = k;  
        for (auto &num : nums) {
            heap_.push(num);
            if (heap_.size() > k) {
                heap_.pop();
            }
        }
    }
    
    int add(int val) {
        heap_.push(val);
        if (heap_.size() > k_) {
            heap_.pop();
        }
        return heap_.top();
    }

};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */