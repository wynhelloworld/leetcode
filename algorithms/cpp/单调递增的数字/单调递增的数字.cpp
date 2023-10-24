// Source : https://leetcode.cn/problems/monotone-increasing-digits/description/
// Author : Yanan Wang
// Date   : 2023-10-24

/**
 * 暴力解法:
 *      从n开始--遍历, 每次检测数字是否单调递增
 * 贪心解法:
 *      n的递增高位不能修改, 要修改的只能是第一次发生递减的高位(这样才能够保证返回的是<=n的最大数字)
 *          eg: 123454367 
 *                   i
 *              这里, i位置第一次发生递减, 但不能增大i, 这样会使结果>n, 
 *              正确做法是将i的前一位减小1, 然后将i及之后的位置填9, 变成123449999
 *              但会有一个细节问题: 可能i-1位置上的值减1之后, 使得i-1位置也发生了递减
 *                  eg: 123554367 
 *                           i
 *                       变成123549999, 这样也是有问题的, 所以这里采用递归思想
 *                       处理完i-1位置的减1后, 将i-1, 重新看i位置是否发生了递减       
 *              
 */

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string str = to_string(n);
        int i = 1;
        while (i < str.size() && str[i - 1] <= str[i]) {
            ++i;
        } 
        if (i < str.size()) {
            while (i > 0 && str[i - 1] > str[i]) {
                --str[i - 1];
                --i;
            }
            while (++i < str.size()) {
                str[i] = '9';
            }
        }
        return stoi(str);
    }
};