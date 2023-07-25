// Source : https://leetcode.cn/problems/happy-number/description/
// Author : Yanan Wang
// Date   : 2023-07-25

/**
 * 模拟n=2:
 *           2 -> 4 -> 16 -> 37 -> 58 
 *                ⬆                ⬇ 
 *               20 <- 42 <- 145 <- 89
 * 模拟n=19:
 *          19 -> 82 -> 68 -> 100 -> 1 -> 1
 *                                   ⬆   ⬇      实际上，也可以把快乐数最终的结局1看作是一个环。 
 *                                   1 <- 1
 * 上面这两种模型酷似:
 *                    ---------------------
 *                                  |     |
 *                                  -------
 *                    像这种模型，一般采用双指针解法，只需判断碰撞位置是否为1即可。
 */

class Solution {
public:
    int SumOfSquares(int n) {
        int sum = 0;
        while (n) {
            sum += pow(n % 10, 2);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n, fast = n;
        do {
            slow = SumOfSquares(slow);
            fast = SumOfSquares(SumOfSquares(fast));
        } while (slow != fast);
        return slow == 1;
    }
};