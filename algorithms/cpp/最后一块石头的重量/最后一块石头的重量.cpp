// Source : https://leetcode.cn/problems/last-stone-weight/ 
// Author : Yanan Wang
// Date   : 2023-10-14

/**
 * 看到”每一回合，从中选出两块最终的石头“，就应该想到用优先级队列（堆）来解决。
 * 将所有元素放入堆中，然后当堆中的元素数量大于1时，就依次拿出两个top，然后计算差值
 *      若差值 == 0，开始下一次循环
 *      若差值 != 0，将差值push进堆
 *  直到堆中无元素或仅剩一个元素，返回答案即可。
 */

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap(stones.begin(), stones.end());
        while (heap.size() > 1) {
            int x = heap.top(); heap.pop();
            int y = heap.top(); heap.pop();
            int dif = x - y;
            if (dif != 0) {
                heap.push(dif);
            }
        }
        return heap.size() == 1 ? heap.top() : 0;
    }
};