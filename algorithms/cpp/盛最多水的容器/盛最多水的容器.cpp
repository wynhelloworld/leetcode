// Source : https://leetcode.cn/problems/container-with-most-water/description/
// Author : Yanan Wang
// Date   : 2023-07-26

/**
 * 先随便选择两条线，计算一下容积
 *      
 *     height[1, 8, 6, 2, 5, 4, 8, 3, 7]
 *                  ⬆       ⬆ 
 *                 left     right
 *     上面的容积为V = (right - left) * min(height[right], height[left]);
 *     然而，当较大高度的left向右移动时，只会出现两种情况，而这两种情况的结果都是导致容积V变小：
 *                                       1、width减小，height不变；
 *                                       2、width减小，height减小；
 *     所以，当left和right确定于某一位置时，此时的V最大，当较大高度的一方向中间移动时，V必定变小。
 *     那么，如果把left和right分别放置于height的两端，较低高度的向中间移动，每次移动过程中都能算出一个V，而题的答案就是其中最大的V。
 */

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int v = 0;
        while (left < right) {
            v = max(v, (right - left) * min(height[left], height[right]));
            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }
        return v;
    }
};