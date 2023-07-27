// Source : https://leetcode.cn/problems/valid-triangle-number/description/
// Author : Yanan Wang
// Date   : 2023-07-27

/**
 * 判断是否能组成三角形的常规方法：任意两边之和大于第三边。这也就意味着比大小这件事情要重复三次。
 *                   特殊方法：当三条边已经有序时：a <= b <= c，此时只需判断a + b > c是否成立即可。
 *                                                        因为c已经是最大的了，那么c+a一定大于b，c+b一定大于a。
 * 所以本题的第一步，先将nums进行排序。
 * 排好序后，先固定最大值，然后left和right分别指向最小值和次最大值。
 *        nums[2, 2, 3, 4, 5, 9, 10]
 *             ⬆             ⬆  ⬆
 *            left         right  max
 *        当left + right > max时，这三个数能够组成三角形，同时left右边的数和right以及max也能够组成三角形。
 *                               此时的三元组个数为right-left个，然后--right。
 *        当left + right <= max时，这三个数不能够组成三角形，此时最小的left向右移动，找到left + right > max直至left == right。
 *        上面只是固定了max，然后循环--max，即能够计算出总的三元组个数。
 */

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int result = 0;
        for (int max = nums.size() - 1; max >= 2; --max) {
            int left = 0, right = max - 1;
            while (left < right) {
                if (nums[left] + nums[right] > nums[max]) {
                    result += right - left;
                    --right;
                } else {
                    ++left;
                }
            }
        }
        return result;
    }
};