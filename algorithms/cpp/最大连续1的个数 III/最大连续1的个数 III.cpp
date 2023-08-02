// Source : https://leetcode.cn/problems/max-consecutive-ones-iii/description/
// Author : Yanan Wang
// Date   : 2023-08-02

/**
 *                   right
 *                    ⬇
 *               nums[1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0]
 *                    ⬆
 *                   left
 * 本题的暴力解法：
 *      当left从开始位置固定，right从left开始一直向右遍历，同时检测是否出现0了，若出现了，记录下0的个数，当个数超过k时，记录下长度，然后重新开始遍历。
 *      然后left向右移动一步，right重新从left开始向右遍历重复上面的操作。
 *      但是这个暴力解法做了很多无用的遍历。
 * 优化：
 *      1、当个数超过k重新遍历时，left向右移动时，盲目的只移动一步可能是无意义的，看下面例子：
 *                                  right         k = 2
 *                                   ⬇
 *               nums[1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0]
 *                    ⬆
 *                   left
 *          此时，right指向第3个0，3 > 2
 *          若left向右移动一步，right重新从left开始遍历时，最终left还会在相同位置停下来，并且长度还比之前短了。
 *          所以left应移动到0的个数<=3处的位置，也就是下标为4的地方。
 *       2、当left更新时，right无需重新从left处开始遍历，直接从原位置处开始遍历即可，因为此时right和left直接是统计了0的个数并且<=k的
 * 暴力解法经过上面两步优化后，就成了滑动窗口。   
 */

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeros = 0, len = 0, n = nums.size();
        for (int left = 0, right = 0; right < n; ++right) {
            if (0 == nums[right]) ++zeros;
            while (zeros > k && 0 == nums[left++]) --zeros;
            len = max(len, right - left + 1);
        }
        return len;
    }
};