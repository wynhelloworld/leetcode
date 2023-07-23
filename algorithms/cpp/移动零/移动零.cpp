// Source : https://leetcode.cn/problems/move-zeroes/
// Author : Yanan Wang
// Date   : 2023-07-23

/**
 * 本题采用双指针解法，用dest和cur指针把nums划分为三个区域：
 *   ---------------------------------------------------------
 *     no-zeros |        zeros        |       not deal     
 *   -----------|---------------------|-----------------------                             
 *    [0, dest] | [dest + 1, cur - 1] | [cur, nums.size() - 1]
 *   ---------------------------------------------------------
 *   descripton:
 *      dest指向已处理区间内的最后一个非零元素  
 *      cur指向未处理区间的第一个元素
 *   principle:
 *      只要cur在遍历nums的整个过程中都始终维持以上区间的状态，那么最后cur==nums.size()时，
 *      [0, dest]区间就全是非零元素，[dest + 1, nums.size() - 1]区间就全是零元素。
 *   method:
 *      根据以上描述，只需要cur在遍历过程中，遇到非零元素与nums[++dest]交换即可。
 */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int dest = -1, cur = 0; cur < nums.size(); ++cur) 
            if (nums[cur]) swap(nums[++dest], nums[cur]);
    }
};