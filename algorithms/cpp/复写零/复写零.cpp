// Source : https://leetcode.cn/problems/duplicate-zeros/description/
// Author : Yanan Wang
// Date   : 2023-07-24

/**
 * 本题采用双指针解法，先“异地模拟”，后“本地操作”。
 *    异地模拟：
 *            用一个临时数组temp，指针cur指向arr的开始，指针dest指向temp的开始，然后进行模拟。
 *            然后根据题意, 当cur指向0时, dest连续走两步并且写0
 *                        当cur指向非0时, dest走一步，并且写上arr[cur] 
 *                 cur                                                          cur 
 *                  ⬇                                                           ⬇
 *             arr [1, 0, 2, 3, 0, 4, 5, 0]       -->        arr [1, 0, 2, 3, 0, 4, 5, 0]
 *            temp [ ,  ,  ,  ,  ,  ,  ,  ]       -->       temp [1, 0, 0, 2, 3, 0, 0, 4]               
 *                  ⬆                                                                 ⬆
 *                 dest                                                               dest
 *
 *    本地操作：
 *            用上面的思想在arr上同时进行两步操作，可以发现行不通，因为temp的重写会覆盖掉后面的值。
 *            所以就想到了从后往前同时进行上面的操作，可从后往前的话，cur和dest的起始位置就要跟上面的最终位置一样，
 *            可问题是无法确定cur的位置，所以此时继续采用双指针法确定cur的位置。
 *                 cur初始化为0，dest初始化为-1，都指向arr，
 *                 在cur遍历过程中，如果cur指向0，dest连续走两步
 *                                如果cur指向非0，dest走一步
 *                 但dest可能走到界外，所以此时特殊处理，arr[n-1]=0; --cur; dest-=2;
 *            此时的cur和dest就是从后往前遍历的起始位置。
 */

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int cur = 0, dest = -1, n = arr.size();
        while (cur < n) {
            if (arr[cur]) ++dest;
            else dest += 2;
            if (dest >= n - 1) break;
            ++cur;
        }
        if (dest == n) {
            arr[n - 1] = 0;
            --cur;
            dest -= 2;  
        }
        while (cur >= 0) {
            if (arr[cur]) {
                arr[dest--] = arr[cur--];
            } else {
                arr[dest--] = 0;
                arr[dest--] = 0;
                --cur;
            }  
        }
    }
};