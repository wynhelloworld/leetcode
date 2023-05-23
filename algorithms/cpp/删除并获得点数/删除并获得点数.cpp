// Source : https://leetcode.cn/problems/delete-and-earn/
// Author : Yanan Wang
// Date   : 2023-05-22

/**
 * 把这道题的很多个例子，升序排序一下，可以发现和打家劫舍I很像
 *  eg：
 *      [2, 2, 3, 3, 3, 4] 如果选中2，那么就不可以选3了，继续选4，结果为8
 *                         如果选中3，那么就不可以选2、4了，结果为9
 *                         如果选中4，那么就不可以选3了，继续选2，结果为8   --》最终结果为9
 *      就是，当选中x的时候，就把x-1和x+1从nums中去掉，然后重新选x。
 *      就有点像，打家劫舍I中的不能偷最近的邻居，但能偷邻居的邻居...
 * 那么，就可以尽量把这道题往打家劫舍I上靠
 *      但是，这个题（升序后）和打家劫舍I的不同点是，相邻元素不是完美递增（+1递增）
 *  eg：
 *      [1, 1, 2, 2, 4, 4, 5, 8, 8, 8] 如果选中4，这里是可以继续选2的（打家劫舍I里是不能选的）
 *
 * 这时可以开辟一个新的数组arr, nums里的每一个数都对应arr的下标，arr[i]表示nums里所有值为i的总和
 *  eg：
 *      将上一个例子配合到arr中
 *   arr  [0, 2, 4, 0, 8, 5, 0, 0, 24]
 *   index 0, 1, 2, 3, 4, 5, 6, 7, 8     
 * 这时就可以对arr进行打家劫舍I
 */

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001;
        vector<int> arr(n);
        for (auto &e : nums) 
            arr[e] += e;
        vector<int> f(n);
        vector<int> g(n);
        f[0] = arr[0];
        for (int i = 1; i < n; ++i) 
        {
            f[i] = g[i - 1] + arr[i];
            g[i] = max(f[i - 1], g[i - 1]);
        }
        return max(f[n - 1], g[n - 1]);
    }
};

