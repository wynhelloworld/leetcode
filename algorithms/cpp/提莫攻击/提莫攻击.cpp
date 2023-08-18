// Source : https://leetcode.cn/problems/teemo-attacking/description/
// Author : Yanan Wang
// Date   : 2023-08-18

/**
 * 可以发现规律：
 *    diff = timeSeries[i + 1] - timeSeries[i];
 *    当 diff >= duration 时，diff时间内duration中毒时间会全部算上
 *    当 diff < duration 时，由于会刷新中毒事件，所以diff时间内只会中毒diff时间。
 */

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans = 0;
        for (int i = 0; i < timeSeries.size() - 1; ++i) {
            int diff = timeSeries[i + 1] - timeSeries[i];
            if (diff >= duration) 
                ans += duration;
            else 
                ans += diff;
        }
        return ans + duration;
    }
};