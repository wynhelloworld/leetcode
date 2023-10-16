// Source : https://leetcode.cn/problems/minimum-operations-to-halve-array-sum/description/
// Author : Yanan Wang
// Date   : 2023-10-16

/**
 * 贪心解法：每次从nums中选一个max进行减半，直到减了至少一半的sum。
 * 证明：
 *      交换论证法：只要能将最优解在不破坏“最优性质”的前提下，转换成贪心解，那么贪心解就是最优解。
 *          贪心解：* * * * * * （减了6次）
 *          最优解：* * * * * * （减了6次）
 *        当某一次选择num时，会出现两种情况：
 *              最优解 == 贪心解 （没什么好说的）
 *              最优解 < 贪心解（因为最优解就是选max，而贪心解!=最优解，那么贪心解<max，贪心解<最优解）
 *                     1、假设单次最优解选的num(<max)可以达到目的，那么最优解本次选max也可以达到目的（减半数值更大了）；
 *                     2、假设最优解前后两次选的是x、y可以达到目的，那么最优解前后两次选y、x也可以达到目的（减半数值、次数都没变）。
 */

class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> heap(nums.begin(), nums.end());
        double sum = 0;
        for (auto &x : nums) {
            sum += x;
        }
        double half = sum / 2;

        int ans = 0;
        while (sum > half) {
            double max_half = heap.top() / 2;
            heap.pop();
            sum -= max_half;
            heap.push(max_half);
            ++ans;
        }
        return ans;
    }
};