// Source : https://leetcode.cn/problems/greatest-sum-divisible-by-three/description/
// Author : Yanan Wang
// Date   : 2023-10-27

/**
 * 本题, 可以全部先将数加起来
 * 若 sum % 3 == 0, 则直接返回
 * 若 sum % 3 == 1, 则要么删除一个%3==1的最小的数, 要么删除2个%3==2的最小的数 (选二者较小值)
 * 若 sum % 3 == 2, 则要么删除一个%3==2的最小的数, 要么删除2个%3==1的最小的数 (选二者较小值)
 *    如何求得最小值和次小值?
 *      1、排序
 *      2、在遍历的同时, 用两个变量记录最小值和次小值
 *              若 x < 最小值:
 *                  次小值 = 最小值
 *                  最小值 = x
 *              若 最小值 <= x < 次小值:
 *                  次小值 = x
 */

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        const int INF = 0x3f3f3f3f;
        int sum = 0;
        int x1 = INF, x2 = INF;// 分别记录%3==1的最小值和次小值
        int y1 = INF, y2 = INF;// 分别记录%3==2的最小值和次小值
        for (auto &x : nums) {
            sum += x;
            if (x % 3 == 1) {
                if (x < x1) {
                    x2 = x1;
                    x1 = x;
                } else if (x < x2){
                    x2 = x;
                }
            } else if (x % 3 == 2) {
                if (x < y1) {
                    y2 = y1;
                    y1 = x;
                } else if (x < y2){
                    y2 = x;
                }
            }
        }
        if (sum % 3 == 1) {
            sum -= min(x1, y1 + y2);
        } else if (sum % 3 == 2) {
            sum -= min(x1 + x2, y1);
        }
        return sum;
    }
};