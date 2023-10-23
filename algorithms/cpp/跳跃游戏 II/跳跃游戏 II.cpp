// Source : https://leetcode.cn/problems/jump-game-ii/description/
// Author : Yanan Wang
// Date   : 2023-10-23

/**
 * 本题的贪心策略, 运用了层序遍历的思路:
 *      用left和right来确定, 本次的跳跃区间
 *      用max_pos来确定, 最大的跳跃位置
 */

class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0;
        int max_pos = 0;
        int left = 0, right = 0;
        while (left <= right) {
            if (max_pos >= nums.size() - 1) {
                return ans;
            }
            for (int i = left; i <= right; ++i) {
                max_pos = max(max_pos, i + nums[i]);
            }
            left = right + 1;
            right = max_pos;
            ++ans;
        }
        return -1;
    }
};