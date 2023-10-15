// Source : https://leetcode.cn/problems/lemonade-change/description/
// Author : Yanan Wang
// Date   : 2023-10-15

/**
 * 贪心策略：
 *      由于找零钱只找5、10，所以用five和ten分别记录下已有的张数
 *      收钱过程中：
 *          若收到5：直接收下，five+1
 *          若收到10：看下five是否 > 0
 *                          若 > 0，就收下，ten+1，five-1
 *                          若 == 0，就返回 flase
 *          若收到20：先看下ten和five是否同时 > 0 
 *                          若 > 0，就收下，ten-1，five-1
 *                          若 !> 0，就再看下five是否 >= 3
 *                                  若 >= 3，就five-3
 *                                  否则，就返回false
 *      当收到20时，先看ten和five是否同时 > 0，再看five是否 >= 3，就是本题的贪心策略
 *  策略证明：
 *      交换论证法：
 *          假设贪心解是：a b c d e f
 *          假设最优解是：d b c a e f    （正确解）
 *          能在不破坏最优解的“最优性质”下将最优解调整成贪心解
 *      当收到5时，贪心解和最优解都是直接收下
 *      当收到10时，贪心解和最优解都是有five就找，无five就返回false
 *      当收到20时，贪心解是：先找一个ten和一个five，若找不起，再找3个five，若再找不起，就返回false
 *                若此时最优解跟贪心解一样，那就没什么好说的
 *                若此时最优解是先找3个five，若找不起，再找一个ten和一个five，若再找不起，就返回false
 *                     如果先将3个five中的2个five换成1个ten，将后面的1个ten换成2个five，那么就变成贪心解了，
 *                     并且，贪心解是正确的，所以，此时贪心解 == 最优解。
 */

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        for (const auto &bill : bills) {
            if (bill == 5) {
                ++five;
            } else if (bill == 10) {
                if (five > 0) {
                    --five;
                    ++ten;
                } else {
                    return false;   
                }
            } else {
                if (five > 0 && ten > 0) {
                    --five;
                    --ten;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};