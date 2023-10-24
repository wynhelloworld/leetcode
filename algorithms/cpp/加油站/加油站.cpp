// Source : https://leetcode.cn/problems/gas-station/description/
// Author : Yanan Wang
// Date   : 2023-10-24

/**
 * 本题, 先制作一个diff[] = gas - cost
 *      然后, 从i位置开始遍历, 加上diff, 若中间出现负值, 则从i位置到达不了
 *      这样的解法, 时间复杂度为O(N^2)
 * 贪心策略:
 *       * * * * * * * * *
 *       0 1 2 3 4 5 6 7 8 
 *       假设从0加到了5, 然后出现负值了, 上面的做法是从1开始重新加, 但这一步可以优化
 *       因为 diff[0] + ... + diff[5] < 0
 *       又因为 diff[0] >= 0
 *       所以 diff[1] + ... + diff[5] < 0
 *            diff[2] + ... + diff[5] < 0
 *             ...
 *       所以, 当从0加到5失败时, 就没必要重新从1开始加了, 直接从6开始遍历
 *       优化后的时间复杂度为O(2*N) ==> O(N)
 */

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int i = 0;
        while (i < n) {
            int sum = 0;
            int step = 0;
            while (step < n) {
                int j = (i + step) % n;
                sum += gas[j] - cost[j];
                if (sum < 0) {
                    break;
                }
                ++step;
            } 
            if (sum >= 0) {
                return i;
            } else {
                i += step + 1;                
            }
        }
        return -1;
    }
};