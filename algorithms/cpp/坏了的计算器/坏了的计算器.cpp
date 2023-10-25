// Source : https://leetcode.cn/problems/broken-calculator/description/
// Author : Yanan Wang
// Date   : 2023-10-25

/**
 * X -> Y
 * 正向思维: 情况较复杂, 不容易实现
 * 反向思维: Y -> X (除法和加法)    
 *      当 X > Y 时, Y只能不断++, 才能==X, 所有次数增加Y-X次
 *      当 X <= Y 时, Y可以选择除法, 也可以选择加法
 *                      当Y是奇数时, Y只能选择加法, 不能选择除法, 因为本题无浮点数
 *                      当Y是偶数时, Y能选除法也能选加法, 但是只选除法是最优的
 *                          证明: 
 *                                如果Y要进行加法, 那么必须进行偶数次加法, 因为偶数
 *                              进行奇数次加法, 会变成奇数, 而奇数只能进行加法.
 *                                并且, 执行了加法后, 势必还会进行除法.
 *                                所以既进行加法也进行除法: Y -> (Y+k)/2, 一共进行了k+1次(k是偶数).
 *                                只进行除法:Y -> (Y+k)/2, 一共进行了(k/2)+1次.
 *                                即, 只进行除法比减法除法都进行更优.
 */

class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ans = 0;
        while (startValue < target) {
            if (target % 2 == 0) {
                target /= 2;
            } else {
                ++target;
            }
            ++ans;
        }
        return ans + startValue - target;
    }
};